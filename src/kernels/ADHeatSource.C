#include "ADHeatSource.h"

registerMooseObject("FoxApp", ADHeatSource);

InputParameters
ADHeatSource::validParams()
{
  InputParameters params = ADKernelValue::validParams();

  params.addClassDescription("Compute the heat conduction term in the heat equation."
                             "\\nabla w \\cdot T ...");

  params.addRequiredParam<Real>("heat_source", "heat source ($s (w/m^3$) of the material");

  return params;
}

ADHeatSource::ADHeatSource(const InputParameters & parameters)
  : ADKernelValue(parameters),
  _heatSource(getParam<Real>("heat_source"))
{
    
}

ADReal
ADHeatSource::precomputeQpResidual()
{
  return -1.0*_heatSource;
}