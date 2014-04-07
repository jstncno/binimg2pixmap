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

	while( inputFile.good() )
	{
		inputFile.read(&byte,sizeof(char));
		if( !inputFile.eof() )
			byteStream.push(byte);
	}

	char type, llength, rlength;
	type = byteStream.front();
	byteStream.pop();
	llength = byteStream.front();
	byteStream.pop();
	rlength = byteStream.front();
	byteStream.pop();

	ImageFileTLV* img = new ImageFileTLV(type,llength,rlength,byteStream);

	cout << img->getLength() << endl << img->getFilename() << endl;
	cout << "# of Pixels per PixelRow: " << img->getNumPixelsPerPixelRow() << endl;
	cout << "# of PixelRows: " << img->getNumPixelRows() << endl;

	delete img;

	return 0;
}
