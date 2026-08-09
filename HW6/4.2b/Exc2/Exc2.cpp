#include "numeric_array.hpp"
#include "array_exception.hpp"
#include "point.hpp"
#include <iostream>

using namespace Mikita::Containers;
using Mikita::CAD::Point;
using namespace std;

int main (){
    //Default and size constructors
    NumericArray<double> a;

    NumericArray<double> b(5);
    NumericArray<double> c(5);

    // Fill arrays
    for (int i = 0; i < b.Size();  i++){
        b[i] = i + 1;       
        c[i] = (i + 1) * 2; 
    }

    // Assignment
    a = b;
    cout << "After a = b, a: ";
    for (int i = 0; i < a.Size(); i++) cout << a[i] << " ";
    cout << endl;

    // Scaling: b * 3 
    NumericArray<double> scaled = b * 3.0;
    cout << "b * 3: ";
    for (int i = 0; i < scaled.Size(); i++) cout << scaled[i] << " ";
    cout << endl;

    // Addition: b + c 
    NumericArray<double> sum = b + c;
    cout << "b + c: ";
    for (int i = 0; i < sum.Size(); i++) cout << sum[i] << " ";
    cout << endl;

    // Dot product: 1*2 + 2*4 + 3*6 + 4*8 + 5*10 = 110
    cout << "DotProduct(b, c): " << b.DotProduct(c) << endl;

    // Exception: different sizes
    try {
        NumericArray<double> shortArr(3);
        NumericArray<double> result = b + shortArr;
    } catch (const ArrayException& e){
        cout << "Caught on +: " << e.GetMessage() << endl;
    }

    try {
        NumericArray<double> shortArr(2);
        cout << b.DotProduct(shortArr) << endl;
    } catch (const ArrayException& e){
        cout << "Caught on DotProduct: " << e.GetMessage() << endl;
    }

    // A NumericArray<Point> can be constructed because Point has a default
    // constructor, copy operations, operator+, and multiplication by a double.
    NumericArray<Point> points1(2);
    NumericArray<Point> points2(2);
    points1[0] = Point(1.0, 2.0);
    points1[1] = Point(3.0, 4.0);
    points2[0] = Point(5.0, 6.0);
    points2[1] = Point(7.0, 8.0);

    NumericArray<Point> pointSum = points1 + points2;
    NumericArray<Point> scaledPoints = points1 * 2.0;
    cout << "Point sum: " << pointSum[0] << " " << pointSum[1] << endl;
    cout << "Scaled points: " << scaledPoints[0] << " "
         << scaledPoints[1] << endl;

    // This does not compile:
    // double pointDotProduct = points1.DotProduct(points2);
    //
    // DotProduct multiplies corresponding elements with Point * Point and adds
    // the result to a double. Point only defines Point * double, so a dot
    // product for Point has no defined meaning with the current Point interface.

    return 0;
}
