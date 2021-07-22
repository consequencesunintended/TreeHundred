// -- LOCAL

// .. REFERENCES

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include <stdio.h>

#include "main_panel.h"
#include "graphics_helper.h"


int main( int argc, char** argv )
{
    GLint  windowWidth, windowHeight;

    GRAPHICS::main_panel = std::make_unique<MAIN_PANEL>();
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

    ImVec4 clear_color = ImVec4( 0.45f, 0.55f, 0.60f, 1.00f );

    while ( !glfwWindowShouldClose( window ) )
    {
        glfwPollEvents();

        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin( "Hello, world!" );                          

        ImGui::Text( "This is some useful text." );               

        ImGui::SliderFloat( "float", &f, 0.0f, 1.0f );            
        ImGui::ColorEdit3( "clear color", ( float* )&clear_color );

        if ( ImGui::Button( "Button" ) )
        {
            counter++;
        }
        ImGui::SameLine();
        ImGui::Text( "counter = %d", counter );
        ImGui::Text( "Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate );
        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize( window, &display_w, &display_h );
        glViewport( 0, 0, display_w, display_h );
        glClearColor( clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w );
        glClear( GL_COLOR_BUFFER_BIT );

        GRAPHICS::main_panel->update();

        glfwGetWindowSize( window, &windowWidth, &windowHeight );

        GRAPHICS::setup3DView( windowWidth, windowHeight );

        GRAPHICS::main_panel->draw();


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



