#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <iterator>
#include "Sum.hpp" 

using namespace std;


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
        default_vector.push_back (5);

        // Creating map container 
        map <string, double> default_map;

        default_map["A"] = 1.02;
        default_map ["B"] = 2.02;
        default_map ["C"] = 3.05;
        default_map ["D"] = 5.00;


        // Testing total sum

        cout << "Total Sum of the list: " << Sum (default_list) << endl;
        cout << "Total Sum of the vector: " << Sum (default_vector) << endl;
        cout << "Total Sum of the map: " << Sum (default_map) << endl;


        cout << endl;
        //Testing Sums with specifed iterators

        cout << "Sum of the Second and Third values in list: " 
            << Sum (next(default_list.begin(),  1), 
                next(default_list.end(), -1)) << endl;

        cout << "Sum of the Second and Third values in vector: " 
            << Sum ((default_vector.begin () +1),
             (default_vector.end ()-1)) << endl;

        cout << "Sum of the Second and Third values in map: "
            << Sum <string, double> (next(default_map.begin (), 1), 
                next(default_map.end (), -1)) << endl;

    return 0;
}