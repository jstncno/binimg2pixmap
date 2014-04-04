#include "TLV.h"
#include "FilenameTLV.h"

FilenameTLV::FilenameTLV()
{
	type = 0x00;
	length = 0;
	filename = "";
}

FilenameTLV::FilenameTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = TLV::bytes2int(llength,rlength);
	filename = "";
	// TODO: read <length> bytes from byteStream into filename
}

void FilenameTLV::setFilename( std::queue<char> &byteStream )
{

}


std::string FilenameTLV::getFilename()
{
	return filename;
}