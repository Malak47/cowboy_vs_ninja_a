//
// Created by malaklinux on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_A_CHARACTER_HPP
#define COWBOY_VS_NINJA_A_CHARACTER_HPP

#include "Point.hpp"
#include <cmath>

using namespace std;
namespace ariel {
    class Character {
    private:
        Point location;
        int hitPoints;
        string name;

    public:
        Character(string name, Point location, int hitPoints);

        bool isAlive() const;

        double distance(Character *other) const;

        void hit(int hit);

        string getName();

        Point getLocation();

        void print();

        int getHitPoints() const;

    };
}
#endif //COWBOY_VS_NINJA_A_CHARACTER_HPP
