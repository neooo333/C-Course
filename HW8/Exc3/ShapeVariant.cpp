#include "ShapeVariant.hpp"
#include <iostream>
#include <string>

using namespace Mikita::CAD;
using namespace std;

ShapeType ShapeVariant() {
    string choice;

    cout << "Enter type of the object (Line, Circle, Point): ";
    cin >> choice;

    if (choice == "Line") {
        return Line();
    } else if (choice == "Circle") {
        return Circle();
    } else if (choice == "Point") {
        return Point();
    } else {
        cout << "Invalid choice, defaulting to Point." << endl;
        return Point();
    }
}
