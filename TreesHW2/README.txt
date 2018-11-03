How to build/run my program:
    How to test this program:
        [In the test-htree.cc file, create an auto instance of an HTree, and initialize it and its branches all at once with HTree(key, value, std::make_shared<HTree>(...) [for the left branch], std::make_shared<HTree>(...) [for the right branch]). Initialize the left/right nodes of this instance as you do this, for effiency's sake. 

        In the test-hforest.cc file, oakForest1 will be your instance of a HForest, a collection of trees. To add trees to it, simply construct a tree like you did in test-htree.cc, but start it with oakForest1.add_tree(std::make_shared<HTree>[...]).

        From there, test whatever programs you wish. Some of the methods will not be pretty to print out. Once a Tree is in a forest, it can be deleted eventually with pop_tree. Because of how tree_ptr_t is built, no deletion needs to happen, the variables perish as they go out of scope.
        In test-htree.cc, the best functions to test are get_key(), get_value(), and printOutList() (which just prints out what you get from path_to.)
        In test-hforest.cc, the best funtions to test out are add_tree(), size(), and pop_tree(). If you create an instance of an HTree, then the methods you can call for an HTree should apply here as well. Be sure to print whatever you want out with a std::cout!

    To run this program:
            In the terminal, type "make". Then, simply run ./use_htree or ./use_hforest to run what is in the test-htree.cc or the test_hforest.cc files.

Explaining my design choices:
    In hforest.cc, there are a lot of comments as getting make_heap to work was NOT easy. The assignment hinted that it would need a compare_trees function to work (seen at the bottom of hforest.cc) but that caused make_heap to error instead? It was difficult to really see what was going on there. 
    Aside from that, most of my additions to the code were just simple "clarification functions." Things that did else/if for some values, or printed things out that would be difficult to print out normally. 
    In HForest I copied the definitions of tree_ptr_t and Directions and path_t to the class from HTree... I wasn't able to test if this caused any errors, but it seemed to work fine and the tree_ptr_t seemed nessicary for HForest to function.
    

    After all that, I just used the following to check for data leaks:
    valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./use_htree and ./use_hforest. Worked well on my end!
