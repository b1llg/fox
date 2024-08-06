#pragma once

#include "ADKernelValue.h"

/**
*Compute compute the residual contribution: _test * s
*/
class ADHeatSource : public ADKernelValue
{
public:
    static InputParameters validParams();

    ADHeatSource(const InputParameters& parameters);

protected:
    // ADKernel objects must override precompute QpResidual
    virtual ADReal precomputeQpResidual() override;

 
    // Heat conduction parameters
    const Real _heatSource;
};