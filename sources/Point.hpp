//
// Created by malaklinux on 5/5/23.
//

#ifndef COWBOY_VS_NINJA_A_POINT_HPP
#define COWBOY_VS_NINJA_A_POINT_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

using namespace std;
namespace ariel {
    class Point {
    private:
        double x, y;

    public:
        Point();

        Point(double x, double y);

        double distance(Point other) const;

        void print() const;

        double getX() const;

        void setX(double x);

        double getY() const;

        void setY(double y);

        static Point moveTowards(Point source, Point destination, double distance);

    };
}
#endif //COWBOY_VS_NINJA_A_POINT_HPP
