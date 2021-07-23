#pragma once

#include "graphics_utility.h"
#include <string>


class MAIN_PANEL : public PANEL_INTERFACE
{
	public:
	void init( void );
	void create_ui( void );
	void draw( void );
	void update( void );

	private:
	std::string m_output_value;
};