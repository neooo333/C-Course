#ifndef SHAPE_VARIANT_H
#define SHAPE_VARIANT_H

#include "boost/variant.hpp"
#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"

typedef boost::variant<Mikita::CAD::Point, Mikita::CAD::Circle, Mikita::CAD::Line> ShapeType;

ShapeType ShapeVariant();

#endif
