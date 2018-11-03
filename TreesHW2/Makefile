CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17
OPTFLAGS=-g
LDFLAGS=$(CXXFLAGS) $(OPTFLAGS)

.cc.o:
	$(CXX) $(CXXFLAGS) -c $<

all: htree test_htree use_htree hforest test_hforest use_hforest

use_htree: test_htree.o
	$(CXX) $(LDFLAGS) test_htree.o -o use_htree

test_htree: htree.cc htree.hh test_htree.cc
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c test_htree.cc -o test_htree

htree: htree.cc htree.hh 
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c htree.cc -o htree


use_hforest: test_hforest.o
	#$(CXX) $(LDFLAGS) -c htree.cc -o htree
	$(CXX) $(LDFLAGS) test_hforest.o -o use_hforest


test_hforest: hforest.cc hforest.hh test_hforest.cc
	$(CXX) $(CXXFLAGS) $(OPTFLAGS)  test_hforest.cc -o test_hforest
	#$(CXX) $(LDFLAGS) htree.o

hforest: hforest.cc hforest.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c hforest.cc -o hforest

#ultimatefile: hforest.cc htree.cc #If removing the FLAGS works to combine two files...
#	$(CXX) hforest.cc htree.cc -o totalforest

clean:
	rm -f *.o 
