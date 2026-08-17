#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include "LessThan.hpp"


using namespace std;


// Defining global functions for cout if 
bool less_than_2 (double value){
    return value < 2;
}

bool less_than_2_map (const pair <string, double>& pair_values){
    return  pair_values.second < 2;
}


int main () {

        // Creating List with some data

        list <double> default_list;

        default_list.push_front(5.36);
        default_list.push_front (7.56);
        default_list.push_front (1.00);
        default_list.push_front (2.45);

        // Creating Vector with 3 elements 
        vector <double> default_vector (3);

        default_vector[0] = 2.37;
        default_vector[1] =  3.25;
        default_vector[2] = 4.25;
        default_vector.push_back (5.00);

        // Creating map container 
        map <string, double> default_map;

        default_map["A"] = 1.02;
        default_map ["B"] = 2.02;
        default_map ["C"] = 3.05;
        default_map ["D"] = 5.00;

        // Checking count_if

        cout << "Less than 2 in vector: "  << count_if (default_vector.begin (),
             default_vector.end (), 
            less_than_2) << endl;

        cout << "Less than 2 in list: " << count_if (default_list.begin (), 
                default_list.end (),
                less_than_2) << endl;
        cout << "Less than 2 in map: " <<count_if (default_map.begin(),
                    default_map.end (),
                    less_than_2_map) << endl;

        cout << endl;

        // Cheking count_if with function object

        cout << "Less than 5 in vector: " << count_if (default_vector.begin (),
             default_vector.end (), 
            LessThan (5)) << endl;

        cout << "Less than 10 in list: " << count_if (default_list.begin (), 
                default_list.end (),
                LessThan (10)) << endl;
        cout << "Less than 4 in map: " << count_if (default_map.begin(),
                    default_map.end (),
                    LessThan (4)) << endl;
        
        return 0;
}