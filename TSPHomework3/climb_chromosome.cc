
#include "climb_chromosome.hh"



void ClimbChromosome::mutate(){
//local hill climbing: searches for best solution in small local "neighborhood" of current chromosome.
    //Works as below (N cities, aka a chromosome with N genes):
/*1. evaluate the fitness of the current (original) chromosome.

2. Pick a random point p in the chromosome.

3. Swap the city at index p with the city at index p-1 and evaluate the resulting chromosome's fitness. 
If p==0, swap with the city at index N-1 instead of at index -1.

4. Swap the city at index p (from the original chromosome) with the city at index p+1 and evaluate the resulting chromosome's fitness. 
If p==N-1, swap with the city at index 0 instead of at index N. (hint: use modulus).

5. Find which of the three chromosomes (i.e., chromosomes from steps A, C, and D) 
produced the fittest ordering and choose that fittest chromosome as the resulting mutated chromosome.
*/
    std::uniform_int_distribution<int> distribution(0, order_.size() - 1); 

    auto origFitness = get_fitness(); //Evalue the fitness of the orig chromosome
    auto otherFitness1 = get_fitness();
    auto otherFitness2 = get_fitness();

    auto p = order_[distribution(generator_)]; //Pick a random point p in the chromosome

    //POINT 3
    if (p == 0){
        std::swap(order_[p], order_[order_.size()-1]);
        otherFitness1 = get_fitness();
        std::swap(order_[p], order_[order_.size()-1]);
    }
    else{
        std::swap(order_[p], order_[p-1]);
        otherFitness1 = get_fitness();
        std::swap(order_[p], order_[p-1]);
    }

    //POINT 4 ... USE MODULUS?
    /*std::swap(order_[p], order_[p+1 % order_.size()]);
    otherFitness2 = get_fitness();
    std::swap(order_[p], order_[p+1 % order_.size()]);*/
    if (p == order_.size()-1){
        std::swap(order_[p], order_[0]);
        otherFitness2 = get_fitness();
        std::swap(order_[p], order_[0]);
    }
    else{
        std::swap(order_[p], order_[p+1]);
        otherFitness2 = get_fitness();
        std::swap(order_[p], order_[p+1]);
    }

    //POINT 5 ...?
    //int maximum( int a, int b, int c ) { return maximum( maximun(a,b), c ) ; }

    auto maxvalue = std::max(origFitness, std::max(otherFitness1, otherFitness2));    
    if (maxvalue == origFitness)
    {
        return; //Current chromosome is most fit, no need to mutate it this way
    }
    else if (maxvalue == otherFitness1)
    {
        std::swap(order_[p], order_[order_.size()-1]); //alt chromosome 1 is more fit, mutate current chromosome to be like it
    }
    else if (maxvalue == otherFitness2)
    {
        std::swap(order_[p], order_[order_.size()-1]); //alt chromosome 2 is more fit, mutate current chromosome to be like it
    }

}


