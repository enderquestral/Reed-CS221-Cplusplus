//Written by Hannah Hellerstein
#include <iostream>
#include <cmath>
using namespace std;

constexpr double npoints = 10;
constexpr double gridpi2(unsigned npoints);
constexpr double makeItDouble(int insidePoints);


int main(){
    //Write a main program that prints the Pi estimate, run it for a few different values of npoints.
    //500 points = Pi estimate of 3.14938

    std:: cout << "The Pi estimate is: "<< fixed << gridpi2(npoints) <<endl;

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

constexpr double makeItDouble(int insidePoints){
    double placeholder = 0.0;
    return (placeholder + insidePoints);
}

constexpr double gridpi2(unsigned npoints){ 
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
    pi = (makeItDouble(insidePoints)/(npoints*npoints))*4;
    return pi;
    
}


