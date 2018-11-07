#include <huffman.hh>
//#include <hforest.hh>



Huffman::Huffman(){
    temp_table[257][2] = {0}{0}; //character: 'a', appears: 2. Does not know/care about encoding. 
    freq_table_ = std::move(temp_table);
    //create a new HTREE node for every possible character +EOF. character/sybol will be it's key, count as it's value. 


}
Huffman::~Huffman(){

}


// Encode a symbol into a sequence of bits, then update frequency table.
bits_t Huffman::encode(int symbol){
    //bits_t is a vector of bools
    /*The algorithm for encoding a character (symbol) c is summarized as follows:
    Build a Huffman tree from scratch, given the existing frequency table (see below).
    Find the path to c in the Huffman tree from the root.
    Convert the path of lefts and rights to zeros and ones, which will be returned as a sequence of bits.
    Increment the frequency table by adding one to c's count.*/

    //if symbol is not in the tree, we need to make a new HTree with appropriate values. HTREE NODE SHOULD HAVE NO CHILDREN.
    //We update the freqtable with a new character instance. (check for not 0,0)


    //if it is already in tree, then we increment value by 1 and remake the heap.
    //make_heap(forest);

    //we have to convert from lefts/rights to 0s and 1s by finding.
    //We will be given lefts/rights for the specified HTree though path_to, which we convert to 0s and 1s. Do this with a simple for loop.

    return bits_t v1(23);
}

// Decode a single bit into a symbol. If no symbol can be unmabiguously decoded
// without additional bits, returns a negative value.
// Subsequent calls with more bits should eventually resolve to either
// a character symbol or HEOF.
// Finally, updates the frequency table with this additional symbol.
int Huffman::decode(bool bit){
    /*
    If this is the first bit in a sequence (Huffman tree not yet computed), 
    build a Huffman tree from scratch, given the existing frequency table (see below), 
    and start from the root node.

    Otherwise, start from the previous node you've computed.

    Compute the next node as either the left or right child of the current node, 
    depending on the bit value.

    If this is an intermediate node (not a leaf), you will return a negative number for a symbol. 
    Otherwise, you're a leaf, pointing to an actual symbol, which you will return.

    Eventually, the current node will be a leaf, at which point a real character c will be returned, 
    and you can reset the Huffman tree to nullptr to remember that next bit starts a new sequence. 
    Additionally, increment the frequency table for c.

    Note that decode works for a single bit at a time, so may have to be called multiple times until a complete symbol is identified.
    */

    //Take a path,
    //Trace it down your singular HTREE (works bitwize) though lefts and rights
    //return the key, no matter what it is. [Must be within range of 0-256 in freq_table]

    return 0;
}

HTree Huffman::make_huffman_tree(){
    //MAKE 257 HTREES.
    //Each HTree is the same thing as from the freq table: character as key, freq as value.
    //PUT THEM ALL IN AN HFOREST.

    //[As long as there is more than one tree in the HForest, find the top two (lowest freq). (pop twice).
    //Merge the top two by making a new HTree, with key = negative_number, and value = sum_of_subtrees
    //leftnode and right node are the two trees you popped.]
    //LOOP ALL OF THIS UNTIL THERE IS ONLY ONE HTREE.



    return HTree(1, 10);
}

//void pass_list_to_huffman(){
//Would: 'I have a character you don't have, here is all the values for it.'
//}

