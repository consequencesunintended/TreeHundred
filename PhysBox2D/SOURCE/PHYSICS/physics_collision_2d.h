#pragma once

// -- LOCAL

// .. REFERENCES

#include "physics_entity.h"
#include "math_point_2d.h"
#include "physics_spring.h"

// -- GLOBAL

// .. TYPES

class PHYSICS_COLLISION_2D
{
	// -- PUBLIC

	public:

	// .. OPERATIONS

	void CheckForCollision(
		PHYSICS_ENTITY& entity,
		const float damping_coefficient,
		const float min_x_value,
		const float max_x_value,
		const float min_y_value,
		const float max_y_value,
		const MATH_POINT_2D& position = MATH_POINT_2D( 0.0f, 0.0f )
	)
	{
		if ( entity.Position.Y < min_y_value + position.Y )
		{
			if ( fabs( entity.Velocity.Y ) < 1.0f )
			{
				entity.Velocity = MATH_VECTOR_2D( entity.Velocity.X, 0.0f );
				entity.Position = MATH_VECTOR_2D( entity.Position.X, min_y_value );
			}
			else
			{
				entity.Velocity = MATH_VECTOR_2D( entity.Velocity.X, -entity.Velocity.Y * damping_coefficient );
				entity.Position = MATH_VECTOR_2D( entity.Position.X, min_y_value + 0.001f );
			}
		}
	}
};