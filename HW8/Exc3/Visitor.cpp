#include "Visitor.hpp"
#include <iostream>

using namespace Mikita::CAD;
using namespace std;

void PrintVisitor::operator()(const Point& p) const {
    cout << p.ToString() << endl;
}

void PrintVisitor::operator()(const Circle& c) const {
    cout << c.ToString() << endl;
}

void PrintVisitor::operator()(const Line& l) const {
    cout << l.ToString() << endl;
}

MoveVisitor::MoveVisitor(double dx, double dy) : m_dx(dx), m_dy(dy) {}

void MoveVisitor::operator()(Point& p) const {
    p.X(p.X() + m_dx);
    p.Y(p.Y() + m_dy);
}

void MoveVisitor::operator()(Line& l) const {
    Point start = l.start_point();
    Point end = l.end_point();

    start.X(start.X() + m_dx);
    start.Y(start.Y() + m_dy);
    end.X(end.X() + m_dx);
    end.Y(end.Y() + m_dy);

    l.start_point(start);
    l.end_point(end);
}

void MoveVisitor::operator()(Circle& c) const {
    Point center = c.center();
    center.X(center.X() + m_dx);
    center.Y(center.Y() + m_dy);
    c.center(center);
}
