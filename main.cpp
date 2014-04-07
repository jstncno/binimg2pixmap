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

	cout << img->getFilename() << "\n\n";
	cout << img->getNumPixelsPerPixelRow() << ' ' << img->getNumPixelRows() << "\n\n";

	vector<PixelRowTLV*> pixelRows = img->getPixelRows();
	for( int i = 0; i < pixelRows.size(); i++ ) // for each pixel row
	{
		std::vector<TLV*> pixels = pixelRows[i]->getPixels();
		for( int i = 0; i < pixels.size(); i++ ) // for each pixel in the row
		{
			char t, key, num;
			t = pixels[i]->getType();
			switch( t )
			{
				case 0x07:
					cout << "PixelGroup ";
					break;
				case 0x08:
					cout << "SinglePixel ";
					break;
				default:
					cout << "test ";
					break;
			}
		}
		cout << '\n';
	}
	cout << endl;

	delete img;

	return 0;
}
