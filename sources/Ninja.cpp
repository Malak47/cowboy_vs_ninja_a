//
// Created by malaklinux on 5/16/23.
//

#include "Ninja.hpp"

namespace ariel {

    Ninja::Ninja(string name, Point location, int hitPoints, int speed) : Character(name, location, hitPoints),
                                                                          speed(speed) {}

    void Ninja::move(Character *enemy) {
        return;
    }

    void Ninja::slash(Character *enemy) {
        if (this->isAlive() && distance(enemy) < 1) {
            enemy->hit(Ninja_SlashDamage);
        }
    }

    int Ninja::getSpeed() {
        return this->speed;
    }

    string Ninja::print() {
        if (!this->isAlive()) {
            return "N (" + this->getName() + ")\n";
        }
        return "Name: " + this->getName() +
               ", Hit Points: " + to_string(this->getHitPoints()) +
               ", Location: (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) +
               ")\n";
    }
}
