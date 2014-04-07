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
/*
	ASSERT macro definition taken from
	http://stackoverflow.com/questions/3767869/adding-message-to-assert
*/
#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": \n" << message << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { std::exit(EXIT_FAILURE); } while (false)
#endif

int main( int argc, char* argv[] )
{
	string errorMessage = "Error: no input file detected\nusage: binimg2pixmap <binary input file>\n";
	ASSERT(argc>1,errorMessage);

	queue<char> byteStream;

	ifstream inputFile;
	inputFile.open(argv[1],ios::binary | ios::in);

	if( inputFile.is_open() )
	{

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
		string outputFileName = img->getFilename();

		FILE* outputFile;
		outputFile = fopen(outputFileName.c_str(),"w");

		if( outputFile == NULL ) perror("Error creating output\n");

		else
		{
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
		}
		delete img;
	}
	else
			perror("Error opening file\n");

	inputFile.close();


	return 0;
}
