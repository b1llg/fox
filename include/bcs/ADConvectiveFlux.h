#pragma once

#include "ADIntegratedBCS.h"

class ADConvectiveFlux : public ADMatNeumannBC
{
public:
    ADConvectiveFlux(const InputParameters & parameters);

    static InputParameters validParams();

protected:

    virtual Real computeResidual() override;

private:

    Real _htc;
    Real _t_infinity;

    const VariableValue & _some_var;

}