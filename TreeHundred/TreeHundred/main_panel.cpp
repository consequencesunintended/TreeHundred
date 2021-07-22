#include "main_panel.h"
#include "imgui.h"

void MAIN_PANEL::init( void )
{
}

void MAIN_PANEL::draw( void )
{
	GRAPHICS_UTILITY::draw_line( MATH_VECTOR_2D( 0.0f, 0.0f ), MATH_VECTOR_2D( 0.0f, 1.0f ) );


	static float f = 0.0f;
	static int counter = 0;

	ImVec4 clear_color = ImVec4( 0.45f, 0.55f, 0.60f, 1.00f );

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
}

void MAIN_PANEL::update( void )
{
}
