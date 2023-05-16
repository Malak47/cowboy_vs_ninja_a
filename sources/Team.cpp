//
// Created by malaklinux on 5/5/23.
//
#include "Team.hpp"

namespace ariel {
    Team::Team(Character *leader) : leader(leader) {}

    Team::~Team() {}

    void Team::add(Character *fighter) {
    }

    void Team::attack(Team *enemyTeam) {
    }

    int Team::stillAlive() {
        return 0;
    }

    void Team::print() {
    }
}