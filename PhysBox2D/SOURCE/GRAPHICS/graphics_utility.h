#ifndef TEST
#define TEST

#include "GLFW/glfw3.h"
#include "graphics_color.h"
#include "math_vector_2d.h"

class PANEL_INTERFACE
{
	public:
	virtual void init( void ) = 0;
	virtual void draw( void ) = 0;
	virtual void update( void ) = 0;
	virtual void controls( GLFWwindow* window, int key, int scancode, int action, int mods )
	{

	}
};


class GRAPHICS_UTILITY
{
public:
	static void push_translation_matrix( const MATH_VECTOR_2D& translation )
	{
		glPushMatrix();
		glTranslatef( translation.X, translation.Y, 0.0f );
	}

	static void pop__matrix()
	{
		glPopMatrix();
	}
	static void draw_line( const MATH_VECTOR_2D& start, const MATH_VECTOR_2D& end, const GRAPHICS_COLOR& colour = GRAPHICS_COLOR::White() )
	{

		glColor4fv( colour.GetRGBA() );
		glBegin( GL_LINES );
		
		glVertex3f( start.X, start.Y, 0.0f );
		glVertex3f( end.X, end.Y, 0.0f );

		glEnd();
		
	}
};
#endif