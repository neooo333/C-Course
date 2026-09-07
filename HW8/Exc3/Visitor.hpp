#ifndef VISITOR_H
#define VISITOR_H

#include "boost/variant.hpp"
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"

class PrintVisitor : public boost::static_visitor<void> {
public:

    void operator()(const Mikita::CAD::Point& p) const;
    void operator()(const Mikita::CAD::Circle& c) const;
    void operator()(const Mikita::CAD::Line& l) const;

};

class MoveVisitor : public boost::static_visitor<void> {
private:

    double m_dx;
    double m_dy;

public:

    MoveVisitor(double dx, double dy);

    void operator()(Mikita::CAD::Point& p) const;
    void operator()(Mikita::CAD::Line& l) const;
    void operator()(Mikita::CAD::Circle& c) const;
};

#endif
