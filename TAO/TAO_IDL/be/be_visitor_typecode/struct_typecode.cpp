// -*- C++ -*-

//=============================================================================
/**
 *  @file  struct_typecode.cpp
 *
 *  Structure TypeCode generation visitor.
 *
 *  @author  Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#include "typecode.h"

TAO::be_visitor_struct_typecode::be_visitor_struct_typecode (
  be_visitor_context * ctx)
  : be_visitor_typecode_defn (ctx)
  , is_recursive_ (false)
  , is_nested_ (false)
{
}

int
TAO::be_visitor_struct_typecode::visit_structure (be_structure * node)
{
  if (!node->is_defined ())
    {
      return this->gen_forward_declared_typecode (node);
    }

  // Check if we are repeated.
  be_visitor_typecode_defn::QNode const * const qnode =
    this->queue_lookup (this->tc_queue_, node);

  ACE_Unbounded_Queue<AST_Type *> recursion_queue;
  bool in_recursion = node->in_recursion (recursion_queue);
  if (qnode && in_recursion)
    {
      // we're repeated and we're recursive so just leave
      return 0;
    }
  else if (this->queue_insert (this->tc_queue_, node, 0) == nullptr)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_struct_typecode::"
                         "visit_type - "
                         "queue insert failed\n"),
                        -1);
    }

  if (this->recursion_detect_ || this->is_nested_)
    {
      return 0;
    }

  // as this was no nested visit mark this typecode as recursive
  this->is_recursive_ = in_recursion;

  static bool const is_exception = false;
  return this->visit (node, is_exception);
}

int
TAO::be_visitor_struct_typecode::visit_exception (be_exception * node)
{
  if (this->recursion_detect_)
    {
      return 0;
    }

  // No need to check for recursion since exceptions are never
  // recursive.
  static bool const is_exception = true;
  return this->visit (node, is_exception);
}

int
TAO::be_visitor_struct_typecode::visit (AST_Structure * node,
                                        bool is_exception)
{
  this->is_nested_ = true;
  TAO_OutStream & os = *this->ctx_->stream ();

  TAO_INSERT_COMMENT (&os);

  if (this->gen_member_typecodes (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "TAO::be_visitor_struct_typecode::visit_structure -"
                         " Unable to generate structure/exception field "
                         "TypeCodes.\n"),
                        -1);
    }

  ACE_CString const tao_fields ("_tao_fields_");
  ACE_CString const fields_name (tao_fields
                                 + node->flat_name ());

  // Generate array containing struct field characteristics.
  os << "static TAO::TypeCode::Struct_Field<" << be_idt_nl
     << "char const *," << be_nl
     << "::CORBA::TypeCode_ptr const *> const ";

  if (node->nfields () == 0)
    {
      // Should only be possible for user exceptions with no fields.
      os << "* const " << be_idt_nl
         << fields_name.c_str () << " = 0;" << be_uidt_nl << be_uidt_nl;
    }
  else
    {
      os << be_idt_nl
         << fields_name.c_str () << "[] =" << be_idt_nl
         << "{" << be_idt_nl;

      if (this->visit_members (node) != 0)
        {
          return -1;
        }

      os << be_uidt_nl
         << "};" << be_uidt << be_uidt_nl << be_uidt_nl;
    }

  static char const StringType[]      = "char const *";
  static char const TypeCodeType[]    = "::CORBA::TypeCode_ptr const *";
  static char const MemberArrayType[] = "TAO::TypeCode::Struct_Field";

  // Generate the TypeCode instantiation.
  os << "static ";

  if (this->is_recursive_)
    {
      os << "TAO::TypeCode::Recursive_Type<" << be_idt_nl;
    }

  // -- TypeCodeBase --
  os << "TAO::TypeCode::Struct<" << be_idt_nl
     << StringType << "," << be_nl
     << TypeCodeType << "," << be_nl
     << MemberArrayType << "<" << be_idt_nl
     << StringType << "," << be_nl
     << TypeCodeType << "> const *," << be_uidt_nl
     << "TAO::Null_RefCount_Policy>";

  if (this->is_recursive_)
    {
      os << "," << be_uidt_nl
         << TypeCodeType << "," << be_nl
         << MemberArrayType << "<" << be_idt_nl
         << StringType << "," << be_nl
         << TypeCodeType << "> const *>" << be_uidt;
    }

  os << be_uidt_nl
     << "_tao_tc_" << node->flat_name () << " (" << be_idt_nl
     << "::CORBA::tk_" << (is_exception ? "except" : "struct") << ","
     << be_nl
     << "\"" << node->repoID () << "\"," << be_nl
     << "\"" << node->original_local_name () << "\"," << be_nl
     << "_tao_fields_" << node->flat_name () << "," << be_nl
     << node->nfields () << ");"
     << be_uidt_nl << be_nl;

  if (this->gen_typecode_ptr (dynamic_cast<be_type*> (node)) != 0)
    {
      return -1;
    }

  return 0;
}

int
TAO::be_visitor_struct_typecode::gen_member_typecodes (AST_Structure * node)
{
  AST_Field ** member_ptr = nullptr;
  ACE_CDR::ULong const count = node->nfields ();

  for (ACE_CDR::ULong i = 0; i < count; ++i)
    {
      node->field (member_ptr, i);

      be_type * const member_type =
        dynamic_cast<be_type*> ((*member_ptr)->field_type ());

      if (this->is_typecode_generation_required (member_type)
          && member_type->accept (this) != 0)
        {
          return -1;
        }

/*  MCO@20101020 - this is unnecessary since the check for recursiveness
 *  of *this* typecode has already been done before calling this method

      be_structure *bs = dynamic_cast<be_structure*> (node);
      if (bs)
        {
          be_visitor_typecode_defn::QNode const * const qnode =
            this->queue_lookup (this->tc_queue_, bs);

          ACE_Unbounded_Queue<AST_Type *> recursion_queue;
          recursion_queue.enqueue_tail(node);
          if (qnode
            && member_type->in_recursion (recursion_queue))
            {
              this->is_recursive_ = true;
            }
        }
*/
    }

  return 0;
}

int
TAO::be_visitor_struct_typecode::visit_members (AST_Structure * node)
{
  AST_Field ** member_ptr = nullptr;
  ACE_CDR::ULong const count = node->nfields ();
  TAO_OutStream & os = *this->ctx_->stream ();

  for (ACE_CDR::ULong i = 0; i < count; ++i)
    {
      node->field (member_ptr, i);

      be_decl * const member_decl =
        dynamic_cast<be_decl*> (*member_ptr);

      be_type * const member_type =
        dynamic_cast<be_type*> ((*member_ptr)->field_type ());

      os << "{ "
         << "\"" << member_decl->original_local_name () << "\", "
         << "&"  << member_type->tc_name ()
         << " }";

      if (i < count - 1)
        {
          os << "," << be_nl;
        }
    }

  return 0;
}
