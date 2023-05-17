//
// Created by malaklinux on 5/16/23.
//

#ifndef COWBOY_VS_NINJA_A_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_A_SMARTTEAM_HPP
#include "Team.hpp"

using namespace std;

namespace ariel {
    class SmartTeam : public Team {
    private:

    public:
        SmartTeam(Character *leader);

        void attack(Team *enemyTeam);

        void print();
    };
}
#endif //COWBOY_VS_NINJA_A_SMARTTEAM_HPP
