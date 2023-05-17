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
        double xNum, yNum;

    public:
        Point();

        Point(double xNum, double yNum);

        double distance(Point other);

        void print();

        double getX();

        void setX(double xNum);

        double getY();

        void setY(double yNum);

        static Point moveTowards(Point source, Point destination, double distance);

    };
}
#endif //COWBOY_VS_NINJA_A_POINT_HPP
