#include "TLV.h"
#include "ImageFileTLV.h"
#include "FilenameTLV.h"
#include "ColorTableTLV.h"

ImageFileTLV::ImageFileTLV()
{
	type = 0x01;
	length = 0;
}

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
	if( t == 0x02 )
		filename = new FilenameTLV(t,lhs,rhs,byteStream);
	else if( t == 0x03 )
		colorTable = new ColorTableTLV(t,lhs,rhs,byteStream);
}

ImageFileTLV::~ImageFileTLV()
{
	delete filename;
	delete colorTable;
	delete pixelData;
}

std::string ImageFileTLV::getFilename()
{
	return filename->getFilename();
}