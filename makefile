CXX = g++
CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')
CXXFLAGS = -O0 -g3 -std=c++14
All: all
all: main

main: main.cpp Allocator.h
	$(CXX) $(CXXFLAGS) main.cpp -o main
#Allocator.o: Allocator.cpp Allocator.h
#	$(CXX) $(CXXFLAGS) -c Allocator.cpp -o Allocator.o
deepclean: 
	rm -f *~ *.o *.gch main *.exe *.stackdump 

clean:
	-rm -f *~ *.o *.gch *.stackdump
