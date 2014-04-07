#include "TLV.h"

#ifndef FilenameTLV_H
#define FilenameTLV_H

class FilenameTLV : public TLV
{
	public:
		FilenameTLV();
		FilenameTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		void setFilename( std::queue<char> &byteStream );
		std::string getFilename();
		char getType();

	private:
		std::string filename;
};

#endif
