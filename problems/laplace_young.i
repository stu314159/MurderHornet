[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 20
  ny = 20
  uniform_refine = 4
[]

[Variables]
  [u]
  []
[]

[Kernels]
  [diffusion]
    type = LaplaceYoungDiffusion
    variable = u
  []
  [source]
    type = LaplaceYoungSource
    variable = u
    kappa = 1.0
  []
[]

[BCs]
  [all]
    type = ADLaplaceYoungNeumannBC
    variable = u
    value = 0.2
    boundary = "left right top bottom"
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON
  petsc_options_iname = '-pc_type'
  petsc_options_value = 'lu'
[]

[Outputs]
  exodus = true
[]
