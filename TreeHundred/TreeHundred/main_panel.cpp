#include "main_panel.h"
#include "imgui.h"
#include "graphics_color.h"

#include <string>
#include <vector>
#include <map>

void MAIN_PANEL::init( void )
{
	m_plant.m_axiom = "F";
	m_plant.m_rules[ 'F' ] = "F[+F]F[-F]F";
	m_plant.m_rotation_degree = 25.7;
}


void MAIN_PANEL::create_ui( void )
{
	ImGui::Begin( "Hello Tree" );
	ImGui::SliderInt( "Itereation", &m_iteration, 0, 10 );
	ImGui::End();
}


void MAIN_PANEL::draw( void )
{
	create_ui();

	m_plant.draw();

}

void MAIN_PANEL::update( void )
{
	m_plant.create( m_iteration );
}
