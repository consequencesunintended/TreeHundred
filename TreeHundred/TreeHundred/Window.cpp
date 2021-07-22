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
	return GRAPHICS::main_graphics<MAIN_PANEL>( 1024, 620 );
}



