#include "TLV.h"
#include "ImageFileTLV.h"
#include "FilenameTLV.h"

ImageFileTLV::ImageFileTLV()
{}

ImageFileTLV::ImageFileTLV( char type, char llength, char rlength )
{
	type = type;
	length = TLV::bytes2int(llength,rlength);
	values.push_back(new FilenameTLV());
}

ImageFileTLV::~ImageFileTLV()
{
	for( int i = 0; i < values.size(); i++ )
	{
		delete values[i];
	}
}