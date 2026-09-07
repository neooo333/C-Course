#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include "Point.hpp"
#include <iostream>

using namespace Mikita::Containers;
using Mikita::CAD::Point;
using namespace std;

int main (){

    
    NumericArray<double> a;

    NumericArray<double> b(5);
    NumericArray<double> c(5);



    for (int i = 0; i < b.Size();  i++){

        b[i] =i + 1;       
        c[i] = (i + 1) * 2; 
    }

    // assignment
    a = b;
    cout << "After a = b, a: ";
    for (int i = 0; i < a.Size(); i++) cout << a[i] << " ";
    cout << endl;

    // Scaling.
    NumericArray<double> scaled = b * 3.0;
    cout << "b * 3: ";
    for (int i = 0; i < scaled.Size(); i++) cout << scaled[i] << " ";
    cout << endl;


    // addition
    NumericArray<double> sum = b + c;
    cout << "b + c: ";
    for (int i = 0; i < sum.Size(); i++) cout << sum[i] << " ";
    cout << endl;

    // Dot product
    cout << "DotProduct(b, c): " << b.DotProduct(c) << endl;

    // different sizes
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

    // A NumericArray<Point> can be constructed with Point instances

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

    //below does not compile 
    // double pointDotProduct = points1.DotProduct(points2);
    // Point only defines Point * double, so a dot product for Point has no defined meaning with the current Point interface.

    return 0;
}
