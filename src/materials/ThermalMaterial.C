#include "ThermalMaterial.h"

registerMooseObject("FoxApp", ThermalMaterial);

InputParameters
ThermalMaterial::validParams()
{
  InputParameters params = Material::validParams();

    params.addRequiredParam<Real>(
      "heat_conduction",
      "The conduction coefficient $k$ in $\\nable\\dot(k\\nabla T)=\\rho\\C_{p}\\dfrac{T}{t}$");

    params.addRequiredParam<Real>(
      "heat_capacity",
      "the heat capcity $C_{p}$ in $\\nabla\\dot(k\\nabla T)=\\rho\\C_{p}\\dfrac{T}{t}$");

  return params;
}

ThermalMaterial::ThermalMaterial(const InputParameters & parameters)
  : Material(parameters),
    // Declare that this material is going to provide a Real value typed
    // material property named "diffusivity" that Kernels and other objects can use.
    // This property is "bound" to the class's "_diffusivity" member.
    _conduction_coefficient(declareProperty<Real>("conduction_coefficient"))

{
}