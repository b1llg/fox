//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "FoxTestApp.h"
#include "FoxApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
FoxTestApp::validParams()
{
  InputParameters params = FoxApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

FoxTestApp::FoxTestApp(InputParameters parameters) : MooseApp(parameters)
{
  FoxTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

FoxTestApp::~FoxTestApp() {}

void
FoxTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  FoxApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"FoxTestApp"});
    Registry::registerActionsTo(af, {"FoxTestApp"});
  }
}

void
FoxTestApp::registerApps()
{
  registerApp(FoxApp);
  registerApp(FoxTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
FoxTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FoxTestApp::registerAll(f, af, s);
}
extern "C" void
FoxTestApp__registerApps()
{
  FoxTestApp::registerApps();
}
