[Mesh]
    type = GeneratedMesh # Can generate simple lines, rectangles and rectangular prisms
    dim = 2 # Dimension of the mesh
    nx = 10 # Number of elements in the x direction
    ny = 10 # Number of elements in the y direction
    xmax = 1.0 # m - width of box
    ymax = 1.0 # m - height of box
    elem_type = QUAD9
[]
[Variables]
    [temperature]
        order = SECOND
        family = LAGRANGE
    []
[]
[Kernels]
    [conduction]
        type = ADConduction # Custom Conduction Kernel ref: lib/kernels/ADConduction.h and src/kernels/ADConduction.C
        variable = temperature # Operate on the "temperature" variable above
        thermal_conductivity = 50 # W/m^3
    []
[]
[BCs]
    [right]
        type = ADDirichletBC # Simple u=value BC
        variable = temperature # Variable to be set
        boundary = left # Name of a sideset in the mesh
        value = 500 # degK
    []
    [left]
        type = ADDirichletBC
        variable = temperature
        boundary = right
        value = 273 # degK
    []
[]
[Executioner]
    type = Steady # Steady state problem
    solve_type = NEWTON # Perform a Newton solve

    # Set PETSc parameters to optimize solver efficiency
    petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
    petsc_options_value = ' hypre    boomeramg'
[]
[Outputs]
    exodus = true # Output Exodus format
    perf_graph = true
[]