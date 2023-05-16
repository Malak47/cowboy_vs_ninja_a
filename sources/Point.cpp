//
// Created by malaklinux on 5/5/23.
//

#include "Point.hpp"
#include <cmath>

namespace ariel {
    Point::Point() : x(0), y(0) {}

    Point::Point(double x, double y) : x(x), y(y) {}

    double Point::distance(Point other) const {
        return sqrt((pow((x - other.x), 2)) + (pow((y - other.y), 2)));
    }

    double Point::getX() const {
        return x;
    }

    void Point::setX(double x) {
        //Point::x = x;
        this->x = x;
    }

    double Point::getY() const {
        return y;
    }

    void Point::setY(double y) {
        //Point::y = y
        this->y = y;
    }

    void Point::print() const {
        cout << "(" << this->x << "," << this->y << ")";
    }

    Point Point::moveTowards(Point source, Point destination, double distance) {
        return {0, 0};
    }

}