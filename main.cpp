#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <queue>
#include "TLV.h"
#include "ImageFileTLV.h"

using namespace std;

int main( int argc, char* argv[] )
{
	assert(argc>1);

	queue<char> byteStream;

	ifstream inputFile;
	inputFile.open(argv[1],ios::binary | ios::in);

	char byte;
	/*inputFile.read(&byte,sizeof(char));
	if( byte == 0x01 )
	{
		char buf[2];
		inputFile.read(&buf[0],sizeof(char));
		inputFile.read(&buf[1],sizeof(char));
		int length = 0;
		length = buf[0];
		length = (length << 8) | buf[1];
		cout << int(buf[0]) << " " << int(buf[1]) << ": " << length << endl;
	}*/
	while( inputFile.good() )
	{
		inputFile.read(&byte,sizeof(char));

		byteStream.push(byte);
	}

	char type, llength, rlength;
	type = byteStream.front();
	byteStream.pop();
	llength = byteStream.front();
	byteStream.pop();
	rlength = byteStream.front();
	byteStream.pop();

	ImageFileTLV img(byte,llength,rlength,byteStream);

	cout << img.getLength() << endl;

	return 0;
}
