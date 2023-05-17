//
// Created byNum malaklinuxNum on 5/5/23.
//

#include "Point.hpp"
#include <cmath>

namespace ariel {
    Point::Point() : xNum(0), yNum(0) {}

    Point::Point(double xNumNum, double yNum) : xNum(xNumNum), yNum(yNum) {}

    double Point::distance(Point other) {
        return sqrt((pow((xNum - other.xNum), 2)) + (pow((yNum - other.yNum), 2)));
    }

    double Point::getX() {
        return xNum;
    }

    void Point::setX(double xNumNum) {
        //Point::xNum = xNum;
        this->xNum = xNumNum;
    }

    double Point::getY() {
        return yNum;
    }

    void Point::setY(double yNum) {
        //Point::yNum = yNum
        this->yNum = yNum;
    }

    void Point::print() {
        cout << "(" << this->xNum << "," << this->yNum << ")";
    }

    Point Point::moveTowards(Point source, Point destination, double distance) {
        return {0, 0};
    }

}