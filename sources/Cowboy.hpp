//
// Created by malaklinux on 5/5/23.
//

#ifndef COWBOY_VS_NINJA_A_COWBOY_HPP
#define COWBOY_VS_NINJA_A_COWBOY_HPP

#include "Character.hpp"

#define Cowboy_HitPoints 110
#define Cowboy_Bullets 6
#define Cowboy_shotDamage 10

using namespace std;
namespace ariel {
    class Cowboy : public Character{
    private:
        int bullets;
    public:
        Cowboy(string name, Point location);

        void shoot(Character *enemy);

        bool hasBullets() const;

        void reload();

        bool hasBoolets() const;

        string print();

    };
}
#endif //COWBOY_VS_NINJA_A_COWBOY_HPP
