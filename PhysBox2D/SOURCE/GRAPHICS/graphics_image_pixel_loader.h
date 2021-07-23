#pragma once


// -- LOCAL

// .. REFERENCES

#include "platform_file_reader.h"
#include "math_point_2d.h"
#include <vector>

// -- GLOBAL

// .. TYPES

class GRAPHICS_IMAGE_PIXEL_LOADER
{
	// -- PUBLIC
	public:

	// .. CONSTRUCTORS

	GRAPHICS_IMAGE_PIXEL_LOADER( void ) = default;

	// ~~

	virtual ~GRAPHICS_IMAGE_PIXEL_LOADER( void )
	{
		delete[] pixels;
	}

	// ~~

	void set_pixels( const char* other_pixels );


	// ~~

	GRAPHICS_IMAGE_PIXEL_LOADER( const GRAPHICS_IMAGE_PIXEL_LOADER& other ) : width( other.width ), height( other.height )
	{
		set_pixels( other.pixels );
	}


	// ~~

	GRAPHICS_IMAGE_PIXEL_LOADER( const char* other_pixels, const int w, const int h ) : width( w ), height( h )
	{
		set_pixels( other_pixels );
	}

	// .. OPERATORS

	GRAPHICS_IMAGE_PIXEL_LOADER& operator=( const GRAPHICS_IMAGE_PIXEL_LOADER& other )
	{
		width = other.width;
		height = other.height;

		set_pixels( other.pixels );

		return *this;
	}

	static std::vector< MATH_POINT_2D > GetPositions( const char* bitmap );

	// .. ACCESSORS

	int GetHeight( void )
	{
		return height;
	}

	// ~~

	int GetWidth( void )
	{
		return width;
	}

	// ~~

	const char* GetPixels( void )
	{
		return pixels;
	}

	// .. FUNCTIONS

	static void LoadBMP( GRAPHICS_IMAGE_PIXEL_LOADER& image, const char* filename );

	// -- PRIVATE

	private:

	// .. ATTRIBUTES

	char* pixels{ nullptr };
	int  width{ 0 };
	int  height{ 0 };
};
