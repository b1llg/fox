#include "FoxApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
FoxApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

FoxApp::FoxApp(InputParameters parameters) : MooseApp(parameters)
{
  FoxApp::registerAll(_factory, _action_factory, _syntax);
}

FoxApp::~FoxApp() {}

void
FoxApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<FoxApp>(f, af, s);
  Registry::registerObjectsTo(f, {"FoxApp"});
  Registry::registerActionsTo(af, {"FoxApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
FoxApp::registerApps()
{
  registerApp(FoxApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
FoxApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FoxApp::registerAll(f, af, s);
}
extern "C" void
FoxApp__registerApps()
{
  FoxApp::registerApps();
}
