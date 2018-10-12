//https://youtu.be/M34TO71SKGk
//As the above, but using a more deterministic/less accurate grid method.
//Basically: Divide the unit square (1x1 length, area:1) to a grid of NxN points. 
//For each of the points, we find if it fits within the unit quarter-circle with an origin at one of the corners and a radius of 1. 
//Then we divide the number of points inside the circle by the total number of points in the grid and multiply by 4 to get an ESTIMATE of Pi.
//compile the program with: g++ -O3 -Wall -Wextra -pedantic pi.cpp -o pi
//Make sure code compiles with no warnings, everything is properly documented/named.


//Written by Hannah Hellerstein
#include <iostream>
#include <cmath>
#include "pi.hh"
using namespace std;

int main(){
	//Write a main program that prints the Pi estimate, run it for a few different values of npoints.
	//500 points = Pi estimate of 3.14938
    
    unsigned int placeholderpoints = 10;
    double result = gridpi(placeholderpoints);
    cout << "The Pi estimate is: "<< fixed << result <<endl;

    /*placeholderpoints = 10;
    result = gridpi(placeholderpoints);
    cout << "The Pi estimate for 10 is: "<< fixed << result <<endl;

    placeholderpoints = 100;
    result = gridpi(placeholderpoints);
    cout << "The Pi estimate for 100 is: "<< fixed << result <<endl;

    placeholderpoints = 1000;
    result = gridpi(placeholderpoints);
    cout << "The Pi estimate for 1000 is: "<< fixed << result <<endl;

    placeholderpoints = 10000;
    result = gridpi(placeholderpoints);
    cout << "The Pi estimate for 10000 is: "<< fixed << result <<endl;*/

	return 0;
}

double gridpi(unsigned npoints){ 
	double pi =0.0;
    int insidePoints = 0; //incremental value
    //field of NxN
    for (int i=0; i < int(npoints); i++){
        //double xcord = double(i)/newTotal;
        for (int j=0; j < int(npoints); j++){
            double xcord = double(i)/npoints;
            double ycord = double(j)/npoints;
            if (std::hypot(xcord,ycord) <= 1.0){
                insidePoints++;
            }

        }
    }
    pi = (double(insidePoints)/pow(npoints,2))*4;
    return pi;
}
