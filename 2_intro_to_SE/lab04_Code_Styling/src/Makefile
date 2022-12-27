CXX=g++
CXXFLAGS = -std=c++17
ROOT_DIR := $(shell git rev-parse --show-toplevel)
-include $(ROOT_DIR)/config/settings
-include $(DEP_DIR)/env

LIBDIRS = -L../lib/routing/build 		# get reference of other files from /lib/routing/build
LIBS = -lrouting						# namespace "routing"
INCLUDES = -I../lib/routing/include		# header files
SOURCES = $(shell find . -name '*.cc')			# find the files that ends with .cc
OBJFILES = $(addprefix ./, $(SOURCES:.cc=.o))	# call object file target to compile

all: routing pathFinding_app

routing: 
	cd ../lib/routing; make; 

%_app: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(LIBDIRS) $^ $(LIBS) -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

clean:
	rm -f *.o *_app *.png
	cd ../lib/routing; make clean; 
