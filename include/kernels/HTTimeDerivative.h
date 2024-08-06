#pragma once

#include "TimeDerivative.h"

class HTTimeDerivative : public TimeDerivative
{
public:
  HTTimeDerivative(const InputParameters & parameters);

  static InputParameters validParams();

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  const Real _density;
  const Real _thermalCapacity;
};