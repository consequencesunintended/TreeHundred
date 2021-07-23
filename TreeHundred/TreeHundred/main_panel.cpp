#include "main_panel.h"
#include "imgui.h"
#include "graphics_color.h"
#include <string>
#include <vector>
#include <map>

void MAIN_PANEL::init( void )
{
	m_plant.reset();
	m_plant.m_axiom = "F";
	m_plant.m_rules[ 'F' ] = "F[+F]F[-F]F";
	m_plant.m_rotation_degree = 25.7;
	m_plant.create( m_iteration );
}


void MAIN_PANEL::create_ui( void )
{
	ImGui::Begin( "Hello Tree" );
	if ( ImGui::SliderInt( "Itereation", &m_iteration, 0, 7 ) )
	{
		m_plant.create( m_iteration );
	}
	if ( ImGui::SliderFloat( "growth rate", &m_growth_rate, 0.0f, 0.1f ) )
	{
		m_plant.m_growth_rate = m_growth_rate;
		m_plant.create( m_iteration );
	}

	if ( ImGui::Button( "Plant1" ) )
	{
		m_plant.reset();
		m_plant.m_axiom = "F";
		m_plant.m_rules[ 'F' ] = "F[+F]F[-F]F";
		m_plant.m_rotation_degree = 25.7;
		m_plant.create( m_iteration );
	}

	if ( ImGui::Button( "Plant2" ) )
	{
		m_plant.reset();
		m_plant.m_axiom = "F";
		m_plant.m_rules[ 'F' ] = "F[+F]F[-F][F]";
		m_plant.m_rotation_degree = 20.f;
		m_plant.create( m_iteration );
	}

	if ( ImGui::Button( "Plant3" ) )
	{
		m_plant.reset();
		m_plant.m_axiom = "F";
		m_plant.m_rules[ 'F' ] = "FF-[-F+F+F]+[+F-F-F]";
		m_plant.m_rotation_degree = 22.5f;
		m_plant.create( m_iteration );
	}

	if ( ImGui::Button( "Plant4" ) )
	{
		m_plant.reset();
		m_plant.m_axiom = "X";
		m_plant.m_rules[ 'X' ] = "F[+X]F[-X]+X";
		m_plant.m_rules[ 'F' ] = "FF";
		m_plant.m_rotation_degree = 20.0f;
		m_plant.create( m_iteration );
	}

	if ( ImGui::Button( "Plant5" ) )
	{
		m_plant.reset();
		m_plant.m_axiom = "X";
		m_plant.m_rules[ 'X' ] = "F[+X][-X]FX";
		m_plant.m_rules[ 'F' ] = "FF";
		m_plant.m_rotation_degree = 25.7;
		m_plant.create( m_iteration );
	}

	if ( ImGui::Button( "Plant6" ) )
	{
		m_plant.reset();
		m_plant.m_axiom = "X";
		m_plant.m_rules[ 'X' ] = "F-[[X]+X]+F[+FX]-X";
		m_plant.m_rules[ 'F' ] = "FF";
		m_plant.m_rotation_degree = 22.5f;
		m_plant.create( m_iteration );
	}

	ImGui::End();
}


void MAIN_PANEL::draw( void )
{
	create_ui();

	GRAPHICS_UTILITY::push_translation_matrix( MATH_VECTOR_2D( 0.0f, -6.0f ) );

	m_plant.draw();

	GRAPHICS_UTILITY::pop__matrix();

}

void MAIN_PANEL::update( void )
{
}
