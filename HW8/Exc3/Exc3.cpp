#include "boost/variant.hpp"
#include <iostream>
#include "ShapeVariant.hpp"
#include "Visitor.hpp"
#include "Line.hpp"

using namespace Mikita::CAD;
using namespace std;

int main() {
    ShapeType shape = ShapeVariant();

    cout << "Created shape:" << endl;
    boost::apply_visitor(PrintVisitor(), shape);

    cout << endl << "Trying boost::get<Line>(shape):" << endl;
    try {
        Line l = boost::get<Line>(shape);
        cout << "Success: " << l.ToString() << endl;
    } catch (boost::bad_get&) {
        cout << "Variant does not contain a Line." << endl;
    }

    cout << endl << "Moving shape by (1, 2):" << endl;
    boost::apply_visitor(MoveVisitor(1.0, 2.0), shape);

    cout << "Shape after move:" << endl;
    boost::apply_visitor(PrintVisitor(), shape);

    return 0;
}
