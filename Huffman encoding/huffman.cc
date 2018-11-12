#include "huffman.hh"

Huffman::Huffman(){
    for(int i =0; i < ALPHABET_SIZE-1; i++){ //Init all first row 0-256. From there, focus on making Huffman Tree.
        //freq_table_[i][0] = i;//FIRST ASCII VALUE BEING 0 OR 1?
        freq_table_[i] = 0;
    }
    freq_table_[ALPHABET_SIZE-1]=1;

}
Huffman::~Huffman(){

}

// Encode a symbol into a sequence of bits, then update frequency table.
Huffman::bits_t Huffman::encode(int symbol){
    /*The algorithm for encoding a character (symbol) c is summarized as follows:
    Build a Huffman tree from scratch, given the existing frequency table (see below).
    Find the path to c in the Huffman tree from the root.
    Convert the path of lefts and rights to zeros and ones, which will be returned as a sequence of bits.
    Increment the frequency table by adding one to c's count.*/

    
    make_huffman_tree();
    bits_t bitsSequence;
    //Find the instance of the symbol in the huffTree.

    auto holdPath = huffTree_->path_to(symbol);
    freq_table_[symbol]++;//if it is already in tree, then we increment value by 1 and remake the heap.

    //we have to convert from lefts/rights to 0s and 1s by finding.
    //We will be given lefts/rights for the specified HTree though path_to, which we convert to 0s and 1s. Do this with a simple for loop.
    for(auto c: holdPath){
        if(c == HTree::Direction::LEFT){
            bitsSequence.push_back(true); //TRUE
        }
        if(c == HTree::Direction::RIGHT){
            bitsSequence.push_back(false); //FALSE
        }
    }
    return bitsSequence;
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
    
    //WORK ON
    
    if(huffTree_ == nullptr){ //huffman tree not yet computed, build one from scratch
        make_huffman_tree();
    }
    int thisNodeSymbol =-1;

    //BELOW WORKS... ONLY FOR THE TOP FRONT TWO THOUGH.
    if(bit){ //True = Left = 1
        huffTree_ = huffTree_->get_child(HTree::Direction::LEFT);
        thisNodeSymbol = huffTree_->get_key();
        
    }
    else{ //False = Right = 0
        huffTree_ = huffTree_->get_child(HTree::Direction::RIGHT);
        thisNodeSymbol = huffTree_->get_key();
    }

    if (thisNodeSymbol >= 0)
    {
        freq_table_[thisNodeSymbol]++;
        huffTree_ = nullptr;
        return thisNodeSymbol;
    }

    return -1; //Something has gone wrong here

    //Take a path,
    //Trace it down your singular HTREE (works bitwize) though lefts and rights
    //return the key, no matter what it is. [Must be within range of 0-256 in freq_table]
}

void Huffman::make_huffman_tree(){
    //character: 'a', appears: 2. Does not know/care about encoding. 
    HForest forest;
    //create a new HTREE node for every possible character +EOF. character/symbol will be it's key, count as it's value. 

    
    for(int i =0; i < ALPHABET_SIZE-1; i++){ 
        forest.add_tree(HTree::tree_ptr_t(new HTree(i, freq_table_[i])));
    }
    forest.add_tree(HTree::tree_ptr_t(new HTree(HEOF, 1)));

    //[As long as there is more than one tree in the Hforest_, find the top two (lowest freq). (pop twice).
    //Merge the top two by making a new HTree, with key = negative_number, and value = sum_of_subtrees
    //leftnode and right node are the two trees you popped.]
    //LOOP ALL OF THIS UNTIL THERE IS ONLY ONE HTREE.
    int i =-1;
    while(forest.size() > 1){
        auto lowestFreq1 = forest.pop_top();
        auto lowestFreq2 = forest.pop_top();
        forest.add_tree(HTree::tree_ptr_t(new HTree(i,(lowestFreq1->get_value() + lowestFreq2->get_value()), lowestFreq1, lowestFreq2)));
        i--;
    }
    //forest_ = forest;
    huffTree_ = forest.pop_top();
    //return huffTree_; //returning an HuffTree
}

//void pass_list_to_huffman(){
//Would: 'I have a character you don't have, here is all the values for it.'
//}

