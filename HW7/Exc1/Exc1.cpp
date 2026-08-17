#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main () {

    // Creating List with some data

    list <double> default_list;

    default_list.push_back(5.36);
    default_list.push_back (7.56);
    default_list.push_front (1.00);

    // Accessing first and last element of the list 
    cout << "1st element of the list:  " << default_list.front () << endl;
    cout << "Last element of the list: " << default_list.back () << endl;

    // Creating Vector with 3 elements 
    vector <double> default_vector (3);

    default_vector[0] = 2.37;
    default_vector[1] =  3.25;
    default_vector[2] = 4.25;

    // Checking elements of the vector
    cout << endl;

    cout << "Vector Size: " << default_vector.size () << endl; 
    for (size_t i = 0; i < default_vector.size (); ++i){
        cout  <<"Vector element "<< i << ": " << default_vector [i] << endl;
    }

    // Increasing size of the vector by adding extra element at the beginning of the vector 
    default_vector.insert(default_vector.begin(), 5); // inserting element at the beginning of the vector
    default_vector.push_back(7);  // Adding one element at the very end of the vector

    // Checking size of the vector again. Should be 5 elements.

    cout << endl;
    cout << "Vector Size: " << default_vector.size () << endl; // should output 5
    for (size_t i = 0; i < default_vector.size (); ++i){
        cout  <<"Vector element "<< i << ": " << default_vector [i] << endl;
    }
    cout << "\n"; 

    // Creating map container 
    map <string, double> default_map;

    default_map["First Value"] = 1.02;
    default_map ["Second Value"] = 2.02;

    cout << "First value in map: " << default_map["First Value"] << endl;
    cout << "Second value in map: " << default_map["Second Value"] << endl;
    return 0;
}
