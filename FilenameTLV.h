#include "TLV.h"

#ifndef FilenameTLV_H
#define FilenameTLV_H

class FilenameTLV : public TLV
{
	public:
		FilenameTLV();
		FilenameTLV( char type, char llength, char rlength ); // Take in 3 bytes as parameters

	private:
		char* filename;
};

#endif
