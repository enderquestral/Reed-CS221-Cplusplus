#include "deme.hh"
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
    //std::cout << "Test before" << "\n";
    Deme demographic(&cities, 20, 0.02);
    //std::cout << "Test after" << "\n";
    auto bestPtr = demographic.get_best();
    std::cout << "BEST CHROMOSOME STARTING OUT: " << bestPtr->get_fitness() << "\n";
    delete bestPtr;
    for (int i = 0; i < 5; ++i)
    {
        
        demographic.compute_next_generation();
        bestPtr = demographic.get_best();
        std::cout << "BEST CHROMOSOME AFTER GENERATION " << i <<": " << bestPtr->get_fitness() << "\n";
        delete bestPtr;
    }
    

    return 0;
}