#include "cities.hh"
#include <iostream>
#include <fstream>

int main(/*int argc, char const *argv[]*/)
{
    std::string fileName  = "";
    
    /*if(argc == 2){ //if there is ONLY the .cpp file and the input file
        fileName = argv[1]; //input file name
    }
    else{
        std::cout << "please input like this: ./cppfile InputFile \n";
        return 1; //too many or two few files
    } */


    auto fin = std::ifstream("five.tsv");
    Cities cities;
    fin >> cities;
    auto citySize = cities.get_vectorOfCities_().size();
    std::cout << cities.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n";
    //cities2 = cities.reorder({ 3, 2, 4, 0, 1 });
    std::cout << cities.total_path_distance({ 3, 2, 4, 0, 1 }) << "\n";
    Cities::permutation_t randPerm = cities.random_permutation(citySize);
    std::cout << cities.total_path_distance(randPerm) << "\n";

    //std::cout << cities2.total_path_distance({ 0, 1, 2, 3, 4 }) << "\n";

    //std::cout << cities.reorder({ 3, 2, 4, 0, 1 }) << "\n";

    //CONTINUE...
    return 0;
}