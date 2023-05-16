//
// Created by malaklinux on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_A_YOUNGNINJA_HPP
#define COWBOY_VS_NINJA_A_YOUNGNINJA_HPP

#include "Ninja.hpp"

#define YoungNinja_HitPoints 100
#define YoungNinja_SlashSpeed 14

using namespace std;

namespace ariel {
    class YoungNinja : public Ninja {
    public:
        YoungNinja(string name, Point location);
    };
}
#endif //COWBOY_VS_NINJA_A_YOUNGNINJA_HPP
