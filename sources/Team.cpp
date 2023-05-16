//
// Created by malaklinux on 5/5/23.
//
#include "Team.hpp"

namespace ariel {
    Team::Team(Character *leader) : leader(leader) {}

    Team::~Team() {}

    void Team::add(Character *fighter) {
        if (fighters.size() == 10) {
            throw invalid_argument("ERROR add(Character* fighter) :: Team is full.\n");
        } else {
            fighters[fighters.size() - 1] = fighter;
        }
    }

    void Team::attack(Team *enemyTeam) {
    }

    int Team::stillAlive() {
        return (int) fighters.size();
    }

    void Team::print() {
    }
}