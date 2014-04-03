# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
SRC = $(shell ls *.cc)

SOURCES = main.cpp
LINK = g++
CXX = g++
CXX_FLAGS = -c 


all: testLinkedString handle_signals my_shell binimage2pixmap

binimage2pixmap:

testLinkedString: testLinkedString.o String.o
	@echo making $@
	$(LINK) -ggdb -o $@ $^

testLinkString.o: testLinkedString.cpp String.h 
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb testString.cpp

String.o: String.cpp String.h
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb String.cpp

handle_signals: handle_signals.o
	@echo making $@
	$(LINK) -ggdb -o $@ $^

handle_signals.o: handle_signals.cpp
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb handle_signals.cpp

my_shell: my_shell.o
	@echo making $@
	$(LINK) -ggdb -o $@ $^

my_shell.o: my_shell.cpp
	@echo making $@
	$(CXX) $(CXX_FLAGS) -o $@ -ggdb my_shell.cpp


clean:
	$(RM) *.o testLinkedString handle_signals my_shell

strip: 
	strip --strip-debug testLinkedString handle_signals my_shell

print:
	cat String.cpp
