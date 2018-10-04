//have helper function isMultiple, which takes 2 int parameters and returns a bool. 
//isMultiple should return true when the first argument is a multiple of the second, false all other cases.
//main Should read an int from user using cin, store into int var called num.
//main should use a loop to read in 10 ints from the user using cin, isMultiple is called for each loop iteration to determine if the number just read in is a multiple of the value stored in num. 
//main should then print out to standard output using cout how many of the 10 numbers were multiples of num. 
// DO NOT USE ANY DATA STRUCTURES THAT STORE MULTIPLE VALUES ALA LISTS OR ARRAYS
//Counting negative numbers as multaples.
//Written by Hannah Hellerstein
#include <iostream>
using namespace std;
bool isMultiple(int,int);

int main(){
	int i = 10;
	int num = 0;
	int num2 = 0;
	int num3 = 0; //counter to see how many are multiples of num
	bool torf = false;

	cout << "Please enter an int to see which is an exponent: "; //to see which is an exponent
	cin >> num;

	while(i > 0){
		cout << "Please enter an int: ";
		cin >> num2;

		torf = isMultiple(num2,num);
		if(torf){
			num3 = num3 +1;
		}
		i = i-1;
	}
	cout << num3;
	cout << '.\n';
	return 0;
}

bool isMultiple(int intparam1, int intparam2){
	if ((intparam1%intparam2) == 0)
	{
		return true;
	}

	else{
		return false;
	}

}