#include "TLV.h"
#include "ImageFileTLV.h"
#include "FilenameTLV.h"

ImageFileTLV::ImageFileTLV()
{}

ImageFileTLV::ImageFileTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = TLV::bytes2int(llength,rlength);
	char t, lhs, rhs;
	t = byteStream.front();
	byteStream.pop();
	lhs = byteStream.front();
	byteStream.pop();
	rhs = byteStream.front();
	byteStream.pop();
	values.push_back(new FilenameTLV(t,lhs,rhs));
}

ImageFileTLV::~ImageFileTLV()
{
	for( int i = 0; i < values.size(); i++ )
	{
		delete values[i];
	}
}