#include "hforest.hh"
#include "hforest.cc"
#include <cassert>
#include <iostream>

int main()
{
    auto oakForest1 = HForest();
    //auto oak1 = HTree(126,1);
    std::cout << oakForest1.size() <<'\n';
    //oakForest1.add_tree(std::make_shared<HTree>(126,1));

    oakForest1.add_tree(std::make_shared<HTree>(126,1,
            std::make_shared<HTree>(-5,2,
                std::make_shared<HTree>(12,3), 
                std::make_shared<HTree>(6,4,
                    std::make_shared<HTree>(9,5))), 
            std::make_shared<HTree>(12,6,
                std::make_shared<HTree>(3,7))));

    oakForest1.add_tree(std::make_shared<HTree>(126,0,
            std::make_shared<HTree>(-5,2,
                std::make_shared<HTree>(12,3), 
                std::make_shared<HTree>(6,4,
                    std::make_shared<HTree>(9,5))), 
            std::make_shared<HTree>(12,6,
                std::make_shared<HTree>(3,7))));

    oakForest1.add_tree(std::make_shared<HTree>(126,333, //making it so that ultimately similar trees have different values at root note
            std::make_shared<HTree>(-5,2,
                std::make_shared<HTree>(12,3), 
                std::make_shared<HTree>(6,4,
                    std::make_shared<HTree>(9,5))), 
            std::make_shared<HTree>(12,6,
                std::make_shared<HTree>(3,7))));

    oakForest1.add_tree(std::make_shared<HTree>(126,2,
            std::make_shared<HTree>(-5,2,
                std::make_shared<HTree>(12,3), 
                std::make_shared<HTree>(6,4,
                    std::make_shared<HTree>(9,5))), 
            std::make_shared<HTree>(12,6,
                std::make_shared<HTree>(3,7))));

    std::cout << oakForest1.size() <<'\n';

    auto hold = oakForest1.pop_tree();
    std::cout << hold->get_value() <<'\n';
    std::cout << hold->get_key() <<'\n';

    std::cout << oakForest1.size() <<'\n';

    auto hold2 = oakForest1.pop_tree();
    std::cout << hold2->get_value() <<'\n';
    std::cout << hold2->get_key() <<'\n';

    std::cout << oakForest1.size() <<'\n';

    return 0;
}