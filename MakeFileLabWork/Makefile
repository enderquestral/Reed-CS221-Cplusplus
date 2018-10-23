CXX=c++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17
OPTFLAGS=-g
LDFLAGS=$(CXXFLAGS) $(OPTFLAGS)


.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

all: %-stats.wc	highest
	echo "hello world"

use_highest: highest.o
	$(CXX) $(LDFLAGS) highest.o -o use_highest
	#use make use_highest to create a proper use_highest executable

highest: highest.cpp highest.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c highest.cpp -o highest.o

%-stats.wc: %.txt
	wc $< > $<-stats.wc
	#type make another-stats.wc


clean:
	rm -f *.o
	rm -f *-stats.wc