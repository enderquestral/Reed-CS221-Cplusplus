/*
 * Declarations for Deme class to evolve a genetic algorithm for the
 * travelling-salesperson problem.  A deme is a population of individuals.
 */

#include "deme.hh"

// Generate a Deme of the specified size with all-random chromosomes.
// Also receives a mutation rate in the range [0-1].
Deme::Deme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
{
    srand(time(NULL));
    //std::vector<Chromosome*> holdPop;
    for(unsigned i = 0; i < pop_size; i++){
        pop_.push_back(new ClimbChromosome(cities_ptr));
    }
    cities_ptr_ = cities_ptr;
    pop_size_ = pop_size;
    mut_rate_ = mut_rate;

    //pop_.clear();
    //pop_.swap(holdPop);
    //holdPop.clear();

    
}

// Clean up as necessary
Deme::~Deme()
{
    for (unsigned i = 0; i < pop_size_; ++i)
    {   
        delete pop_[i];
    }
    pop_.clear();
}

// Evolve a single generation of new chromosomes, as follows:
// We select pop_size/2 pairs of chromosomes (using the select() method below).
// Each chromosome in the pair can be randomly selected for mutation, with
// probability mut_rate, in which case it calls the chromosome mutate() method.
// Then, the pair is recombined once (using the recombine() method) to generate
// a new pair of chromosomes, which are stored in the Deme.
// After we've generated pop_size new chromosomes, we delete all the old ones.
void Deme::compute_next_generation()
{
    std::vector<Chromosome*> newPop;
    for(unsigned i = 0; i < (pop_size_/2) - 1; i++)
    {
        auto parent1 = select_parent();
        auto parent2 = select_parent();
        while(parent1 == parent2)
        {
            parent2 = select_parent();
        }

        auto mutate = (rand() % 100) / 100.0; // Between 0 and .99
        if(mutate < mut_rate_)
        {
            parent1->mutate();
        }

        mutate = (rand() % 100) / 100.0;
        if(mutate < mut_rate_)
        {
            parent2->mutate();
        }

        auto children = parent1->recombine(parent2);
        newPop.push_back(std::move(children.first));
        newPop.push_back(std::move(children.second));
    }
    auto bestElem = get_best();
    newPop.push_back(bestElem->clone());
    newPop.push_back(std::move(bestElem->clone()));
    delete bestElem;

    for (unsigned i = 0; i < pop_size_; ++i)
    {   
        delete pop_[i];
    }
    pop_.clear();

    pop_.swap(newPop);
    newPop.clear();
    
}

// Return a copy of the chromosome with the highest fitness.
const Chromosome* Deme::get_best() const
{
    double mostFitScore = 0.0;
    auto mostFitElem = pop_[pop_.size()-1];
    for(auto e : pop_)
    {
        if(e->get_fitness() >= mostFitScore)
        {
            if (mostFitScore != 0.0)
            {
                delete mostFitElem;
            }
            mostFitScore = e->get_fitness();
            mostFitElem = e->clone(); //HATE THIS            
        }
    }
    const auto submitter = mostFitElem->clone();
    delete mostFitElem;
    return submitter;
}

// Randomly select a chromosome in the population based on fitness and
// return a pointer to that chromosome.
Chromosome* Deme::select_parent()
{
    double sum = 0.0;
    for(auto e : pop_)
    {
        sum += e->get_fitness();
    }
    auto randomLoc = rand() % int(sum);
    auto currentLoc = 0.0;
    auto currentElem = 0;
    for(int i = 0; currentLoc < randomLoc; i++)
    {
        currentLoc += pop_[i]->get_fitness();
        currentElem = i;
    }
    return pop_[currentElem];
}




