#include "main_panel.h"
#include "imgui.h"
#include "graphics_color.h"

#include <string>
#include <vector>
#include <map>

void MAIN_PANEL::init( void )
{
}


std::string get_l_system( const int n,
						  const std::string& axiom,
						  const std::map<char, std::string >& rules )
{
	std::string current_string = axiom;

	for ( int i = 1; i < n; i++ )
	{
		std::string new_string;

		for ( auto c : current_string )
		{
			if ( rules.find( c ) != rules.end() )
			{
				new_string += rules.at( c );
			}
			else
			{
				new_string += c;
			}
		}
		current_string = new_string;
	}
	return current_string;
}


std::string get_l_system_recursive( const int n,
									const std::string& axiom,
									const std::map<char, std::string >& rules )
{
	std::string initial_string;

	if ( n == 0 )
	{
		return axiom;
	}
	else if ( n == 1 )
	{
		initial_string = axiom;
	}
	else
	{
		initial_string = get_l_system_recursive( n - 1, axiom, rules );
	}

	std::string new_string;

	for ( auto c : initial_string )
	{
		if ( rules.find( c ) != rules.end() )
		{
			new_string += rules.at( c );
		}
		else
		{
			new_string += c;
		}
	}
	return new_string;
}

void MAIN_PANEL::create_ui( void )
{
	static int f = 0;
	static int counter = 0;

	ImVec4 clear_color = ImVec4( 0.45f, 0.55f, 0.60f, 1.00f );

	ImGui::Begin( "Hello Tree" );

	std::map<char, std::string > rules;

	ImGui::SliderInt( "Itereation", &f, 0, 10 );

	rules[ 'F' ] = "FF-[-F+F+F]+[+F-F-F]";
	//rules[ 'F' ] = "FF";

	std::string axiom = "F";

	m_output_value = get_l_system( f, axiom, rules );

	auto display_value = m_output_value;

	for ( size_t i = display_value.size(); i-- > 0; )
	{
		char c = display_value[ i ];

		if ( c == 'X' )
		{
			display_value.erase( display_value.begin() + i );
		}
	}
	ImGui::Text( display_value.c_str() );

	ImGui::End();
}


void MAIN_PANEL::draw( void )
{
	create_ui();

	MATH_VECTOR_2D starting_point{ 0.0f, 0.0f };
	MATH_VECTOR_2D ending_point{ 0.0f, 0.1f };
	MATH_VECTOR_2D translation_vector{ 0.0f, -5.0f };

	std::vector< MATH_VECTOR_2D > saved_starting_states;
	std::vector< MATH_VECTOR_2D > saved_ending_states;

	starting_point.Translate( translation_vector );
	ending_point.Translate( translation_vector );

	float rotation = 22.5f;

	for ( auto c : m_output_value )
	{
		if ( c == 'F' )
		{
			auto colour = GRAPHICS_COLOR::White();
			GRAPHICS_UTILITY::draw_line( starting_point, ending_point, colour );


			MATH_VECTOR_2D direction = ending_point - starting_point;

			starting_point = ending_point;
			ending_point += direction;
		}

		else if ( c == '+' )
		{
			ending_point.Translate( starting_point * -1.0F );
			ending_point.RotateD( rotation );
			ending_point.Translate( starting_point );
		}

		else if ( c == '-' )
		{
			ending_point.Translate( starting_point * -1.0F );
			ending_point.RotateD( -rotation );
			ending_point.Translate( starting_point );
		}

		else if ( c == '[' )
		{
			saved_starting_states.push_back( starting_point );
			saved_ending_states.push_back( ending_point );
		}

		else if ( c == ']' )
		{
			starting_point = saved_starting_states[ saved_starting_states.size() - 1 ];
			ending_point = saved_ending_states[ saved_ending_states.size() - 1 ];

			saved_starting_states.pop_back();
			saved_ending_states.pop_back();
		}
	}
}

void MAIN_PANEL::update( void )
{
}
