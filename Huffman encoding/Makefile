CXX=g++-8
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  test_bitio test_hforest test_huffman  encoder decoder #test_tree

test_bitio: bitio.o test_bitio.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_tree: test_htree.o htree.o
	$(CXX) $(LDFLAGS) -o $@ $^
#Commented out instances of test_tree as it didn't like trying to only work with htree.hh instead of htree.cc.

test_huffman: test_huffman.o huffman.o hforest.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_hforest: test_hforest.o hforest.o
	$(CXX) $(LDFLAGS) -o $@ $^

encoder: encoder.o bitio.o huffman.o hforest.o
	$(CXX) $(LDFLAGS) -o $@ $^

decoder: decoder.o  bitio.o huffman.o hforest.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o test_bitio encoder decoder
	rm  -rf *.comp

test: all
	./test_tree
	./test_hforest
	./test_huffman
	./test_bitio
