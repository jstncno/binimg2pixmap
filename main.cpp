#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <assert.h>
#include "TLV.h"
#include "ImageFileTLV.h"

using namespace std;

int main( int argc, char* argv[] )
{
	assert(argc>1);

	ifstream inputFile;
	inputFile.open(argv[1],ios::binary | ios::in);

	char byte;
	inputFile.read(&byte,sizeof(char));
	if( byte == 0x01 )
	{
		char buf[2];
		inputFile.read(&buf[0],sizeof(char));
		inputFile.read(&buf[1],sizeof(char));
		int length = 0;
		length = buf[0];
		length = (length << 8) | buf[1];
		cout << int(buf[0]) << " " << int(buf[1]) << ": " << length << endl;
	}
/*	while( inputFile.good() )
	{
		inputFile.read(&byte,sizeof(char));

		switch( byte )
		{
			case 0x01:
				cout << "0x01\n";
				break;
			case 0x02:
				cout << "0x02\n";
				break;
			case 0x03:
				cout << "0x03\n";
				break;
			default:
				break;
		}
	}
*/
	return 0;
}
