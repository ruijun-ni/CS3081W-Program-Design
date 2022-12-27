# The CXXFLAGS variable sets compile flags for g++:
#  -g          compile with debug information
#  -std=c++11  use the c++ standard language definition

CXX=g++
CXXFLAGS = -std=c++11 -g

run: main.o Duck.o	
	$(CXX) $(CXXFLAGS) main.o Duck.o -o run

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

duck.o: Duck.cc Duck.h
	$(CXX) $(CXXFLAGS) -c Duck.cc -o Duck.o

clean:
	rm -f *.o run