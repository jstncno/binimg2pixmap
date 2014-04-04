#include "TLV.h"

#ifndef FilenameTLV_H
#define FilenameTLV_H

class FilenameTLV : public TLV
{
	public:
		FilenameTLV();
		FilenameTLV( char type, char llength, char rlength ); // Take in 3 bytes as parameters
		void setFilename( std::queue<char> &byteStream );
		std::string getFilename();

	private:
		std::string filename;
};

#endif