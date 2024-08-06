#include "ADConduction.h"

registerMooseObject("FoxApp", ADConduction);

InputParameters
ADConduction::validParams()
{
  InputParameters params = ADKernelGrad::validParams();

  params.addClassDescription("Compute the heat conduction term in the heat equation."
                             "\\nabla w \\cdot T ...");

  params.addRequiredParam<Real>("thermal_conductivity", "isotropic conductivity ($k$) of the material");

  return params;
}

ADConduction::ADConduction(const InputParameters & parameters)
  : ADKernelGrad(parameters),
  _thermalConductivity(getParam<Real>("thermal_conductivity"))
{
    
}

ADRealVectorValue
ADConduction::precomputeQpResidual()
{
  return _thermalConductivity * _grad_u[_qp];
}