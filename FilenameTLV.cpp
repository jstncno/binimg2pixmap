#include "TLV.h"
#include "FilenameTLV.h"

FilenameTLV::FilenameTLV()
{
	type = 0x02;
	length = 0;
	filename = "";
}

FilenameTLV::FilenameTLV( char type, char llength, char rlength, std::queue<char> &byteStream )
{
	type = type;
	length = bytes2int(llength,rlength);
	filename = "";
	// read <length> bytes from byteStream into filename
	for( int i = 0; i < length; i++ )
	{
		filename += byteStream.front();
		byteStream.pop();
	}
}

void FilenameTLV::setFilename( std::queue<char> &byteStream )
{

}


std::string FilenameTLV::getFilename()
{
	return filename;
}