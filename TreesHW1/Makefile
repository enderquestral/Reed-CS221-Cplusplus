CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17
OPTFLAGS=-g
LDFLAGS=$(CXXFLAGS) $(OPTFLAGS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c $<

all: tree test_tree

use_tree: test-tree.o
	$(CXX) $(LDFLAGS) test-tree.o -o use_tree

test_tree: tree.cc tree.hh test-tree.cc
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c test-tree.cc -o test-tree

tree: tree.cc tree.hh test-tree.cc
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c tree.cc -o tree


clean:
	rm -f *.o
