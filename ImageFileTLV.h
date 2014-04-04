#include "TLV.h"
#include "FilenameTLV.h"
#include "ColorTableTLV.h"

#ifndef ImageFileTLV_H
#define ImageFileTLV_H

class ImageFileTLV : public TLV
{
	public:
		ImageFileTLV();
		ImageFileTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~ImageFileTLV();

		std::string getFilename();
	private:
		FilenameTLV* filename;
		ColorTableTLV* colorTable;
};

#endif
