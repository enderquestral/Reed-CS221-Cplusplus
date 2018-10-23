#include <iostream>
#include <initializer_list>
#include "highest.hh"
//I would normally include a .hh file, but since the submission limit for files is 3, I'll have to initialize the highest function in the .cpp file.

using namespace std;

//const int* highest(int val, const int* start, const int* finish);

int main()
{
    const int DATA_LEN = 10;
    const int data[DATA_LEN] = { 0, 1, 1, 1, 4, 4, 5, 6, 7, 10 };

    for (auto search : { -1, 0, 1, 2, 4, 6, 7, 8, 9, 10, 11, 555}) {
        const auto where = highest(search, data, data + DATA_LEN);
        std::cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            std::cout << "not found!" << std::endl;
        } else {
            std::cout << (where-data) << std::endl;
        }

    }
    return 0;

}

const int* highest(int val, const int* start, const int* finish){
    //Function performs a binary search, returns a pointer to the highest element in the array that contains this value
    //if value is not in this array, return nullptr
    //ASSUMING THAT THE ARRAY IS ALREADY SORTED...
    //int lengthOfArray = finish - start; //IFFY IF THIS WORKS, DON'T WANT TO RISK TRYING IT.
    const int* midpointer = start + ((finish-start)/2);
    if ((finish-start) >0){
        //normal if else statements with recursion, which should be the correct time
        //Find the highest pointer with the value
        if((finish-start) == 1){
            if(*midpointer == val){
                //Value at place midpointer is equal to val.
                return midpointer;
            }
            else{ //last spot, and the value at midpointer is not val, showing that there is no instance of val
                return nullptr;
            }
        }
        else if (val < *midpointer){
            return highest(val, start, midpointer);
        }
        else{ //val >= *midpointer. It does this so no matter what, lengthOfArray becomes 1 at the end.
            return highest(val, midpointer, finish);
        }
    }
    else{ //length of array is 0
        return nullptr;
    }

}
