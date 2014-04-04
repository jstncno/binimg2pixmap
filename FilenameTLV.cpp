#include "TLV.h"
#include "FilenameTLV.h"

FilenameTLV::FilenameTLV()
{
	type = 0x00;
	length = 0;
}

FilenameTLV::FilenameTLV( char type, char llength, char rlength )
{
	type = type;
	length = TLV::bytes2int(llength,rlength);
}