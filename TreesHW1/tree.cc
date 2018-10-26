//This is gonna be "the first hard homework." Oh boy.
#include "tree.hh"
#include <cassert>
//Tree holds values via an indec with a key. Don't worry about efficiency.
bool isValueThere(tree_ptr_t tree, key_t key);

tree_ptr_t create_tree(const key_t& key, const value_t& value, tree_ptr_t left, tree_ptr_t right){
    tree_ptr_t sapling = new Tree;
    sapling->key_ = key;
    sapling->value_ = value;
    sapling->left_ = left; //making sure that the input given actually is there
    sapling->right_ = right;//making sure that the input given actually is there
    return sapling;
}




void destroy_tree(tree_ptr_t tree){
    // Deallocate all space consumed by this tree and its children.
    if (!tree){ //if there is nothing in the pointer spot
        delete tree;
        return;
    }
    destroy_tree(tree->left_);
    destroy_tree(tree->right_);
    delete tree;
}

std::string path_to(tree_ptr_t tree, key_t key){
    assert(tree!= NULL); //catch if tree or key do not exist
    std::string wordHolder = ""; 
    
    if(tree->key_ == key){// if key is at present location
        return wordHolder;
    }
    else{
        if(tree->left_ != nullptr){
            if(isValueThere(tree->left_, key) ){
                wordHolder  += "L";
                return wordHolder + path_to(tree->left_, key);
            }
        }
        if(tree->right_ != nullptr){
            if(isValueThere(tree->right_, key)){
                wordHolder += "R";
                return wordHolder + path_to(tree->right_, key);
            }
        }
        
    }
    assert(false);
}

bool isValueThere(tree_ptr_t tree, key_t key){
    //give me a tree, give me a key, return yes if the key exists in this tree
    if (tree->key_ == key){ //if there is nothing in the pointer spot
        return true;
    }
    if(tree->left_ != nullptr){
        if(isValueThere(tree->left_, key)){
            return true;
        }
    }
    if(tree->right_ != nullptr){
        if(isValueThere(tree->right_, key)){
            return true;
        }
    }
    return false;
}


tree_ptr_t node_at(tree_ptr_t tree, std::string path){
    assert(tree != NULL);
    for (char c: path){
        if (c == 'L' and tree->left_ != nullptr){
            tree = tree->left_;
        }
        else if (c == 'R' and tree->right_ != nullptr){
            tree = tree->right_;
        }
        else{
            return nullptr;
        }
    }
    return tree;
}

