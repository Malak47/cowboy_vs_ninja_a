//
// Created by malaklinux on 5/5/23.
//

#ifndef COWBOY_VS_NINJA_A_TEAM_HPP
#define COWBOY_VS_NINJA_A_TEAM_HPP

#include <array>
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

#define TeamMembers 10

using namespace std;
namespace ariel {
    class Team {
    private:
        Character *leader;
        array<Character *, TeamMembers> fighters;
    public:
        Team(Character *leader);
        void add(Character *fighter);
        void attack(Team *enemyTeam);
        int stillAlive();
        void print();

        ~Team();
    };
}

#endif //COWBOY_VS_NINJA_A_TEAM_HPP
