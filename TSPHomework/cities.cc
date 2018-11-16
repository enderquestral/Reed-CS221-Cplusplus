//WRITTEN BY CASEY HARRIS AND HANNAH HELLERSTEIN

#include "cities.hh"


////////
Cities::Cities(){
    srand(time(NULL));
}
Cities::~Cities(){

}

// Given a permutation, return a new Cities object where the order of the
// cities reflects the original order of this class after reordering with
// the given ordering. So for example, the ordering { 1, 0 } simply swaps
// the first two elements (coordinates) in the new Cities object.
Cities Cities::reorder(const permutation_t& ordering) const{

    ///Not sure if this is what is meant by the meaning above, but... fingers crossed!
    Cities newCitiesObject;
    for(auto i : ordering)
    {
        newCitiesObject.vectorOfCities_.push_back(this->vectorOfCities_.at(i));
    }
    return newCitiesObject;
}

// For a given permutation of the cities in this object,
// compute how long (distance) it would take to traverse all the cities in the
// order of the permutation, and then returning to the first city.
// The distance between any two cities is computed as the Euclidean 
// distance on a plane between their coordinates.
//It should compute the total distance of traversing all the cities in the order defined by the permutation. 
//Don't forget to add the distance going back from the last city in the permutation to the first one.
double Cities::total_path_distance(const permutation_t& ordering) const{

    double holdDistance = 0.0;
    for(unsigned int i =0; i< ordering.size()-1; i++){
        //std::cout << ordering.at(i) << "\n";
        //std::cout << ordering.at(i+1) << "\n";
        //std::cout << vectorOfCities_[ordering.at(i+1)].first << "\n";
        holdDistance += get_distance(ordering.at(i), ordering.at(i+1));
    }
    holdDistance += get_distance(ordering.at(ordering.size()-1), ordering.at(0)); //Distance of last city back to first
    return holdDistance;
}

double Cities::get_distance(const unsigned int spot1, const unsigned int spot2) const{
    auto city1 = vectorOfCities_.at(spot1);
    auto city2 = vectorOfCities_.at(spot2);
    //get the distance between two cities? Unsigned ints?
    //NEED A DISTANCE FORMULA
    auto length = city2.first - city1.first;
    auto height = city2.second - city1.second;
    auto result = sqrt(pow(height,2)+pow(length,2));
    return result;
}

///NEW THING
//That generates and returns a new permutation of all the numbers from 0 to len-1 (with no skipped or repeated indices). 
//Note that the ordering needs to be "very random" for the search to work well in the next step. 
//You can implement your permutation algorithm any way you like, but please document your algorithm clearly in the code.
//You will need access to pseudo-random numbers for your permutation algorithm. 
//You can use the C++'s standard library random number generators

Cities::permutation_t Cities::random_permutation(unsigned len){
    permutation_t cityIDs;
    //Fill the permutation with numbers 0 to vector.size()
    for(unsigned int i = 0; i < len; i++)
    {
        cityIDs.push_back(i);
    }
    //Shuffle them
    permutation_t newOrder;
    for(auto j = len; j > 1; j--)
    {
        auto r = rand() % cityIDs.size();
        newOrder.push_back(r);
        cityIDs.erase(cityIDs.begin() + r);
    }
    //auto final = cityIDs[0];
    newOrder.push_back(cityIDs[0]);

    return newOrder;
}



istream& operator>> (std::istream& is, Cities& city){
    //allow for the reading  / filling of a Cities object from a stream.

    //is>> city.holdCoordsOfACity_.first>> city.holdCoordsOfACity_.second;

    //FOR OPERATOR IN CLASS
    /*char c;
    while(is>>c){
        holdCoordsOfACity_.first = int(c);
        is>>c;
        holdCoordsOfACity_.second = int(c);
        vectorOfCities_.push_back(holdCoordsOfACity_);
    }
    //int placeholder;

    //is >> placeholder;
    //vectorOfCities_.push_back(placeholder);
    return is;*/

    //FOR OPERATOR OUTSIDE OF CLASS
    //int c;
    Cities::coord_t holdCoordsOfACity;
    while(is>>holdCoordsOfACity.first){
        //holdCoordsOfACity.first = c;
        is>>holdCoordsOfACity.second;
        //holdCoordsOfACity.second = c;
        city.get_vectorOfCities_().push_back(holdCoordsOfACity);
        //std::cout << "vectorOfCities_ size: " << city.get_vectorOfCities_().size() << "\n";
    }
    //int placeholder;

    //is >> placeholder;
    //vectorOfCities_.push_back(placeholder);
    return is;


}

ostream& operator<< (std::ostream& os, Cities& city){
    for(auto c : city.get_vectorOfCities_())
    {
        os << c.first << " " << c.second << "\n";
    }
    return os;
}






