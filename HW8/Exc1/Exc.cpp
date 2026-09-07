#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <iostream>
#include "Shape.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "Line.hpp"


using namespace std;
using Mikita::CAD::Shape;
using Mikita::Containers::Array;
using Mikita::CAD::Point;
using Mikita::CAD::Line;

int main (){

    typedef boost::shared_ptr<Shape> ShapePtr;
    typedef Array <ShapePtr> ShapeArray;

    ShapeArray test_array (3); 

    test_array [0] = boost::make_shared <Point> ();
    test_array [1] = boost::make_shared <Point> (1, 2);
    test_array [2] = boost::make_shared <Line> (Point (1,1), Point (2,2));

    cout <<  test_array [0] -> ToString() <<endl;
    cout <<  test_array [1] -> ToString()<<endl;
    cout <<  test_array [2] -> ToString()<<endl;

    cout << "use_count [0]: " << test_array[0].use_count() << endl;
    cout << "use_count [1]: " << test_array[1].use_count() << endl;
    cout << "use_count [2]: " << test_array[2].use_count() << endl;

    cout << "resetting [0]" << endl;
    test_array[0].reset();  // last owner → Point deleted now
    cout << "after reset [0], use_count: " << test_array[0].use_count() << endl;

    cout << "resetting [1]" << endl;
    test_array[1].reset();
    cout << "after reset [1], use_count: " << test_array[1].use_count() << endl;

    cout << "resetting [2]" << endl;
    test_array[2].reset();

    cout << "after reset [2], use_count: " << test_array[2].use_count() << endl;

    return 0;
}
