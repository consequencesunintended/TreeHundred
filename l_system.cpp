#include "l_system.h"
#include <map>

std::string L_SYSTEM::get_genetic_code( const int iteration )
{
	std::string initial_string;

	if ( iteration == 0 )
	{
		return m_axiom;
	}
	else if ( iteration == 1 )
	{
		initial_string = m_axiom;
	}
	else
	{
		initial_string = get_genetic_code( iteration - 1 );
	}

	std::string new_string;

	for ( auto c : initial_string )
	{
		if ( m_rules.find( c ) != m_rules.end() )
		{
			new_string += m_rules.at( c );
		}
		else
		{
			new_string += c;
		}
	}

	return new_string;
}

void L_SYSTEM::create( const int iteration )
{
	m_draw_lines.clear();

	const auto& code = get_genetic_code( iteration );

	MATH_VECTOR_2D starting_point{ 0.0f, 0.0f };
	MATH_VECTOR_2D ending_point{ 0.0f, m_growth_rate };

	std::vector< MATH_VECTOR_2D > saved_starting_states;
	std::vector< MATH_VECTOR_2D > saved_ending_states;

	for ( auto c : code )
	{
		if ( c == 'F' )
		{
			m_draw_lines.push_back( starting_point );
			m_draw_lines.push_back( ending_point );

			MATH_VECTOR_2D direction = ending_point - starting_point;

			starting_point = ending_point;
			ending_point += direction;
		}

		else if ( c == '+' )
		{
			ending_point.Translate( starting_point * -1.0F );
			ending_point.RotateD( m_rotation_degree );
			ending_point.Translate( starting_point );
		}

		else if ( c == '-' )
		{
			ending_point.Translate( starting_point * -1.0F );
			ending_point.RotateD( -m_rotation_degree );
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

void L_SYSTEM::draw()
{
	for ( size_t i = 0; i < m_draw_lines.size(); i += 2 )
	{
		GRAPHICS_UTILITY::draw_line( m_draw_lines[ i ], m_draw_lines[ i + 1 ] );
	}
}
