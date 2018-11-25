#include "chromosome.hh"
#include "cities.hh"
#include <iostream>
#include <fstream>

int main()
{

    auto filein = std::ifstream("five.tsv"); //use five.tsv as our route
    //recombine it, see if it's legit
    Cities cities;
    filein >> cities;
    Chromosome chromosome1(&cities);
    Chromosome chromosome2(&cities);

    std::cout << "CHROMOSOME 1: " << chromosome1.get_fitness() << "\n";
    std::cout << "CHROMOSOME 2: " << chromosome2.get_fitness() << "\n";
    auto twokids = chromosome1.recombine(&chromosome2);

    std::cout << "CHROMOSOME 1 AFT RECOMBINE: " << twokids.first->get_fitness() << "\n";
    std::cout << "CHROMOSOME 2 AFT RECOMBINE: " << twokids.second->get_fitness() << "\n";

    delete twokids.first;
    delete twokids.second;

    chromosome1.mutate();
    std::cout << chromosome1.get_fitness() << "\n";

    return 0;
}