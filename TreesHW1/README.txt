How to build/run my program:
    How to test this program:
        In the test-tree.cc file, create a tree_ptr_t instance, and initialize it with create_tree(). Initialize the left/right nodes of this instance as you do this, for effiency's sake. 

        Then, once you have properly initalized the instances, test whichever other programs you wish. Only test destroy_tree at the end.
        path_to causes the program to stop running if you input a number that is not in the tree. Print it with a standard std::cout.
        node_at gives the location of the node of a given key. To print it out, you should assign that result to a tree_ptr_t, and then print out the test->key_ to make sure it outputs correctly. If nothing/a non L-or-R character is input as key, or the actual path does not work as instructed, then nullptr is returned instead. For proper functionality, make the string consist ONLY of 'L's and 'R's.

    To run this program:
            In the terminal, type "make". Then, type "make use_tree" to create the proper executable. Then, simply run ./use_tree to run what is in the test-tree.cc fiel.

Explaining my design choices:
    Throughout all of this, my main feeling was that recursion was a life saver. It made destroy_tree feel so efficient, and path_to feel less of a drag. This being said, I'm somewhat sad that I had to create a helper function for path_to, but in the end it did make more sense than a far larger individual function, even if the implementation of isValueThere felt inefficient. 
    create_tree was simple. Just create a member of a structure, give it its values, then output it. 
    node_at was based entirely around looping through a string with a character c. From there, it's just making sure that c is either a R or a L, and that said path exists in the tree.  

    After all that, I just used the following to check for data leaks:
    valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./use_tree
    


