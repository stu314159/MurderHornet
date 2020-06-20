//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADIntegratedBC.h"

/**
 * Implements a simple constant Neumann BC where grad(u)=value on the boundary.
 * Uses the term produced from integrating the diffusion operator by parts.
 */
class ADLaplaceYoungNeumannBC : public ADIntegratedBC
{
public:
  static InputParameters validParams();

  ADLaplaceYoungNeumannBC(const InputParameters & parameters);

protected:
  virtual ADReal computeQpResidual() override;

  /// Value of grad(u) on the boundary.
  const Real & _value;
};
