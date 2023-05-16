//
// Created by malaklinux on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_A_TRAINEDNINJA_HPP
#define COWBOY_VS_NINJA_A_TRAINEDNINJA_HPP
#include "Ninja.hpp"

#define TrainedNinja_HitPoints 120
#define TrainedNinja_SlashSpeed 12

using namespace std;

namespace ariel {
    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(string name, Point location);
    };
}
#endif //COWBOY_VS_NINJA_A_TRAINEDNINJA_HPP
