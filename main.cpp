#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <queue>
#include "TLV.h"
#include "ImageFileTLV.h"

using namespace std;

string byte2string(char byte)
{

}

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
	int numPixelsPerPixelRow = img->getNumPixelsPerPixelRow();
	int numPixelRows = img->getNumPixelRows();

	cout << img->getFilename() << "\n\n";
	cout << numPixelsPerPixelRow << ' ' << numPixelRows << "\n\n";

	queue<char> pixelKeys;
	map<char,char> pixels;
	char key;
	string R,G,B;
	for( int i = 0; i < numPixelRows; i++ )
	{
		img->queuePixelKeysAtRow(i,pixelKeys);
		for( int i = 0; i < numPixelsPerPixelRow; i++ )
		{
			key = pixelKeys.front();
			img->getPixelAtKey(key,pixels);
			pixelKeys.pop();
			//cout << static_cast<int>(pixels['R']) << " ";
		}
		cout << '\n';
	}

	delete img;

	return 0;
}
