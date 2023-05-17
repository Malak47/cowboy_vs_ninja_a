//
// Created by malaklinux on 5/5/23.
//

#ifndef COWBOY_VS_NINJA_A_COWBOY_HPP
#define COWBOY_VS_NINJA_A_COWBOY_HPP

#include "Character.hpp"

constexpr int Cowboy_HitPoints = 110;
constexpr int Cowboy_Bullets = 6;
constexpr int Cowboy_shotDamage = 10;

using namespace std;
namespace ariel {
    class Cowboy : public Character {
    private:
        int bullets;
    public:
        Cowboy(string name, Point location);

        void shoot(Character *enemy);

        bool hasBullets();

        void reload();

        bool hasboolets();

        string print();

        int getBulletsLeft();

    };
}
#endif //COWBOY_VS_NINJA_A_COWBOY_HPP
