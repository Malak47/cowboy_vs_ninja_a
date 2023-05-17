//
// Created by malaklinux on 5/16/23.
//
#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;

TEST_SUITE("Point methods tests") {
    Point p1{};
    Point p2{};
    Point p3{1, 2};
    Point p4 = {-1 * p3.getX(), -1 * p3.getY()}; //(-1,-2)
    Point p5{3, 4};
    Point p6{p5.getX(), p5.getY()}; //(3,4)


    TEST_CASE("Distance method") {
        CHECK_EQ(p1.distance(p3), p3.distance(p1));
        CHECK_EQ(p4.distance(p3), p3.distance(p4));
        CHECK_EQ(p6.distance(p1), p2.distance(p5));

        CHECK_EQ(p1.distance(p1), 0);
        CHECK_EQ(p2.distance(p1), 0);
        CHECK_EQ(p3.distance(p1), 2.236068);
        CHECK_EQ(p4.distance(p3), 4.472136);
        CHECK_EQ(p4.distance(p5), 7.211103);
        CHECK_EQ(p5.distance(p6), 0);
    }

    TEST_CASE("moveTowards method") {
        CHECK_EQ(p1.distance(p5), doctest::Approx(5.0));
        Point::moveTowards(p1, p5, 3.0);
        CHECK_EQ(p1.distance(p5), doctest::Approx(2.0));
    }

    TEST_CASE("Getters & Setters") {
        //Get
        CHECK_EQ(p1.getX(), p2.getX());
        CHECK_EQ(p4.getX(), -1 * p3.getX());
        CHECK_EQ(p6.getY(), 4);
        CHECK_EQ(p5.getY(), p6.getY());

        //Set
        p1.setX(20);
        p4.setX(p6.getX());
        p6.setY(p1.getX());
        p5.setY(2);
        CHECK_EQ(p1.getX(), 20);
        CHECK_EQ(p4.getX(), 3);
        CHECK_EQ(p6.getY(), 20);
        CHECK_EQ(p5.getY(), 2);
    }
}
TEST_SUITE("Character methods tests") {
    Character char1 = {"Malak", {5, 3}, 150};
    Character char2 = {"Loly", {1, 2}, 120};
    Character char3 = {"NewMalak", {5, 3}, 150};
    Character *cowboy = new Cowboy{"CowBoy", {1, 1}};
    TrainedNinja trainedNinja = {"TrainedNinja", {1, 1}};
    Character *ninja1 = new Ninja{trainedNinja.getName(), trainedNinja.getLocation(), trainedNinja.getHitPoints(),
                                  trainedNinja.getSpeed()};
    Character *ninja2 = new OldNinja("OldNinja", {3, 4});


    TEST_CASE("isAlive method") {
        CHECK_FALSE(!char1.isAlive());
        CHECK_FALSE(!char2.isAlive());
        CHECK_FALSE(!cowboy->isAlive());
        CHECK_FALSE(!ninja1->isAlive());
        CHECK_FALSE(!ninja2->isAlive());
        while (char1.getHitPoints() > 0) {
            char1.hit(10);
        }
        CHECK_FALSE(char1.isAlive());
    }

    TEST_CASE("distance method") {
        CHECK_EQ(char1.distance(&char2), 4.123106);
        CHECK_EQ(char2.distance(&char1), 4.123106);
        CHECK_EQ(char2.distance(&char2), 0);
        CHECK_EQ(char1.distance(&char1), 0);
    }

    TEST_CASE("hit method") {
        char3.hit(50);
        CHECK_EQ(char2.getHitPoints(), 120);
        CHECK_EQ(char3.getHitPoints(), 100);
    }

    TEST_CASE("getName method") {
        CHECK_EQ(char1.getName(), "Malak");
        CHECK_EQ(char2.getName(), "Loly");
        CHECK_EQ(char3.getName(), "NewMalak");
        CHECK_EQ(cowboy->getName(), "CowBoy");
        CHECK_EQ(ninja1->getName(), "TrainedNinja");
        CHECK_EQ(ninja2->getName(), "OldNinja");
    }

    TEST_CASE("getLocation method") {
        CHECK_EQ(char2.getLocation().getX(), 1);
        CHECK_EQ(char2.getLocation().getY(), 2);
        CHECK_EQ(char3.getLocation().getX(), 5);
        CHECK_EQ(char3.getLocation().getY(), 3);
    }

    TEST_CASE("getHitPoints method") {
        CHECK_EQ(char1.getHitPoints(), 0);
        CHECK_EQ(char2.getHitPoints(), 120);
        CHECK_EQ(char3.getHitPoints(), 100);
        CHECK_EQ(cowboy->getHitPoints(), 110);
        CHECK_EQ(ninja1->getHitPoints(), 120);
        CHECK_EQ(ninja2->getHitPoints(), 120);
    }

}
TEST_SUITE("CowBoy methods tests") {

    Cowboy cowboy1 = {"cowboy1", {1, 2}};
    Cowboy cowboy2 = {"cowboy2", {5, -2}};
    Cowboy cowboy3 = {"cowboy3", {2, -2}};


    TEST_CASE("shoot method") {
        CHECK_THROWS(cowboy1.shoot(&cowboy1));
        cowboy1.shoot(&cowboy2);
        CHECK_FALSE(!cowboy2.isAlive());
        while (cowboy2.getHitPoints() > 0) {
            cowboy1.shoot(&cowboy2);
            if (!cowboy1.hasBullets()) {
                cowboy1.reload();
            }
        }
        CHECK_FALSE(cowboy2.isAlive());

    }

    TEST_CASE("hasBullets method") {
        cowboy1.reload();
        int i = 0;
        while (i < 6) {
            cowboy1.shoot(&cowboy3); //50
            i++;
        }
        CHECK_EQ(cowboy1.getBulletsLeft(), 0);
        CHECK_FALSE(cowboy1.hasBullets());
        CHECK_FALSE(!cowboy3.hasBullets());
    }

    TEST_CASE("reload method") {
        cowboy1.reload();
        CHECK_EQ(cowboy1.getBulletsLeft(), 6);
        cowboy1.shoot(&cowboy3);        //40
        CHECK_EQ(cowboy1.getBulletsLeft(), 5);
        cowboy1.shoot(&cowboy3);        //30
        CHECK_EQ(cowboy1.getBulletsLeft(), 4);
        cowboy1.shoot(&cowboy3);        //20
        CHECK_EQ(cowboy1.getBulletsLeft(), 3);
        cowboy1.shoot(&cowboy3);        //10
        CHECK_EQ(cowboy1.getBulletsLeft(), 2);
    }

}
TEST_SUITE("Ninja methods tests") {
    OldNinja oldNinja = {"oldNinja", {1, 2}};
    TrainedNinja trainedNinja = {"trainedNinja", {5, -2}};
    YoungNinja youngNinja = {"youngNinja", {2, -2}};

    TEST_CASE("slash method") {
        CHECK_THROWS(oldNinja.slash(&oldNinja));
        oldNinja.slash(&trainedNinja);
        CHECK_FALSE(!trainedNinja.isAlive());
//        while (oldNinja.distance(&trainedNinja) > 1) {
//            oldNinja.move(&trainedNinja);
//        }
//        while (trainedNinja.getHitPoints() > 0) {
//            oldNinja.slash(&trainedNinja);
//        }
        CHECK_FALSE(trainedNinja.isAlive());
    }

    TEST_CASE("move method") {
//        while (oldNinja.distance(&youngNinja) > 1) {
//            oldNinja.move(&youngNinja);
//        }
        CHECK_FALSE(oldNinja.distance(&youngNinja) > 1);
        CHECK_FALSE(youngNinja.distance(&oldNinja) > 1);
    }

    TEST_CASE("getSpeed method") {
        CHECK_EQ(oldNinja.getSpeed(), 8);
        CHECK_EQ(trainedNinja.getSpeed(), 12);
        CHECK_EQ(youngNinja.getSpeed(), 14);
    }
}

TEST_SUITE("Team methods tests") {
    Cowboy cowboy1 = {"cowboy1", {1, 2}};
    Cowboy cowboy2 = {"cowboy2", {5, -2}};
    Cowboy cowboy3 = {"cowboy3", {2, -2}};

    Cowboy cowboy4 = {"cowboy4", {1, 3}};
    Cowboy cowboy5 = {"cowboy5", {7, -2}};
    Cowboy cowboy6 = {"cowboy6", {-2, -2}};

    OldNinja oldNinja1 = {"oldNinja1", {0, 2}};
    OldNinja oldNinja2 = {"oldNinja2", {2, 9}};
    TrainedNinja trainedNinja1 = {"trainedNinja1", {25, -12}};
    TrainedNinja trainedNinja2 = {"trainedNinja2", {15, -1}};
    YoungNinja youngNinja1 = {"youngNinja1", {2, -5}};
    YoungNinja youngNinja2 = {"youngNinja2", {9, -10}};
    //cowboy1,cowboy2,cowboy3,cowboy4,cowboy5,cowboy6,oldNinja1,oldNinja2,trainedNinja1,trainedNinja2
    TEST_CASE("add & stillAlive methods") {
        Team team = {&cowboy1};
        Team2 team2 = {&youngNinja2};

        CHECK_EQ(team.stillAlive(), 1);
        team.add(&cowboy2);
        CHECK_EQ(team.stillAlive(), 2);
        team.add(&cowboy3);
        CHECK_EQ(team.stillAlive(), 3);
        team.add(&cowboy4);
        CHECK_EQ(team.stillAlive(), 4);
        team.add(&cowboy5);
        CHECK_EQ(team.stillAlive(), 5);
        team.add(&cowboy6);
        CHECK_EQ(team.stillAlive(), 6);
        team.add(&oldNinja1);
        CHECK_EQ(team.stillAlive(), 7);
        team.add(&oldNinja2);
        CHECK_EQ(team.stillAlive(), 8);
        team.add(&trainedNinja1);
        CHECK_EQ(team.stillAlive(), 9);
        team.add(&trainedNinja2);
        CHECK_EQ(team.stillAlive(), 10);

        CHECK_THROWS(team.add(&youngNinja1));

        CHECK_THROWS(team2.add(&cowboy1));
        CHECK_THROWS(team2.add(&cowboy2));
        CHECK_THROWS(team2.add(&youngNinja2));
    }

    TEST_CASE("attack method") {
        Team team = {&cowboy1};
        Team2 team2 = {&oldNinja1};
        SmartTeam team3 = {&youngNinja1};
        SmartTeam team4 = {&trainedNinja1};

        team.add(&cowboy2);
        team.add(&cowboy3);
        team.add(&cowboy4);
        team.add(&cowboy5);
        team.add(&cowboy6);

        team2.add(&oldNinja2);

        team3.add(&youngNinja2);

        team4.add(&trainedNinja2);

        team.attack(&team2);
        team3.attack(&team2);
        team4.attack(&team2);

        CHECK_EQ(team2.stillAlive(), 0);
    }
}