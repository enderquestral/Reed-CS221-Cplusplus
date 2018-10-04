//Read 3 int values from standard input using cin, storing each into its own int variable. program should use if/else statements to determine the SMALLEST VALUE entered by the user, print that value to standard output using cout.

//Written by Hannah Hellerstein
#include <iostream>
using namespace std;
int main(){
	int int1 = 0;
	int int2 = 0;
	int int3 = 0;

	cout << "Please enter an integer value: ";
	cin >> int1;
	cout << "Please enter another integer value: ";
	cin >> int2;
	cout << "Please enter another integer value: ";
	cin >> int3;

	//FIND THE SMALLEST INT
	if (int1>int2){
		//
		if (int2>int3){ //int2 >int3
			cout << int3; 
			cout <<'\n';}
		else{ //int3>int2
			cout << int2;
			cout <<'\n';}
	}
	else //int2>int1
		if (int1>int3){
			cout << int3;
			cout <<'\n';//print out int3
		}
		else{ //int3>int1, print out int1
			cout << int1;
			cout <<'\n';}
	return 0;
	
}