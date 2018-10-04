//have a helper function called log, takes 2 int parameters: num and base. returns an int. 
//log should use a loop to calculate the logarithm of num when base is used as the base and return that value. 
//log should return the floor of the logarithm for numbers that are not powers of the base. 
//main reads in 2 ints from user. if either input is negative, the main function should print out "both inputs must be non-negative" and return. 
//if both are positive, the main should call log, specifying the first input as num, the second as base. the main should then print the result. 

//Written by Hannah Hellerstein
#include <iostream>
using namespace std;
int log(int,int);
int main(){
	int num = 0;
	int num2 = 0;
	int result = 0;
	cout << "Please enter an int [num]: "; //num
	cin >> num;
	cout << "Please enter another int [base]: "; //base
	cin >> num2;
	if( num < 0 or num2 < 0){
		cout << "Both inputs must be non-negative.";
		cout << ".\n";
		return 0;
	}
	else if (num ==0 or num2 ==0){ //-intinity, which is a hassle
		cout << 0;
		cout << '\n';
		return 0;
	}
	else {
		result = log(num,num2);
		cout << result;
		cout << '\n';
		return 0;
	}
	
}

int log(int num, int base){
	int i = 0;
	int hold = base;
	 //should return the floor of the logaritm for numbers that are not powers of the base [ROUND TO LOWEST INT]
	while(num >= hold){
		hold *= base;
		i +=1;
	}
	//if ((result % 10) != 0){ //if the end result HAS something in the .0th spot, return the floor of it.
	
	return i;
}