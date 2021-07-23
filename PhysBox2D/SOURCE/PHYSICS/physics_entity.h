
#pragma once

// -- LOCAL
	
// .. REFERENCES

#include "math_vector_2d.h"
#include <assert.h>

// -- GLOBAL

// .. TYPES

class ENTITY
{
	public:
	MATH_VECTOR_2D	Position;
};

class PHYSICS_ENTITY : virtual public ENTITY
{
	public:

	virtual MATH_VECTOR_2D GetAcceleration() = 0;

	virtual MATH_VECTOR_2D& ForceValue() = 0;

	MATH_VECTOR_2D	Velocity;	
	MATH_VECTOR_2D	OldPosition;
	float			Mass{ 1 };

	protected:

	MATH_VECTOR_2D	Force;

};

class MOVEABLE_PHYSICS_ENTITY : public PHYSICS_ENTITY
{
	public:

	MATH_VECTOR_2D GetAcceleration() override
	{
		return Force / Mass;
	}

	MATH_VECTOR_2D& ForceValue() override
	{
		return Force;
	}
};

class STATIC_PHYSICS_ENTITY : public PHYSICS_ENTITY
{
	MATH_VECTOR_2D GetAcceleration() override
	{
		return MATH_VECTOR_2D();
	}

	MATH_VECTOR_2D& ForceValue() override
	{
		return dummy_force;
	}

	private:

	MATH_VECTOR_2D	dummy_force;
};