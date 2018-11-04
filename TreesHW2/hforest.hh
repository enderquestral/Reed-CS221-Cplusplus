#include "htree.hh"
#include <vector>
#include <memory>
#pragma once


class HForest
{
public:
    using tree_ptr_t = std::shared_ptr<const HTree>;
    enum class Direction { LEFT, RIGHT };
    using path_t = std::list<Direction>;

    HForest(int size = 0);
    ~HForest() = default;
    //size: return how many trees are in the forest.
    int size() const;

    //add_tree: Take a pointer to an HTree and add it to the forest. You may use a smart pointer if you like.
    void add_tree(tree_ptr_t newHTree);
    //pop_tree: return a pointer to the HTree with the highest value in the root node, and remove it from the forest.
    tree_ptr_t pop_tree();

    void print_out_popped_tree(tree_ptr_t oldTree);
    

private:
    int size_;
    std::vector<tree_ptr_t> forest_;
};