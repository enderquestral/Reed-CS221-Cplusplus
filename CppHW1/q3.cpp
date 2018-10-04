//have a helper function pow that takes 2 int parameters, base and exponent, returns an int.
//pow should calculate base^exponent RECURSIVELY and return that value
//main should read in 2 int values from user. if either is less than 1, function should print out "both inputs must be positive" and return. 
//If both are positive, main should call pow, specifying the first user input as base, second as exponent. 
//main should then print the result returned before returning. 

//Written by Hannah Hellerstein
#include <iostream>
using namespace std;

int pow(int,int);

int main(){
	int num = 0;
	int num2 = 0;
	int result = 0;

	cout << "Please enter an int: "; //base
	cin >> num;
	cout << "Please enter another int: "; //exponent
	cin >> num2;
	if ( num < 1 or num2 < 1){
		cout << "Both inputs must be positive.";
		cout << '.\n';
		return 0;
	}
	else{
		result = pow(num,num2);
		cout << result; 
		cout << '\n';
		return 0;
	}
	
}

int pow(int base, int exponent){
	if (exponent == 1){
		return base;
	}
	else if (exponent > 1){
		//exponent = exponent -1;
		return(base * pow(base, exponent-1));
	}
	else{ //exponent = 0
		return 1;
	}
}