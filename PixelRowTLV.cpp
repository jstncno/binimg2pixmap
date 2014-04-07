#include "TLV.h"
#include "PixelRowTLV.h"

PixelRowTLV::PixelRowTLV()
{
	type = 0x06;
	length = 0;
}

PixelRowTLV::PixelRowTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);

	for( int i = 0; i < length; i++ )
	{
		values.push(byteStream.front());
		byteStream.pop();
	}

	char t, lhs, rhs;

	while( !values.empty() )
	{
		t = values.front();
		values.pop();
		lhs = values.front();
		values.pop();
		rhs = values.front();
		values.pop();

		switch( t )
		{
			case 0x07: // if pixel-group
				pixels.push_back(new PixelGroupTLV(t,lhs,rhs,values));
				break;
			case 0x08: // if single-pixel
				pixels.push_back(new SinglePixelTLV(t,lhs,rhs,values));
				break;
			default:
				break;
		}

		for( int i = 0; i < pixels.size(); i++ )
			numPixels += pixels[i]->getNumPixels();

	}
}

PixelRowTLV::~PixelRowTLV()
{
	for( int i = 0; i < pixels.size(); i++ )
		delete pixels[i];
}

char PixelRowTLV::getType()
{
	return type;
}

int PixelRowTLV::getNumPixels()
{
	return numPixels;
}

std::vector<TLV*> PixelRowTLV::getPixels()
{
	return pixels;
}