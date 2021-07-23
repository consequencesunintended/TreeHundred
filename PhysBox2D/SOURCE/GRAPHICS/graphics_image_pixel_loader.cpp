#include "graphics_image_pixel_loader.h"

// -- LOCAL

// .. REFERENCES

#include "platform_file_reader.h"

// -- PUBLIC

// .. FUNCTIONS

void GRAPHICS_IMAGE_PIXEL_LOADER::LoadBMP( GRAPHICS_IMAGE_PIXEL_LOADER & image, const char * filename ) 
{
	int		dataOffset;
	int		headerSize;
	int		width;
	int		height;
	int		bytesPerRow;
	int		size;
	char	*pixels3;
	char	*pixels2;
	int		index_x;
	int		index_y;
	int		index_c;

	PLATFORM_FILE_READER  file_reader_engine;

	file_reader_engine.LoadFile( filename );
	file_reader_engine.SkipCharacters( 10 );

	dataOffset = file_reader_engine.readInt();
	headerSize = file_reader_engine.readInt();

	switch( headerSize ) 
	{
		case 40:
			width = file_reader_engine.readInt();
			height = file_reader_engine.readInt();
			break;
		case 12:
			width = file_reader_engine.readShort();
			height = file_reader_engine.readShort();
			break;
	}
	bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
	size = bytesPerRow * height;
	pixels3 = new char[ size ];
	file_reader_engine.SeekInBeginning(dataOffset);
	file_reader_engine.ReadCharacters( pixels3 , size);
	pixels2 = new char[ width * height * 3 ];

	for ( index_y = 0; index_y <= height - 1; index_y++ )
	{
		for ( index_x = 0; index_x <= width - 1; index_x++ )
		{
			for ( index_c = 0; index_c <= 2; index_c++ )
			{
				pixels2[ 3 * ( width * index_y + index_x ) + index_c ] = pixels3[ bytesPerRow * index_y + 3 * index_x + ( 2 - index_c ) ];
			}
		}
	}	
	file_reader_engine.CloseTheFile();
	image = GRAPHICS_IMAGE_PIXEL_LOADER( pixels2, width, height);
	delete [] pixels2;
	delete [] pixels3;
}

void GRAPHICS_IMAGE_PIXEL_LOADER::set_pixels( const char* other_pixels )
{
	pixels = new char[ width * height * 3 ];

	for ( int index_y = 0; index_y <= height - 1; index_y++ )
	{
		for ( int index_x = 0; index_x <= width - 1; index_x++ )
		{
			for ( int index_c = 0; index_c <= 2; index_c++ )
			{
				pixels[ 3 * (width * index_y + index_x) + index_c ] = other_pixels[ 3 * (width * index_y + index_x) + index_c ];
			}
		}
	}
}

std::vector< MATH_POINT_2D > GRAPHICS_IMAGE_PIXEL_LOADER::GetPositions( const char* bitmap )
{
	unsigned int					width;
	unsigned int					height;
	unsigned int					colour;
	GRAPHICS_IMAGE_PIXEL_LOADER		image;
	unsigned int					index_x;
	unsigned int					index_y;
	std::vector< MATH_POINT_2D >	point_table;

	GRAPHICS_IMAGE_PIXEL_LOADER::LoadBMP( image, bitmap );
	width = image.GetWidth();
	height = image.GetHeight();

	for ( index_y = 0; index_y <= height - 1; index_y++ )
	{
		for ( index_x = 0; index_x <= width - 1; index_x++ )
		{
			colour = image.GetPixels()[ 3 * (index_y * width + index_x) ];

			if ( colour != -1 )
			{
				point_table.push_back( MATH_POINT_2D( float( int( index_x - width / 2 ) ), float( int( index_y - height / 2 ) ) ) );
			}
		}
	}
	return point_table;
}









