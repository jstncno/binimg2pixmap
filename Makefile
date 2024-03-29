# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
SRC = $(shell ls *.cc)

SOURCES = main.cpp
LINK = g++
CXX = g++
CXX_FLAGS = -c 


all: binimg2pixmap

binimg2pixmap: binimg2pixmap.o TLV.o ImageFileTLV.o FilenameTLV.o ColorTableTLV.o ColorMappingTLV.o PixelDataTLV.o PixelRowTLV.o PixelGroupTLV.o SinglePixelTLV.o
	@echo making $@
	$(LINK) -ggdb -o $@ $^

binimg2pixmap.o: main.cpp TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb main.cpp

TLV.o: TLV.cpp TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb TLV.cpp

ImageFileTLV.o: ImageFileTLV.cpp ImageFileTLV.h FilenameTLV.h ColorTableTLV.h PixelDataTLV.h PixelRowTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb ImageFileTLV.cpp

FilenameTLV.o: FilenameTLV.cpp FilenameTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb FilenameTLV.cpp

ColorTableTLV.o: ColorTableTLV.cpp ColorTableTLV.h ColorMappingTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb ColorTableTLV.cpp

ColorMappingTLV.o: ColorMappingTLV.cpp ColorMappingTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb ColorMappingTLV.cpp

PixelDataTLV.o: PixelDataTLV.cpp PixelDataTLV.h PixelRowTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb PixelDataTLV.cpp

PixelRowTLV.o: PixelRowTLV.cpp PixelRowTLV.h PixelGroupTLV.h SinglePixelTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb PixelRowTLV.cpp

PixelGroupTLV.o: PixelGroupTLV.cpp PixelGroupTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb PixelGroupTLV.cpp

SinglePixelTLV.o: SinglePixelTLV.cpp SinglePixelTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb SinglePixelTLV.cpp

clean:
	$(RM) *.o binimg2pixmap

