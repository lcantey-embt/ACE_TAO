// $Id$
#include "Config_Handlers_Export.h"
#ifndef DEPLOYMENT_HPP
#define DEPLOYMENT_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include <memory>
#include <vector>
#include <XMLSchema/Types.hpp>

#include "Basic_Deployment_Data.hpp"

#include "cpd.hpp"

#include "cdd.hpp"

#include "cdp.hpp"

#include "pcd.hpp"

#include "toplevel.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    Config_Handlers_Export
    ::CIAO::Config_Handlers::Domain
    domain (xercesc::DOMDocument const*);

    Config_Handlers_Export
    ::CIAO::Config_Handlers::DeploymentPlan
    deploymentPlan (xercesc::DOMDocument const*);

    Config_Handlers_Export
    ::CIAO::Config_Handlers::ImplementationArtifactDescription
    implementationArtifactDescription (xercesc::DOMDocument const*);

    Config_Handlers_Export
    ::CIAO::Config_Handlers::ComponentInterfaceDescription
    componentInterfaceDescription (xercesc::DOMDocument const*);

    Config_Handlers_Export
    ::CIAO::Config_Handlers::ComponentImplementationDescription
    componentImplementationDescription (xercesc::DOMDocument const*);

    Config_Handlers_Export
    ::CIAO::Config_Handlers::ComponentPackageDescription
    componentPackageDescription (xercesc::DOMDocument const*);

    Config_Handlers_Export
    ::CIAO::Config_Handlers::PackageConfiguration
    packageConfiguration (xercesc::DOMDocument const*);

    Config_Handlers_Export
    ::CIAO::Config_Handlers::TopLevelPackageDescription
    topLevelPackageDescription (xercesc::DOMDocument const*);
  }
}

#include <XMLSchema/Traversal.hpp>

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
    }
  }
}

#include <XMLSchema/Writer.hpp>

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    Config_Handlers_Export
    void
    domain (::CIAO::Config_Handlers::Domain const&, xercesc::DOMDocument*);

    Config_Handlers_Export
    void
    deploymentPlan (::CIAO::Config_Handlers::DeploymentPlan const&, xercesc::DOMDocument*);

    Config_Handlers_Export
    void
    implementationArtifactDescription (::CIAO::Config_Handlers::ImplementationArtifactDescription const&, xercesc::DOMDocument*);

    Config_Handlers_Export
    void
    componentInterfaceDescription (::CIAO::Config_Handlers::ComponentInterfaceDescription const&, xercesc::DOMDocument*);

    Config_Handlers_Export
    void
    componentImplementationDescription (::CIAO::Config_Handlers::ComponentImplementationDescription const&, xercesc::DOMDocument*);

    Config_Handlers_Export
    void
    componentPackageDescription (::CIAO::Config_Handlers::ComponentPackageDescription const&, xercesc::DOMDocument*);

    Config_Handlers_Export
    void
    packageConfiguration (::CIAO::Config_Handlers::PackageConfiguration const&, xercesc::DOMDocument*);

    Config_Handlers_Export
    void
    topLevelPackageDescription (::CIAO::Config_Handlers::TopLevelPackageDescription const&, xercesc::DOMDocument*);
  }
}

#endif // DEPLOYMENT_HPP
