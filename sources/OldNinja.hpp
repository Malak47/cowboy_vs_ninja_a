//
// Created by malaklinux on 5/5/23.
//

#ifndef COWBOY_VS_NINJA_A_OLDNINJA_HPP
#define COWBOY_VS_NINJA_A_OLDNINJA_HPP


#include "Ninja.hpp"

#define OldNinja_HitPoints 150
#define OldNinja_SlashSpeed 8

using namespace std;

namespace ariel {
    class OldNinja : public Ninja {
    public:
        OldNinja(string name, Point location);
    };
}

#endif //COWBOY_VS_NINJA_A_OLDNINJA_HPP
