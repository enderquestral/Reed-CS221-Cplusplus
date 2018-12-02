/*
 * Implementation for Chromosome class
 */

#include <algorithm>
#include <cassert>
#include <random>
#include <cfloat>
#include <time.h>
#include <iostream>

#include "chromosome.hh"

//////////////////////////////////////////////////////////////////////////////
// Generate a completely random permutation from a list of cities
Chromosome::Chromosome(const Cities* cities_ptr)
  : cities_ptr_(cities_ptr),
    order_(random_permutation(cities_ptr->size()))
{
  assert(is_valid());
  fitness_ = get_fitness();
  srand(time(NULL)); //make it so that the random changes every time
}

//////////////////////////////////////////////////////////////////////////////
// Clean up as necessary
Chromosome::~Chromosome() {
  assert(is_valid());
}

//////////////////////////////////////////////////////////////////////////////
// Perform a single mutation on this chromosome
void Chromosome::mutate() {
  // Add your implementation here
    //simply pick two points in the permutation at random and swap their values.
    //FIX, MAKE SURE THE NUMBERS ARE NOT THE SAME
    auto randomplace1 = rand() % order_.size();
    auto randomplace2 = rand() % order_.size();
    while (randomplace1 == randomplace2){
        randomplace2 = rand() % order_.size();
    }
    std::iter_swap(order_.begin()+randomplace1, order_.begin()+randomplace2); //swaps point1 value with point2 value and vice versa
    assert(is_valid());
}

//////////////////////////////////////////////////////////////////////////////
// Return a pair of offsprings by recombining with another chromosome
// Note: this method allocates memory for the new offsprings
std::pair<Chromosome*, Chromosome*>
Chromosome::recombine(const Chromosome* other)
{
    assert(is_valid());
    assert(other->is_valid());
  //FIX
  //choose range with numbers that are not the same, use create_crossover_child call twice
    unsigned randomplace1 = rand() % order_.size()-1;
    unsigned randomplace2 = rand() % order_.size();
    while(randomplace1 >= order_.size()){
        randomplace1 = rand() % order_.size()-1;
    }
    while (randomplace1 >= randomplace2){
        randomplace2 = rand() % order_.size();
    }
    auto child1 = create_crossover_child(this, other, randomplace1, randomplace2);
    auto child2 = create_crossover_child(other, this, randomplace1, randomplace2); 
    std::pair<Chromosome*, Chromosome*> newChildren;
    newChildren.first = child1;
    newChildren.second = child2;
    return newChildren;
}

//////////////////////////////////////////////////////////////////////////////
// For an ordered set of parents, return a child using the ordered crossover.
// The child will have the same values as p1 in the range [b,e),
// and all the other values in the same order as in p2.
Chromosome*
Chromosome::create_crossover_child(const Chromosome* p1, const Chromosome* p2,
                                   unsigned b, unsigned e) const
{
  Chromosome* child = p1->clone();

  // We iterate over both parents separately, copying from parent1 if the
  // value is within [b,e) and from parent2 otherwise
  unsigned i = 0, j = 0;

  for ( ; i < p1->order_.size() && j < p2->order_.size(); ++i) {
    if (i >= b and i < e) {
      child->order_[i] = p1->order_[i];
    }
    else { // Increment j as long as its value is in the [b,e) range of p1
      while (p1->is_in_range(p2->order_[j], b, e)) {
        ++j;
      }
      assert(j < p2->order_.size()); //ISSUE
      child->order_[i] = p2->order_[j];
      j++;
    }
  }
  assert(child->is_valid()); //ISSUE
  return child;
}

// Return a positive fitness value, with higher numbers representing
// fitter solutions (shorter total-city traversal path).
double Chromosome::get_fitness() const {

    /*
    Implement the GET_fitness() method. 
    You will need to figure out how to calculate a measure of fitness for the permutation 
    currently stored in the my_order member; the fitness value will be different when different 
    permutations are stored in my_order. 

    Your measure needs to insure that “good” (more fit) values are higher than less fit values. 
    The shorter the overall distance to traverse the cities, the better the fitness and the higher the score.
    */

    //fitness needs to by globally comprable
    //all have to be positive FITNESS
    //MAXIMUM DOUBLE / NUMBER OF CITIES, then subtract distances?
    auto largestNum = 1000000 / cities_ptr_->size();
    auto fitnesstemp = cities_ptr_->total_path_distance(order_);
    return largestNum/fitnesstemp;
}

// A chromsome is valid if it has no repeated values in its permutation,
// as well as no indices above the range (length) of the chromosome.
// We implement this check with a sort, which is a bit inefficient, but simple
bool Chromosome::is_valid() const {
    // Add your implementation here
    Cities::permutation_t placeholder = order_;
    std::sort(placeholder.begin(), placeholder.end());
    for (unsigned i = 0; i < placeholder.size(); ++i)
    {   
        if(placeholder[i] != i){
            return false;
        }
        if(i > placeholder.size()){ //no indicies above the ranve of the chromosome.
            return false;
        }
    }
    return true;
}

// Find whether a certain value appears in a given range of the chromosome.
// Returns true if value is within the specified the range specified
// [begin, end) and false otherwise.
bool Chromosome::is_in_range(unsigned value, unsigned begin, unsigned end) const {
    for(unsigned i = begin; i < end; i++)
    {
      if(value == order_[i])
      {
        return true;
      }
    }
    return false;
}
