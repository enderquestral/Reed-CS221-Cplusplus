#include "hforest.hh"
#include "htree.cc" //Do not include, just link it into same executable?

#include <cassert>
#include <list>
#include <algorithm>
#include <iostream>


    HForest::HForest(int size){
        size_ = size;
    }
    
    //HForest::~HForest(){}

    //size: return how many trees are in the forest.
    int HForest::size() const{return size_;}

    //add_tree: Take a pointer to an HTree and add it to the forest.
    void HForest::add_tree(tree_ptr_t newHTree){
        forest_.push_back(newHTree);
        std::make_heap(forest_.begin(), forest_.end()); //doesn't like compare function????
        size_++;
    }

    //pop_tree: return a pointer to the HTree with the highest value in the root node, and remove it from the forest.
    HForest::tree_ptr_t HForest::pop_tree(){
        std::make_heap(forest_.begin(), forest_.end());
        tree_ptr_t holdspot = *forest_.begin();
        //auto torf = compare_trees(*forest_.begin(), *forest_.end()); //This is fine... something about make heap is not happy
        
        auto largestValue = holdspot->get_value();
        //auto savedPosition = 0;
        //auto iteratingThru =0;
        for(auto c: forest_){ //loop through forest
            if(c->get_value() > largestValue){//tell it to give me the HTree with the largest value at its root node
                holdspot = c;//save the node seperately in outside variable. 
                largestValue = holdspot->get_value();
            }
            //iteratingThru++;
        }

        std::pop_heap(forest_.begin(), forest_.end()); //remove that tree from the forest.
        //std::make_heap(forest_.begin(), forest_.end(), compare_trees(*forest_.begin(), *forest_.end()));
        size_--;
        return holdspot;
    }


    void HForest::print_out_popped_tree(tree_ptr_t oldTree){
        std::cout << oldTree->get_value() <<'\n';
        std::cout << oldTree->get_key() << '\n';
    }

    //This function takes two elements (trees) in a forest and returns a bool: true if the first tree has a lower value than the second tree. 
    //The value of a tree can simple be the node value at the root of the tree.
    bool HForest::compare_trees(tree_ptr_t t1, tree_ptr_t t2){
        auto hold1 = t1->get_value();
        auto hold2 = t2->get_value();
        if(hold1<hold2){
            return true;
        }
        return false;
    }