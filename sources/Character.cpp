//
// Created by malaklinux on 5/16/23.
//

#include "Character.hpp"

namespace ariel {
    Character::Character(string name, Point location, int hitPoints) : name(name), location(location),
                                                                       hitPoints(hitPoints) {}

    bool Character::isAlive() {
        return hitPoints > 0;
    }

    double Character::distance(Character *other) {
        return sqrt((pow((this->location.getX() - other->getLocation().getX()), 2)) +
                    (pow((this->location.getY() - other->getLocation().getY()), 2)));
    }

    void Character::hit(int hit) {
        hitPoints = hitPoints - hit;
    }

    string Character::getName() {
        return name;
    }

    Point Character::getLocation() {
        return location;
    }

    void Character::print() {
        /*if (!isAlive()) {
            if (hit)
                cout << "(" << name << ")";
            cout << endl;
            return;
        }
        cout << "Name: " << name << ", Hit Points: " << hitPoints << ", Location: ";
        location.print();
        cout << endl;*/
    }

    int Character::getHitPoints() {
        return hitPoints;
    }

}