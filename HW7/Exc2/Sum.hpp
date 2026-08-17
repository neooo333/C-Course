#ifndef SUM_HPP
#define SUM_HPP

#include <map>


using namespace std;


template <typename T> 
double Sum (const T& container){

    double total = 0;

    typename T::const_iterator it;
    typename T::const_iterator end_it =  container.end ();


    for (it = container.begin (); it != end_it; ++it){
        total += (*it);
    }

    return total;
}


template <typename I>
double Sum (I begin_iterator, I end_iterator){

    double total = 0;
    for (I it = begin_iterator; it != end_iterator; it++){
        total += (*it);
    }

    return total;
}


template <typename K, typename V>
double Sum (const map <K, V>& container){
    double total = 0;

    typename map<K, V>::const_iterator it;
    typename map<K, V>::const_iterator end_it = container.end ();

    for (it = container.begin(); it != end_it; it++){
        total += it->second;
    }


    return total;
}



template <typename K, typename V>
double Sum (typename map<K, V>::iterator begin_iterator,
     typename map<K, V>::iterator end_iterator){

    double total = 0;

    for (typename map<K, V>::iterator it = begin_iterator; it != end_iterator; it++){
        total += it->second;
    }
    return total;
}

#endif
