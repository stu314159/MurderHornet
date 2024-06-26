//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ADLapalceYoungNeumannBC.h"

registerMooseObject("MooseApp", ADLaplaceYoungNeumannBC);

InputParameters
ADLaplaceYoungNeumannBC::validParams()
{
  InputParameters params = ADIntegratedBC::validParams();
  params.addRequiredParam<Real>("value", "Value of the BC");
  params.addParam<Real>("value", 0.0, "The value of the gradient on the boundary.");
  params.declareControllable("value");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$\\frac{\\partial u}{\\partial n}=h$, "
                             "where $h$ is a constant, controllable value.");
  return params;
}

ADLaplaceYoungNeumannBC::ADLaplaceYoungNeumannBC(const InputParameters & parameters)
  : ADIntegratedBC(parameters), _value(getParam<Real>("value"))
{
}

ADReal
ADLaplaceYoungNeumannBC::computeQpResidual()
{
//  ADReal k = std::sqrt(1 + _grad_u[_qp] * _grad_u[_qp]);
//  return -_test[_i][_qp] * _value * k;
    return -_test[_i][_qp]*_value;
}
