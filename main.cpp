#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <queue>
#include <iomanip>
#include <stdio.h>
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

	inputFile.close();

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
	string outputFileName = img->getFilename();

	FILE* outputFile;
	outputFile = fopen(outputFileName.c_str(),"w");

	//outputFile << outputFileName << "\n\n";
	//outputFile << numPixelsPerPixelRow << ' ' << numPixelRows << "\n\n";

	fprintf( outputFile, "%s\n\n", outputFileName.c_str() );
	fprintf( outputFile, "%d %d\n\n", numPixelsPerPixelRow, numPixelRows );

	queue<char> pixelKeys;
	map<char,unsigned char> pixels;
	char key;
	unsigned char R,G,B;
	for( int i = 0; i < numPixelRows; i++ )
	{
		img->queuePixelKeysAtRow(i,pixelKeys);
		for( int i = 0; i < numPixelsPerPixelRow; i++ )
		{
			key = pixelKeys.front();
			img->getPixelAtKey(key,pixels);
			pixelKeys.pop();
			R = pixels['R'];
			G = pixels['G'];
			B = pixels['B'];
			
			fprintf( outputFile, "%.2x %.2x %.2x", R, G, B );
			if( i < numPixelsPerPixelRow-1 )
				fprintf( outputFile, " " );
		}
		fprintf( outputFile, "\n" );
	}

	fprintf( outputFile, "\n" );
	fclose(outputFile);

	delete img;

	return 0;
}
