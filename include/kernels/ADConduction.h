#pragma once

#include "ADKernelGrad.h"

/**
*Compute compute the residual contribution: grad_test * k *grad_u
*/
class ADConduction : public ADKernelGrad
{
public:
    static InputParameters validParams();

    ADConduction(const InputParameters& parameters);

protected:
    // ADKernel objects must override precompute QpResidual
    virtual ADRealVectorValue precomputeQpResidual() override;

 
    // Heat conduction parameters
    const Real _thermalConductivity;
};