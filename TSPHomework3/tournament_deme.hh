#pragma once
#include "deme.hh"
#include "chromosome.hh"
#include "cities.hh"
#include "climb_chromosome.hh"

#include <random>
#include <time.h>
#include <math.h>

/*
This class inherits from the Deme class and overrides whatever is necessary in your judgement 
for your class to replace the parent selection algorithm. 

It can use either Chromosome or ClimbChromosome: experiment with both when you're done and pick the best one.
*/


/*
The new selection operator we’ll try is called “tournament selection” because it pits candidate parents against each other 
to determine which parent gets to recombine. It works as follows:

A.Select P parents at random, where P is a constant power of two that you choose (no bigger than the population size).

B.Take the first pair in the set of P parents and discard the parent with the lower fitness of the two.

C. Do the same for the next pair, and so forth. You should have P/2 parents in the resulting set.

D. Repeat steps B--C until you’re left with only one parent.


*/
class TournamentDeme : public Deme
{
public:
    TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
    : Deme(cities_ptr, pop_size, mut_rate)
    {}

    //virtual ~TournamentDeme();

    //override slect parent

protected:
    Chromosome* select_parent() override;
    
};