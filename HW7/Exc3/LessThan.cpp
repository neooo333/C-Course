#include "LessThan.hpp"
#include <utility>
#include <string>

using namespace std;

// Functions for LessThan class

LessThan::LessThan (double value) : threshold (value){};

LessThan::~LessThan (){};

bool LessThan::operator () (double x) const{
    return x < threshold;
}

bool LessThan::operator () (const pair <string, double>& pair_value) const {
    return pair_value.second < threshold;
}


