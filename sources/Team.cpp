//
// Created by malaklinux on 5/5/23.
//
#include "Team.hpp"

namespace ariel {
    Team::Team(Character *leader) : leader(leader) {
        //fighters[numberOfFighters++] = leader;
        fighters.at(numberOfFighters++) = leader;
    }


    Team::~Team() {
        size_t i = 0;
        while (i < numberOfFighters) {
            delete fighters.at(i);
            i++;
        }
    }


    void Team::add(Character *fighter) {
        fighters.at(numberOfFighters++) = fighter;
    }

    void Team::attack(Team *enemyTeam) {
    }

    int Team::stillAlive() {
        return 0;
    }

    void Team::print() {
    }

    unsigned long Team::getNumberOfFighters() {
        return numberOfFighters;
    }
}