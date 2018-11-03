//After you're done implementing your HTree, you will want to copy & rewrite your testing code from HW5 to use the new class. Run it to ensure you haven't introduced any new bugs.


#include "htree.hh"
#include "htree.cc"
#include <cassert>
#include <iostream>
//#include <catch2.hpp> // Use this to be a testing thing after init tree works?


/*
            126
           /   \
          /     \
        -5       12
        / \     /
      12   6    3
          /
         9
*/
int main(){
    auto oak1 = HTree(126,1,
            std::make_shared<HTree>(-5,2,
                std::make_shared<HTree>(12,3), 
                std::make_shared<HTree>(6,4,
                    std::make_shared<HTree>(9,5))), 
            std::make_shared<HTree>(12,6,
                std::make_shared<HTree>(3,7)));    

    
    std::cout << oak1.get_key() << '\n';
    std::cout << oak1.get_value() << '\n';

    oak1.printOutList(12);
    oak1.printOutList(9);
    oak1.printOutList(3);
    oak1.printOutList(-5);
    oak1.printOutList(126);
    oak1.printOutList(6);
    //oak1.printOutList(7); //Uncomment if you want to see it crash thanks to assert.

    //oak1.get_child(RIGHT);
    //oak1.get_child(LEFT);
    return 0;
}

