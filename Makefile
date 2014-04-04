# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
SRC = $(shell ls *.cc)

SOURCES = main.cpp
LINK = g++
CXX = g++
CXX_FLAGS = -c 


all: binimg2pixmap

binimg2pixmap: binimg2pixmap.o TLV.o ImageFileTLV.o FilenameTLV.o
	@echo making $@
	$(LINK) -ggdb -o $@ $^

binimg2pixmap.o: main.cpp TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb main.cpp

TLV.o: TLV.cpp TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb TLV.cpp

ImageFileTLV.o: ImageFileTLV.cpp ImageFileTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb ImageFileTLV.cpp

FilenameTLV.o: FilenameTLV.cpp FilenameTLV.h TLV.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb FilenameTLV.cpp

clean:
	$(RM) *.o binimg2pixmap

