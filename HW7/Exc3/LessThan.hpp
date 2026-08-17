#ifndef LESSTHAN
#define LESSTHAN

#include <utility>
#include <string>

using namespace std;


class LessThan {

    private:
        double threshold;
    
    public:

        LessThan (double value); // constructor

        ~LessThan (); //destructor

        bool operator () (double x) const; // () operator to be used in count_if for vector and list

        bool operator () (const pair<string, double>& pair_value) const; // () operator to be used in count_if for map


};
#endif