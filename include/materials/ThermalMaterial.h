#include "Material.h"


class ThermalMaterial : public Material
{
public:
  ThermalMaterial(const InputParameters & parameters);

  static InputParameters validParams();

protected:
//   virtual void computeQpProperties() override;

private:
  /// member variable to hold the computed diffusivity coefficient
    MaterialProperty<Real> & _heat_conduction;
    MaterialProperty<Real> & _heat_capacity;
};