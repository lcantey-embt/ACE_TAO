# Microsoft Developer Studio Project File - Name="mif_server" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=mif_server - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE run the tool that generated this project file and specify the
!MESSAGE nmake output type.  You can then use the following command:
!MESSAGE
!MESSAGE NMAKE /f "mif_server.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "mif_server.mak" CFG="mif_server - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "mif_server - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mif_server - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mif_server - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\mif_server"
# PROP Target_Dir ""
# ADD CPP /nologo /O2 /W3 /GX /MD /GR /I "..\..\..\tao\RTScheduling" /I "..\..\..\tao\RTCORBA" /I "..\..\..\..\Kokyu" /I "..\..\..\examples\Kokyu_dsrt_schedulers" /I "..\..\.." /I "..\..\..\tao" /I "..\..\..\.." /D NDEBUG /D WIN32 /D _CONSOLE /FD /c
# SUBTRACT CPP /YX
# ADD RSC /l 0x409 /d NDEBUG /i "..\..\..\tao\RTScheduling" /i "..\..\..\tao\RTCORBA" /i "..\..\..\..\Kokyu" /i "..\..\..\examples\Kokyu_dsrt_schedulers" /i "..\..\.." /i "..\..\..\tao" /i "..\..\..\.."
BSC32=bscmake.exe
# ADD BSC32 /nologo 
LINK32=link.exe
# ADD LINK32 advapi32.lib user32.lib /INCREMENTAL:NO TAO_RTScheduler.lib Kokyu.lib Kokyu_DSRT_Schedulers.lib TAO_RTCORBA.lib TAO_PortableServer.lib TAO_IORInterceptor.lib TAO_Valuetype.lib TAO_ObjRefTemplate.lib TAO.lib ACE.lib /libpath:"..\..\..\examples\Kokyu_dsrt_schedulers" /libpath:"..\..\..\tao\RTScheduling" /libpath:"..\..\..\tao\RTCORBA" /libpath:"..\..\..\tao\PortableServer" /libpath:"..\..\..\tao\IORInterceptor" /libpath:"..\..\..\tao\Valuetype" /libpath:"..\..\..\tao\ObjRefTemplate" /libpath:"..\..\..\..\Kokyu" /libpath:"..\..\..\tao" /libpath:"..\..\..\..\ace" /libpath:"..\..\..\..\lib" /nologo /version:1.3.1 /subsystem:console /pdb:"Release\server.pdb"  /machine:I386 /out:"Release\server.exe"

!ELSEIF  "$(CFG)" == "mif_server - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "Debug\mif_server"
# PROP Target_Dir ""
# ADD CPP /nologo /Ob0 /W3 /Gm /GX /Zi /MDd /GR /Gy /I "..\..\..\tao\RTScheduling" /I "..\..\..\tao\RTCORBA" /I "..\..\..\..\Kokyu" /I "..\..\..\examples\Kokyu_dsrt_schedulers" /I "..\..\.." /I "..\..\..\tao" /I "..\..\..\.." /D _DEBUG /D WIN32 /D _CONSOLE /FD /c
# SUBTRACT CPP /YX
# ADD RSC /l 0x409 /d _DEBUG /i "..\..\..\tao\RTScheduling" /i "..\..\..\tao\RTCORBA" /i "..\..\..\..\Kokyu" /i "..\..\..\examples\Kokyu_dsrt_schedulers" /i "..\..\.." /i "..\..\..\tao" /i "..\..\..\.."
BSC32=bscmake.exe
# ADD BSC32 /nologo 
LINK32=link.exe
# ADD LINK32 advapi32.lib user32.lib /INCREMENTAL:NO TAO_RTSchedulerd.lib Kokyud.lib Kokyu_DSRT_Schedulersd.lib TAO_RTCORBAd.lib TAO_PortableServerd.lib TAO_IORInterceptord.lib TAO_Valuetyped.lib TAO_ObjRefTemplated.lib TAOd.lib ACEd.lib /libpath:"..\..\..\examples\Kokyu_dsrt_schedulers" /libpath:"..\..\..\tao\RTScheduling" /libpath:"..\..\..\tao\RTCORBA" /libpath:"..\..\..\tao\PortableServer" /libpath:"..\..\..\tao\IORInterceptor" /libpath:"..\..\..\tao\Valuetype" /libpath:"..\..\..\tao\ObjRefTemplate" /libpath:"..\..\..\..\Kokyu" /libpath:"..\..\..\tao" /libpath:"..\..\..\..\ace" /libpath:"..\..\..\..\lib" /nologo /version:1.3.1 /subsystem:console /pdb:".\server.pdb" /debug /machine:I386 /out:".\server.exe"

!ENDIF

# Begin Target

# Name "mif_server - Win32 Release"
# Name "mif_server - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE=".\server.cpp"
# End Source File
# Begin Source File

SOURCE=".\test_i.cpp"
# End Source File
# Begin Source File

SOURCE=".\testC.cpp"
# End Source File
# Begin Source File

SOURCE=".\testS.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE=".\test_i.h"
# End Source File
# Begin Source File

SOURCE=".\testC.h"
# End Source File
# Begin Source File

SOURCE=".\testS.h"
# End Source File
# Begin Source File

SOURCE=".\testS_T.h"
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "i;inl"
# Begin Source File

SOURCE=".\test_i.i"
# End Source File
# Begin Source File

SOURCE=".\testC.i"
# End Source File
# Begin Source File

SOURCE=".\testS.i"
# End Source File
# Begin Source File

SOURCE=".\testS_T.i"
# End Source File
# End Group
# Begin Group "Template Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\testS_T.cpp"
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "Documentation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\README"
# End Source File
# Begin Source File

SOURCE=".\timeline.txt"
# End Source File
# End Group
# Begin Group "IDL Files"

# PROP Default_Filter "idl"
# Begin Source File

SOURCE=".\test.idl"

!IF  "$(CFG)" == "mif_server - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Invoking IDL Compiler on $(InputPath)
InputPath=.\test.idl
InputName=test
InputDir=.

BuildCmds= \
	PATH=%PATH%;..\..\..\..\lib \
	..\..\..\..\bin\tao_idl -o . -Gv -Ge 1 -Sc -Wb,pre_include=ace\pre.h -Wb,post_include=ace\post.h $(InputPath)

".\$(InputName)C.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == "mif_server - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Invoking IDL Compiler on $(InputPath)
InputPath=.\test.idl
InputName=test
InputDir=.

BuildCmds= \
	PATH=%PATH%;..\..\..\..\lib \
	..\..\..\..\bin\tao_idl -o . -Gv -Ge 1 -Sc -Wb,pre_include=ace\pre.h -Wb,post_include=ace\post.h $(InputPath)

".\$(InputName)C.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF

# End Source File
# End Group
# End Target
# End Project
