#include "boost/tuple/tuple.hpp"
#include <string>
#include <iostream>

using namespace std;


typedef boost::tuple <string, int, double> Person;
void Print (const Person& tuple_instance){

    // Checking diffrent versions of the get function
    cout << "Name: " << get<0> (tuple_instance) << endl;
    cout << "Age: " << tuple_instance.get <1> () << endl;
    cout << "Length: " << get <2> (tuple_instance) << endl;
    return;

}


int main () {

    Person first_person (string ("John"), int (27), double (34.65));
    Person second_person (string ("Mike"), int (30), double (56.4));

    Print (first_person);
    Print (second_person);

    first_person.get <1> () += 1;

    cout << "Incremented age of John by 1 \n";

    Print (first_person);
    return 0;
}