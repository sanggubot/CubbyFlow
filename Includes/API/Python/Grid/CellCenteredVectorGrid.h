/*************************************************************************
> File Name: CellCenteredVectorGrid.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: CellCenteredVectorGrid functions for CubbyFlow Python API.
> Created Time: 2018/02/06
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_PYTHON_CELL_CENTERED_VECTOR_GRID_H
#define CUBBYFLOW_PYTHON_CELL_CENTERED_VECTOR_GRID_H

#include <pybind11/pybind11.h>

void AddCellCenteredVectorGrid2(pybind11::module& m);
void AddCellCenteredVectorGrid3(pybind11::module& m);

#endif