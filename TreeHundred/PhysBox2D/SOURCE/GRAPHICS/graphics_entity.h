#pragma once

#include "glfw3.h"
#include "graphics_color.h"
#include "math_vector_2d.h"
#include "physics_entity.h"
#include <vector>

class GRAPHICS_ENTITY : virtual public ENTITY
{
	public:

	virtual void create() = 0;

	void draw()
	{
		glPushMatrix();

		glColor4fv( GRAPHICS_COLOR::White().GetRGBA() );
		glTranslatef( Position.X, Position.Y, 0.0f );

		glBegin( GL_LINE_LOOP );

		for ( auto& v : lines )
		{
			glVertex3f( v.X, v.Y, 0.0f );
		}
		glEnd();
		glPopMatrix();
	}
	std::vector< MATH_VECTOR_2D > lines;
};

class GRAPHICS_CIRCLE : public GRAPHICS_ENTITY
{
	public:

	void create() override
	{
		MATH_VECTOR_2D v = MATH_VECTOR_2D( Radius, 0.0 );

		const float sections = 6.28 / ( float )Tessellation;

		for ( size_t i = 0; i < Tessellation; ++i )
		{
			v.Rotate( sections );
			lines.push_back( v );
		}
	}
	float			Radius;
	int				Tessellation;
	float* Rgba_colour{ nullptr };
};

class GRAPHICS_SQUARE : public GRAPHICS_ENTITY
{
	public:


	void create() override
	{
		lines.push_back( MATH_VECTOR_2D( -Width / 2.0f, Height / 2.0f ) );
		lines.push_back( MATH_VECTOR_2D( Width / 2.0, Height / 2.0f ) );
		lines.push_back( MATH_VECTOR_2D( Width / 2.0, -Height / 2.0f ) );
		lines.push_back( MATH_VECTOR_2D( -Width / 2.0, -Height / 2.0f ) );
	}

	float Width;
	float Height;
};