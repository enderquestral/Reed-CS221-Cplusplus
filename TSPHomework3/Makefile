CXX=g++-8
CXXFLAGS=-Wall -Wextra -pedantic -std=c++17 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:   chromosome_test tsp test_deme test_tdeme

chromosome_test: chromosome_test.o chromosome.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_deme: test_deme.o deme.o chromosome.o cities.o climb_chromosome.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_tdeme: test_tdeme.o deme.o chromosome.o cities.o climb_chromosome.o tournament_deme.o
	$(CXX) $(LDFLAGS) -o $@ $^

tsp: tsp.o chromosome.o deme.o tournament_deme.o cities.o climb_chromosome.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o tsp


test: all
	#./chromosome_test
	#./test_tdeme
	#./test_deme
	./tsp "challenge.tsv" 10 0.1