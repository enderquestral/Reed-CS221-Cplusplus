#include "cities.hh"
#include <iostream>
#include <fstream>
#include <climits>

int main(int argc, char const *argv[])
{
    std::string fileName = "";

    if(argc == 2){ //if there is ONLY the .cpp file and the input file
        fileName = argv[1]; //input file name
    }
    else{
        std::cout << "please input like this: ./cppfile InputFile \n";
        return 1; //too many or too few files)
    }

    auto fin = std::ifstream(fileName);
    Cities cities;
    fin >> cities;
    auto citySize = cities.get_vectorOfCities_().size();
    double minDist = INT_MAX;
    Cities::permutation_t shortestPerm;

    int perms = 1000000;
    if(citySize > 0){
        for(int i = 1; i < perms; i++){
            Cities::permutation_t randPerm = cities.random_permutation(citySize);
            auto newDist = cities.total_path_distance(randPerm);
            if(newDist < minDist)
            {
                shortestPerm = randPerm;
                minDist = newDist;
                std::cout << i << " " << newDist << "\n";
            }
        }
        cities = cities.reorder(shortestPerm);
    }
    

    std::ofstream newFile;
    newFile.open("shortest.tsv");
    newFile << cities;
    newFile.close();
}