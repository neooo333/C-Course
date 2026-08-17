#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <iostream>

int main() {
    boost::tuple<std::string, double, int> person("Ada", 3.14, 42);

    std::cout << "name:  " << person.get<0>() << "\n";
    std::cout << "value: " << person.get<1>() << "\n";
    std::cout << "id:    " << person.get<2>() << "\n";
    std::cout << "all:   " << person << "\n";
}