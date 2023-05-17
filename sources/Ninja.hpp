//
// Created by malaklinux on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_A_NINJA_HPP
#define COWBOY_VS_NINJA_A_NINJA_HPP

#include "Character.hpp"

constexpr int Ninja_SlashDamage = 40;

using namespace std;
namespace ariel {
    class Ninja : public Character {
    private:
        int speed;
    public:
        Ninja(string name, Point location, int hitPoints, int speed);

        void move(Character *enemy);

        void slash(Character *enemy);

        int getSpeed();

        string print();

    };
}
#endif //COWBOY_VS_NINJA_A_NINJA_HPP
