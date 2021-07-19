#pragma

#include "glfw3.h"
#include "graphics_color.h"
#include "math_vector_2d.h"

namespace GRAPHICS
{
	void draw_line( const MATH_VECTOR_2D& start, const MATH_VECTOR_2D& end )
	{
		glPushMatrix();

		glColor4fv( GRAPHICS_COLOR::White().GetRGBA() );

		glBegin( GL_LINES );

		glVertex3f( start.X, start.Y, 0.0f );
		glVertex3f( end.X, end.Y, 0.0f );

		glEnd();
		glPopMatrix();
	}
}