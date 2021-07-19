// -- LOCAL

// .. REFERENCES

#include "glfw3.h"
#include "graphics_utility.h"
#include "graphics_helper.h"
#include "math_vector_2d.h"

#include <iostream>


GLint                                                       windowWidth, windowHeight;

void controls( GLFWwindow* window, int key, int scancode, int action, int mods )
{
    if ( action == GLFW_PRESS && key == GLFW_KEY_ESCAPE )
    {
        glfwSetWindowShouldClose( window, GL_TRUE );
    }
}

GLFWwindow* initWindow( const int resX, const int resY )
{
    if ( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return NULL;
    }
    glfwWindowHint( GLFW_SAMPLES, 4 );

    GLFWwindow* window = glfwCreateWindow( resX, resY, "TreeHundred", NULL, NULL );

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

void display( GLFWwindow* window )
{

    glfwGetWindowSize( window, &windowWidth, &windowHeight );

    GRAPHICS::setup3DView( windowWidth, windowHeight );

    GRAPHICS::draw_line( MATH_VECTOR_2D( 0.0f, 0.0f ), MATH_VECTOR_2D( 0.0f, 1.0f ) );

    glfwSwapBuffers( window );
}

void init()
{

}

void update()
{
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
    init();


    glfwMakeContextCurrent( window );


    while ( !glfwWindowShouldClose( window ) )
    {
        update();
        display( window );

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}



