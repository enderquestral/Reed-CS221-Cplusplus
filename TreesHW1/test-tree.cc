#include "tree.hh"
#include "tree.cc"
#include <cassert>
#include <iostream>

int main(){
    tree_ptr_t oak = create_tree(126,0,create_tree(-5,0,create_tree(12,0),create_tree(6,0,create_tree(9,0))),create_tree(12,0,create_tree(3,0)));
    
    std::cout << path_to(oak, 12) << '\n';
    std::cout << path_to(oak, 9) << '\n';
    std::cout << path_to(oak, 3) << '\n';
    std::cout << path_to(oak, -5) << '\n';
    std::cout << path_to(oak, 126) << '\n';
    //std::cout << path_to(oak, 7) << '\n'; //Does not exist in tree. If uncommented, it asserts and causes code to stop.
    tree_ptr_t test = node_at(oak, "LR");
    std::cout << test->key_ <<'\n';
    destroy_tree(oak);
}

