#pragma once

#include "glfw3.h"
#include "graphics_color.h"
#include "math_vector_2d.h"
#include "physics_entity.h"
#include <vector>

namespace GRAPHICS
{
	void clear()
	{
		glClearColor( 114.0f / 255.0f, 0, 138.0f / 255.0f, 1.00 );
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	}

	void perspectiveGL( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
	{
		const GLdouble pi = 3.14;
		GLdouble fW, fH;

		fH = tan( fovY / 360 * pi ) * zNear;
		fW = fH * aspect;

		glFrustum( -fW, fW, -fH, fH, zNear, zFar );
	}

	void setup3DView( int windowWidth, int windowHeight )
	{
		glViewport( 0, 0, windowWidth, windowHeight );

		clear();

		glMatrixMode( GL_PROJECTION_MATRIX );
		glLoadIdentity();
		GRAPHICS::perspectiveGL( 100, ( double )windowWidth / ( double )windowHeight, 0.1, 100 );

		glMatrixMode( GL_MODELVIEW_MATRIX );
		glTranslatef( 0, 0, -5 );
	}

	GLFWwindow* create_window( const int& resX, const int& resY, void (*controls) (GLFWwindow*, int, int, int, int) )
	{
		if ( !glfwInit() )
		{
			fprintf( stderr, "Failed to initialize GLFW\n" );
			return NULL;
		}
		glfwWindowHint( GLFW_SAMPLES, 4 );

		GLFWwindow* window = glfwCreateWindow( resX, resY, "Circle", NULL, NULL );

		if ( window == NULL )
		{
			fprintf( stderr, "Failed to open GLFW window.\n" );
			glfwTerminate();
			return NULL;
		}

		glfwMakeContextCurrent( window );
		glfwSetKeyCallback( window, controls );

		printf( "Renderer: %s\n", glGetString( GL_RENDERER ) );
		printf( "OpenGL version supported %s\n", glGetString( GL_VERSION ) );

		glEnable( GL_DEPTH_TEST );
		glDepthFunc( GL_LEQUAL );
		glDisable( GL_CULL_FACE );
		glCullFace( GL_BACK );
		return window;
	}
};