//
// Created by tienl on 24/10/2020.
//

#include "Physio.h"
#include <random>
Physio::Physio(std::string name) : TeamStaff(name) {}
void Physio::improveEndurance(Athlete &athlete) {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_real_distribution<double> randURD(impact- 1, impact-0.5);

    double realImpact = randURD(randEng);
    athlete.setEndurance(athlete.getEndurance() + realImpact);
}

void Physio::reportTeamStaffInfo() {
    std::cout << "*Physio therapist information:*" << std::endl
              << "-Name: " << name << std::endl
              << "-Impact on endurance: " << impact << std::endl;
}