# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
SRC = $(shell ls *.cc)

SOURCES = main.cpp
LINK = g++
CXX = g++
CXX_FLAGS = -c 


all: binimg2pixmap

binimg2pixmap: binimg2pixmap.o
	@echo making $@
	$(LINK) -ggdb -o $@ $^

binimg2pixmap.o: main.cpp
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb main.cpp

clean:
	$(RM) *.o binimg2pixmap

