//
// Created by tienl on 24/10/2020.
//

#include "TeamStaff.h"

#include <random>

TeamStaff::TeamStaff(std::string aname) {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_real_distribution<double> randURD(1.1, 1.5);
    name = aname;
    impact = randURD(randEng);
}

std::string TeamStaff::getName() const {
    return name;
}

void TeamStaff::setName(std::string name) {
    TeamStaff::name = name;
}

double TeamStaff::getImpact() const {
    return impact;
}

void TeamStaff::setImpact(double impact) {
    TeamStaff::impact = impact;
}
