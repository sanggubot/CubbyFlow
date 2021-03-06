/*************************************************************************
> File Name: GridPressureSolver2.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: Abstract base class for 2-D grid-based pressure solver.
> Created Time: 2017/08/10
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_GRID_PRESSURE_SOLVER2_H
#define CUBBYFLOW_GRID_PRESSURE_SOLVER2_H

#include <Core/Field/ConstantScalarField2.h>
#include <Core/Field/ConstantVectorField2.h>
#include <Core/Grid/FaceCenteredGrid2.h>
#include <Core/Solver/Grid/GridBoundaryConditionSolver2.h>

namespace CubbyFlow
{
	//!
	//! \brief Abstract base class for 2-D grid-based pressure solver.
	//!
	//! This class represents a 2-D grid-based pressure solver interface which can
	//! be used as a sub-step of GridFluidSolver2. Inheriting classes must implement
	//! the core GridPressureSolver2::Solve function as well as the helper function
	//! GridPressureSolver2::SuggestedBoundaryConditionSolver.
	//!
	class GridPressureSolver2
	{
	public:
		//! Default constructor.
		GridPressureSolver2();

		//! Default destructor.
		virtual ~GridPressureSolver2();

		//!
		//! \brief Solves the pressure term and apply it to the velocity field.
		//!
		//! This function takes input velocity field and outputs pressure-applied
		//! velocity field. It also accepts extra arguments such as \p boundarySDF
		//! and \p fluidSDF that represent signed-distance representation of the
		//! boundary and fluid area. The negative region of \p boundarySDF means
		//! it is occupied by solid object. Also, the positive / negative area of
		//! the \p fluidSDF means it is occupied by fluid / atmosphere. If not
		//! specified, constant scalar field with std::numeric_limits<double>::max() will be used for
		//! \p boundarySDF meaning that no boundary at all. Similarly, a constant
		//! field with -std::numeric_limits<double>::max() will be used for \p fluidSDF which means it's fully
		//! occupied with fluid without any atmosphere.
		//!
		//! \param[in]    input                 The input velocity field.
		//! \param[in]    timeIntervalInSeconds The time interval for the sim.
		//! \param[inout] output                The output velocity field.
		//! \param[in]    boundarySDF           The SDF of the boundary.
		//! \param[in]    boundaryVelocity      The velocity of the boundary.
		//! \param[in]    fluidSDF              The SDF of the fluid/atmosphere.
		//! \param[in]    useCompressed         True if it uses compressed system.
		//!
		virtual void Solve(
			const FaceCenteredGrid2& input,
			double timeIntervalInSeconds,
			FaceCenteredGrid2* output,
			const ScalarField2& boundarySDF = ConstantScalarField2(std::numeric_limits<double>::max()),
			const VectorField2& boundaryVelocity = ConstantVectorField2({ 0, 0 }),
			const ScalarField2& fluidSDF = ConstantScalarField2(-std::numeric_limits<double>::max()),
			bool useCompressed = false) = 0;

		//!
		//! \brief Returns the best boundary condition solver for this solver.
		//!
		//! This function returns the best boundary condition solver that works well
		//! with this pressure solver. Depending on the pressure solver
		//! implementation, different boundary condition solver might be used.
		//!
		virtual GridBoundaryConditionSolver2Ptr	SuggestedBoundaryConditionSolver() const = 0;
	};

	//! Shared pointer type for the GridPressureSolver2.
	using GridPressureSolver2Ptr = std::shared_ptr<GridPressureSolver2>;
}

#endif