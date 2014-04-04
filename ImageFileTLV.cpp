#include "TLV.h"
#include "ImageFileTLV.h"

ImageFileTLV::ImageFileTLV( char type, char llength, char rlength )
{
	type = type;
	length = TLV::bytes2int(llength,rlength);
}