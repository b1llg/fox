[Mesh]
  file = angle.e
[]
[Variables]
  [temperature]
    order = FIRST
    family = LAGRANGE
  []
[]
[Kernels]
  [conduction]
    type = ADConduction # Custom Conduction Kernel ref: lib/kernels/ADConduction.h and src/kernels/ADConduction.C
    variable = temperature # Operate on the "temperature" variable above
    thermal_conductivity = 50e-3 # W/mmK
  []
  # Include our time derivative here
  [impeuler]
    type = HTTimeDerivative
    variable = temperature
    density = 7.85e-6 # kg/mm3
    thermal_capacity = 880 # J/kgk
  []
[]
[BCs]
  [top]
    type = ADDirichletBC # Simple u=value BC
    variable = temperature # Variable to be set
    boundary = top # Name of a sideset in the mesh
    value = 500 # degK
  []
  [right]
    type = ADDirichletBC
    variable = temperature
    boundary = right
    value = 273 # degK
  []
[]
[Executioner]
  type = Transient # Here we use the Transient Executioner (instead of steady)
  start_time = 0
  end_time = 10000
  dtmin = 1e-3
  dtmax = 1000
  [TimeStepper]
    type = IterationAdaptiveDT
    dt = 0.5
  []
  solve_type = NEWTON
  scheme = implicit-euler
  petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
  petsc_options_value = ' hypre    boomeramg'
[]
[Outputs]
  exodus = true # Output Exodus format
  perf_graph = true
[]