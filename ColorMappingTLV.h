#include "TLV.h"

#ifndef ColorMappingTLV_H
#define ColorMappingTLV_H

class ColorMappingTLV : public TLV
{
	public:
		ColorMappingTLV();
		ColorMappingTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~ColorMappingTLV();

	private:
		char key,R,G,B;
		std::queue<char> values;
};

#endif
