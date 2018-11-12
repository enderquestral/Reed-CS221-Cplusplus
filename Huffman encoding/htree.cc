#include "htree.hh"
#include <cassert>
#include <list>
#include <iostream>
//////////

// Initialize with a key, left value, right value, and a value:
HTree::HTree(int key, uint64_t value, tree_ptr_t left, tree_ptr_t right){
    key_ = key;
    value_ = value;
    left_ = left;
    right_ = right;
}

//HTree::~HTree(){
    //WORK ON
    //IF THIS SEGMENT IS UNCOMMENTED AND ~HTree IS NOT default, IT CAUSES SEGMENTATION FAULT
    //if the left_ and right_ of an HTree are nullptrs, delete HTree and return.
    //else, holderToLeft::~HTree, holderToRight::~HTree, destroy holderToLeft, destroy holderToRight, destroy HTree
    
    //If this causes problems, make it blank?
    /*if (left_ ==nullptr and right_ == nullptr){
        delete this;
        return;
    }
    auto holdPointerL = this->get_child(Direction::LEFT);
    auto holdPointerR = this->get_child(Direction::RIGHT);
    holdPointerL->~HTree(); //destroy tree left
    holdPointerR->~HTree(); //destroy tree right

    delete this;*/
//}

int HTree::get_key() const{return key_;}  // Return key in current node
uint64_t HTree::get_value() const{return value_;}      // Return value in current node

// Return the child of this node indicated by dir.
// If the child is nullptr (current node is a leaf), returns nullptr.
HTree::tree_ptr_t HTree::get_child(Direction dir) const{
    if (dir == Direction::LEFT and left_ != nullptr){
        return left_;

    }
    else if (dir == Direction::RIGHT and right_ != nullptr){
        return right_;

    }
    else{ //dir is not LEFT or RIGHT OR appropriate HTree value does not point to something
        return nullptr;
    }
}

// Return a list of directions from root to a node of a given key.
// Crashes (with an assert) if key not contained in this tree
HTree::path_t HTree::path_to(int key) const{
    path_t holdPath; //meant to be empty list. Used to just return something empty.
    if(key_ ==key){
        return holdPath;
    }
    else{
        //focus on left branch
        if (left_->isValueThere(key)) { //child path becomes left
            auto child_path = left_->path_to(key);
            child_path.insert(child_path.begin(), Direction::LEFT);
            return child_path;
        }
        //focus on right branch
        if(right_->isValueThere(key)){
            auto child_path = right_->path_to(key);
            child_path.insert(child_path.begin(), Direction::RIGHT);
            return child_path;
        }
    }
    assert(false);
}


bool HTree::isValueThere(int key) const{
      //make sure this is not NULL?
      if(key_ == key){
        return true;
      }
      if(get_child(Direction::LEFT) != nullptr){
        //auto holdPointer = this->get_child(Direction::LEFT);
        if(left_->isValueThere(key)){
            return true;
        }
      }
      if(get_child(Direction::RIGHT) != nullptr){
        //auto holdPointer = this->get_child(Direction::RIGHT);
        if(right_->isValueThere(key)){
            return true;
        }
      }
      return false;
}

void HTree::printOutList(int key)const {
    auto pathList = path_to(key);
    std::string wordHolder = "";
    for (auto c: pathList){
        if(c == Direction::LEFT){
            wordHolder += "L ";
        }
        if(c == Direction::RIGHT){
           wordHolder += "R "; 
        }
    }
    std::cout << wordHolder << '\n';
}