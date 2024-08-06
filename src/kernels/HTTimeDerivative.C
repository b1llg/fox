#include "HTTimeDerivative.h"

#include "Material.h"

registerMooseObject("FoxApp", HTTimeDerivative);

InputParameters
HTTimeDerivative::validParams()
{
  InputParameters params = TimeDerivative::validParams();
    
    params.addClassDescription("Computes the time derivative of temperature: $\\rho C_{p} \\dfrac{\partial T}{\partial t}$");

    params.addRequiredParam<Real>("density", "density of the material kg/m3");
    params.addRequiredParam<Real>("thermal_capacity", "thermal capacity j/kgk");

    return params;
}

HTTimeDerivative::HTTimeDerivative(const InputParameters & parameters)
  : TimeDerivative(parameters), 
  _density(getParam<Real>("density")),
  _thermalCapacity(getParam<Real>("thermal_capacity"))
{
}

Real
HTTimeDerivative::computeQpResidual()
{
  return _density * _thermalCapacity * TimeDerivative::computeQpResidual();
}

Real
HTTimeDerivative::computeQpJacobian()
{
  return _density * _thermalCapacity * TimeDerivative::computeQpJacobian();
}