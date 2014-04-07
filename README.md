#binimg2pixmap
##Binary image to pixmap converter
A C++ program that takes in a binary image file (encoded as a byte stream, composed of a set of nested Type-Length-Value (TLV) structures) and converts it to an ASCII bitmap file.

##Compile
Download all source files and `make`

##Usage
`binimg2pixmap <binary input file>`

#Input File
The input file must be a binary image file, encoded as a byte stream, composed of a set of nested Type-Length-Value (TLV) structures. The TLV structure is defined as:

**[type: 1 byte] [length: 2 bytes] [value: <length> bytes]**

#Output File
The output file will be a simple bitmap, held in a plain-text, ASCII file format.

```
<filename>\n
<number of pixels per row> <number of rows in image>\n \n
<pixel row #1>\n
<pixel row #2>\n
...
<pixel row #n>\n
\n
```