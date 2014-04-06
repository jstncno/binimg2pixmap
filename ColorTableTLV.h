#include "TLV.h"
#include "ColorMappingTLV.h"

#ifndef ColorTableTLV_H
#define ColorTableTLV_H

class ColorTableTLV : public TLV
{
	public:
		ColorTableTLV();
		ColorTableTLV( char type, char llength, char rlength, std::queue<char> &byteStream ); // Take in 3 bytes as parameters
		~ColorTableTLV();

	private:
		std::map<char,ColorMappingTLV*> colorMappings;
};

#endif
