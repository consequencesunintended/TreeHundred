// -- LOCAL

// .. REFERENCES

#include "glfw3.h"
#include "main_panel.h"
#include "graphics_utility.h"
#include "graphics_helper.h"
#include "math_vector_2d.h"

#include "memory"

#include <iostream>


GLint  windowWidth, windowHeight;
std::unique_ptr< PANEL_INTERFACE > main_panel = std::make_unique< MAIN_PANEL >();

void controls( GLFWwindow* window, int key, int scancode, int action, int mods )
{
    if ( action == GLFW_PRESS && key == GLFW_KEY_ESCAPE )
    {
        glfwSetWindowShouldClose( window, GL_TRUE );
    }
}

GLFWwindow* initWindow( const int resX, const int resY )
{    
    return GRAPHICS::create_window( resX, resY, controls );
}

void display( void )
{
    main_panel->draw();    
}

void init()
{
    main_panel->init();
}

void update()
{
    main_panel->update();
}

int main( int argc, char** argv )
{
    GLFWwindow* window;

    init();
    window = initWindow( 1024, 620 );

    if ( !window )
    {
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent( window );


    while ( !glfwWindowShouldClose( window ) )
    {
        update();

        glfwGetWindowSize( window, &windowWidth, &windowHeight );

        GRAPHICS::setup3DView( windowWidth, windowHeight );

        display();

        glfwSwapBuffers( window );

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}



