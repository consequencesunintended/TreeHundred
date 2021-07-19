
#pragma once

// -- LOCAL

// .. REFERENCES

#include "math_square_root.h"
#include <math.h>  
#include <assert.h>

// .. TYPES

class MATH_VECTOR_2D
{
	// -- PUBLIC

	public:

	// .. CONSTRUCTORS

	MATH_VECTOR_2D( void ) :
		X( 0 ),
		Y( 0 )
	{
	}

	// ~~

	MATH_VECTOR_2D( const float x_value ) :
		X( x_value ),
		Y( x_value )
	{
	}

	// ~~

	MATH_VECTOR_2D( const float x_value, const float y_value ) :
		X( x_value ),
		Y( y_value )
	{
	}

	// ~~

	MATH_VECTOR_2D( const MATH_VECTOR_2D& other ) :
		X( other.X ),
		Y( other.Y )
	{
	}

	// ~~

	virtual ~MATH_VECTOR_2D( void )
	{
	}

	// .. OPERATORS

	MATH_VECTOR_2D& operator =( const MATH_VECTOR_2D& other )
	{
		X = other.X;
		Y = other.Y;

		return *this;
	}

	// ~~

	MATH_VECTOR_2D operator +( const MATH_VECTOR_2D& other ) const
	{
		return MATH_VECTOR_2D( X + other.X, Y + other.Y );
	}

	// ~~

	MATH_VECTOR_2D operator -( const MATH_VECTOR_2D& other ) const
	{
		return MATH_VECTOR_2D( X - other.X, Y - other.Y );
	}

	// ~~

	MATH_VECTOR_2D operator *( const MATH_VECTOR_2D& other ) const
	{
		return MATH_VECTOR_2D( X * other.X, Y * other.Y );
	}

	// ~~

	MATH_VECTOR_2D operator /( const MATH_VECTOR_2D& other ) const
	{
		return MATH_VECTOR_2D( X / other.X, Y / other.Y );
	}

	// ~~

	void operator +=( const MATH_VECTOR_2D& other )
	{
		X += other.X;
		Y += other.Y;
	}

	// ~~

	void operator -=( const MATH_VECTOR_2D& other )
	{
		X -= other.X;
		Y -= other.Y;
	}

	// ~~

	void operator *=( const MATH_VECTOR_2D& other )
	{
		X *= other.X;
		Y *= other.Y;
	}

	// ~~

	void operator /=( const MATH_VECTOR_2D& other )
	{
		X /= other.X;
		Y /= other.Y;
	}

	// ~~

	bool operator ==( const MATH_VECTOR_2D& other )
	{
		return ((X == other.X) && (Y == other.Y));
	}

	// .. INQUIRIES

	float GetLength( void ) const
	{
		return MATH_SQUARE_ROOT::GetSquareRoot( X * X + Y * Y );
	}

	// ~~

	float GetSquareLength( void ) const
	{
		return (X * X + Y * Y);
	}

	// ~~

	float GetDotProduct( const MATH_VECTOR_2D& other ) const
	{
		return X * other.X + Y * other.Y;
	}

	// .. OPERATIONS

	void Assign( const float x_value, const float y_value )
	{
		X = x_value;
		Y = y_value;
	}

	// ~~

	void Reset( void )
	{
		X = 0.0f;
		Y = 0.0f;
	}

	// ~~

	bool normalise( void )
	{
		if ( GetLength() != 0.0f )
		{
			X = X / GetLength();
			Y = Y / GetLength();

			return true;
		}
		else
		{
			X = 0.0f;
			Y = 0.0f;

			return false;
		}
	}

	// ~~

	void SetDifference( const MATH_VECTOR_2D& first, const MATH_VECTOR_2D& second )
	{
		X = second.X - first.X;
		Y = second.Y - first.Y;
	}

	void Rotate( float radius )
	{
		float new_x = cos( radius ) * X - sin( radius ) * Y;
		float new_y = sin( radius ) * X + cos( radius ) * Y;

		X = new_x;
		Y = new_y;
	}


	// .. ATTRIBUTES

	float X;
	float Y;
};

