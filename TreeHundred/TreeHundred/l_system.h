#pragma once

#include "math_vector_2d.h"
#include "graphics_utility.h"
#include <string>
#include <vector>
#include <map>

class L_SYSTEM
{
	public:

	std::string get_genetic_code( const int iteration );
	void create( const int iteration );
	void draw();
	void reset()
	{
		m_rules.clear();
	}


	std::string						m_axiom;
	std::map<char, std::string >	m_rules;
	float							m_rotation_degree{ 25.0f };
	std::vector< MATH_VECTOR_2D >	m_draw_lines;
	float							m_growth_rate{ 0.1f };
};