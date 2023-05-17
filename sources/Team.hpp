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

constexpr int TeamMembers = 10;

using namespace std;
namespace ariel {
    class Team {
    private:
        Character *leader;
        array<Character *, TeamMembers> fighters;
        unsigned long numberOfFighters = 0;
    public:
        Team(Character *leader);

        void add(Character *fighter);

        void attack(Team *enemyTeam);

        int stillAlive();

        unsigned long getNumberOfFighters();

        void print();

        ~Team();

        Team (Team&) = delete; // Copy Constructor.
        Team (Team&&) noexcept = delete; // Move Constructor.
        Team& operator = (const Team&) = delete; // Copy assignment operator.
        Team& operator = (Team&&) noexcept = delete; // Move assignment operator.
    };
}

#endif //COWBOY_VS_NINJA_A_TEAM_HPP
