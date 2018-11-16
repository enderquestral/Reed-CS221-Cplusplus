/*
 * API file for Travelling-Salesperson Cities class and utilities

 Your task for this homework is to write a number of member data, member functions, 
 and free functions to implement the functionality of Cities as defined below. 
 You are also required to write a main program that will use this functionality for a randomized search of a TSP solution. 
 In addition to the functions described below, add any constructor, destructor, or private methods that you deem necessary.
 */

#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <random>
#include <time.h>
using namespace std;


// Representation of an ordering of cities
class Cities {
 public:
  Cities();
  ~Cities();
  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  // An ordering of the cities in cities_t. Each value represents a unique index
  // into the current city ordering.
  using permutation_t = std::vector<unsigned int>;

  // Given a permutation, return a new Cities object where the order of the
  // cities reflects the original order of this class after reordering with
  // the given ordering. So for example, the ordering { 1, 0 } simply swaps
  // the first two elements (coordinates) in the new Cities object.
  Cities reorder(const permutation_t& ordering) const;

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.
  double total_path_distance(const permutation_t& ordering) const;

  permutation_t random_permutation(unsigned len);

  //std::istream& operator>> (std::istream& is);
  //std::ostream& operator<< (std::ostream& os);

  double get_distance(const unsigned int spot1, const unsigned int spot2) const;
  //double get_distance(const coord_t city1, const coord_t city2) const;
  std::vector<coord_t>& get_vectorOfCities_() {return vectorOfCities_;}
  coord_t get_holdCoords_()const{return holdCoordsOfACity_;}
  permutation_t get_originalOrder_()const{return originalOrder_;}

  private:
    std::vector<coord_t> vectorOfCities_;
    coord_t holdCoordsOfACity_;
    permutation_t originalOrder_;
};


istream& operator>> (std::istream& is, Cities& city);
ostream& operator<< (std::ostream& os, Cities& city);


