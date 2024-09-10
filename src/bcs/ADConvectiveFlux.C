#include "ADConvectiveFlux.h"

registerMooseObject("FoxApp", ADConvectiveFlux);

InputParameters
ADConvectiveFlux::validParams()
{
    InputParameters params = IntegratedBC::validParams();

    // Parameters
    params.addRequiredParam<Real>("htc", "Heat transfert coefficient")
    params.addRequiredParam<Real>("t_infinity", "Temperature around boundary")

    return params;
}

ADConvectiveFlux::ADConvectiveFlux(const InputParameters & parameters)
    : IntegratedBC(parameters),
    _htc(getParam<Real>("htc")),
    _some_var_val(coupledValue("some_var"))
{
}

Real
ADConvectiveFlux::computeQpResidual()
{
    return 
}

