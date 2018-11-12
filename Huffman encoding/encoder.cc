
//Encoder is a program that takes another filename as a command-line argument. 
//It then reads and compresses the file into an output file of the same name with a .comp suffix.

//So, for example, after implementing and compiling the encoder, you'd be able to do something like:

//./encoder bitio.cc

//And when the program completes there'll be a new binary file in your directory called bitio.cc.comp. 
//In both instances, try to challenge yourself to take more than a single command-line argument, so that your encoder actually compresses all the filenames given as input.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "huffman.hh"
#include "bitio.hh"

int main(int argc, char* argv[])
{
    Huffman huff;
    Huffman::bits_t vectorofbits;
    std::string fileName  = "";
    
    if(argc == 2){ //if there is ONLY the .cpp file and the input file
        fileName = argv[1]; //input file name
    }
    else{
        std::cout << "please input like this: ./cppfile InputFile \n";
        return 1; //too many or two few files
    }

    
    std::ifstream oldFile;
    oldFile.open(fileName, std::ios::out);
    std::ofstream newFile; //make a new file
    newFile.open(fileName +".comp", std::ios::binary);
    //BitIO bitReceive(nullptr, &newFile);//has input stream, no output stream
    BitIO bitGive(&newFile, nullptr);//has an output steam, no input stream

    char c;
    while(oldFile.get(c)){ //c is a character in oldfile //for every character in input file:
        //std::cout << char(c) <<"\n";
        vectorofbits = huff.encode(c);//take that character, encode it by taking the int value of the character
        for(long unsigned int i =0; i < vectorofbits.size(); i++){
            bitGive.output_bit(vectorofbits[i]);
        }  
    }

    oldFile.clear();
    oldFile.seekg(0, std::ios::beg);  //reset file to point at beginning again


    /*while(oldFile.get(c)){
        HTree::path_t holdPath = huff.get_huffTree()->path_to(c);

        for(auto c: holdPath){
            if(c == HTree::Direction::LEFT){
                bitGive.output_bit(true);
            }
            if(c == HTree::Direction::RIGHT){
                bitGive.output_bit(false);
            }
        }
    }*/

    
    

    //take first two characters  'I ' convert them to ascii :4820
    //COMPARE THE TWO, PLEASE BE THE SAME

    /*for(auto c : oldFile){ //c is a character in oldfile //for every character in input file:
        vectorofbits = huff.encode(c);//take that character, encode it by taking the int value of the character
        for (auto v: vectorofbits){
            bitGive.output_bit(v);//get vector of bits, use bitio output bit to output that into a new file?
        }
    }*/
   
        
        
        //put those 1s and 0s into a new file, 8 times


    newFile.close();
    oldFile.close();
    return 0;
}