#include "tournament_deme.hh"
#include <algorithm>



/*TournamentDeme::~TournamentDeme()
{
    for (unsigned i = 0; i < pop_size_; ++i)
    {   
        delete pop_[i];
    }
    pop_.clear();
}*/

/*
The new selection operator we’ll try is called “tournament selection” because it pits candidate parents against each other 
to determine which parent gets to recombine. It works as follows:

A.Select P parents at random, where P is a constant power of two that you choose (no bigger than the population size).

B.Take the first pair in the set of P parents and discard the parent with the lower fitness of the two.

C. Do the same for the next pair, and so forth. You should have P/2 parents in the resulting set.

D. Repeat steps B--C until you’re left with only one parent.

*/
Chromosome* TournamentDeme::select_parent()
{
    std::vector<Chromosome*> parentPool;
    std::uniform_int_distribution<int> distribution(0, pop_.size() - 1);


    unsigned tempvalue = pow(2, distribution(generator_));

    //2 ** (rand() % int(pop_.size()));

    while(tempvalue > pop_.size()){
        tempvalue = pow(2, distribution(generator_));
    }

    const auto poolTotal = tempvalue;

    for (unsigned i = 0; i < poolTotal; ++i)
    {
        //auto parent1 = Deme::select_parent();
        auto parent1 = pop_[distribution(generator_)]; //Not selecting a parent at random? 
        if (std::find(parentPool.cbegin(), parentPool.cend(), parent1) != parentPool.end()) //if parent1 is in the vector of parentpool
        {
            i--;
        }
        else{
            parentPool.push_back(parent1);
        }
    }
    while(parentPool.size() != 1){ //bad idea?
        std::vector<Chromosome*> tempVector;
        //auto poolEnd = parentPool.end();
        //auto placeholderLength = tempVector.size();
        for (unsigned j = 0; j < parentPool.size()/2; j+=2)
        {
            auto tempparent1 = parentPool[j];
            auto tempparent2 = parentPool[j+1];
            // std::cout<< "GOT TO THIS POINT!" << "\n"; //GETS TO THIS POINT TWICE?
            if (tempparent1->get_fitness() < tempparent2->get_fitness())
            {
                tempVector.push_back(tempparent2);
            }
            else{
                tempVector.push_back(tempparent1); //clone?
            }
        }
        //parentPool = tempVector;
        parentPool.swap(tempVector);
        //tempVector.clear();
    }

    return parentPool[0];
    
}
