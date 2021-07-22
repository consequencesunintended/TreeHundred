#pragma once

#include "GLFW/glfw3.h"
#include "graphics_color.h"
#include "graphics_utility.h"
#include "math_vector_2d.h"
#include "physics_entity.h"
#include <vector>
#include <memory>

namespace GRAPHICS
{
	std::unique_ptr< PANEL_INTERFACE > main_panel;

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

	void controls( GLFWwindow* window, int key, int scancode, int action, int mods )
	{
		if ( action == GLFW_PRESS && key == GLFW_KEY_ESCAPE )
		{
			glfwSetWindowShouldClose( window, GL_TRUE );
		}

		main_panel->controls( window, key, scancode, action, mods );
	}

	GLFWwindow* create_window( const int& resX, const int& resY )
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

		printf( "Renderer: %s\n", glGetString( GL_RENDERER ) );
		printf( "OpenGL version supported %s\n", glGetString( GL_VERSION ) );

		glfwSetKeyCallback( window, controls );
		glEnable( GL_DEPTH_TEST );
		glDepthFunc( GL_LEQUAL );
		glDisable( GL_CULL_FACE );
		glCullFace( GL_BACK );
		return window;
	}


	GLFWwindow* initWindow( const int resX, const int resY )
	{
		return GRAPHICS::create_window( resX, resY );
	}


	template< class T>
	int main_graphics( const int width, const int height)
	{
		GLint  windowWidth, windowHeight;

		GRAPHICS::main_panel = std::make_unique<T>();
		GRAPHICS::main_panel->init();

		GLFWwindow* window = GRAPHICS::initWindow( 1024, 640 );

		if ( !window )
		{
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent( window );

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); ( void )io;

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL( window, true );
		ImGui_ImplOpenGL2_Init();

		while ( !glfwWindowShouldClose( window ) )
		{
			glfwPollEvents();

			ImGui_ImplOpenGL2_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			int display_w, display_h;
			glfwGetFramebufferSize( window, &display_w, &display_h );

			GRAPHICS::main_panel->update();

			glfwGetWindowSize( window, &windowWidth, &windowHeight );

			GRAPHICS::setup3DView( windowWidth, windowHeight );

			GRAPHICS::main_panel->draw();

			ImGui::Render();
			ImGui_ImplOpenGL2_RenderDrawData( ImGui::GetDrawData() );
			glfwMakeContextCurrent( window );
			glfwSwapBuffers( window );
		}

		ImGui_ImplOpenGL2_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		glfwDestroyWindow( window );
		glfwTerminate();
		return 0;
	}
};