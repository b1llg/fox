[Mesh]
    type = GeneratedMesh # Can generate simple lines, rectangles and rectangular prisms
    dim  = 2                      # Dimension of the mesh
    nx   = 10                     # Number of elements in the x direction
    ny   = 10                     # Number of elements in the y direction
    xmax = 1.0                    # m - width of box
    ymax = 1.0                    # m - height of box
    elem_type = QUAD8
[]
[Variables]
    [temperature]
        order = FIRST
        family = LAGRANGE
    []
[]
[Kernels]
    [conduction]
      type = ADConduction         # Custom Conduction Kernel ref: lib/kernels/ADConduction.h and src/kernels/ADConduction.C
      variable = temperature      # Operate on the "temperature" variable above
      thermal_conductivity = 50   # W/m^3
    []
[]
[Kernels]
  [hgen]
    type = ADHeatSource         # Custom Conduction Kernel ref: lib/kernels/ADHeatSource.h and src/kernels/ADHeatSource.C
    variable = temperature      # Operate on the "temperature" variable above
    heat_source = 75000    # W/m^3
  []
  # Include our time derivative here
  [impeuler]
    type = HTTimeDerivative
    variable = temperature
    density = 7850             # kg/m3
    thermal_capacity = 880     # J/kgk
  []
[]
[BCs]
    [right]
      type = ADDirichletBC        # Simple u=value BC
      variable = temperature      # Variable to be set
      boundary = left             # Name of a sideset in the mesh
      value = 500                 # degK
    []
    [left]
      type = ADDirichletBC
      variable = temperature
      boundary = right
      value = 273                 # degK
    []
[]
[Executioner]
  type = Transient   # Here we use the Transient Executioner (instead of steady)
  start_time = 0
  end_time = 100000
  dtmin = 1
  dtmax = 100
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