//
// Created by tienl on 24/10/2020.
//

#include "SportPsy.h"
#include <random>

SportPsy::SportPsy(std::string name) : TeamStaff(name) {}
void SportPsy::improveMentalHealth(Athlete &athlete) {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_real_distribution<double> randURD(impact- 1, impact-0.5);

    double realImpact = randURD(randEng);
    athlete.setMental(athlete.getMental() + realImpact);
  

}

void SportPsy::reportTeamStaffInfo() {
    std::cout << "*Sport Psychologist information:*" << std::endl
              << "-Name: " << name << std::endl
              << "-Impact mental health: " << impact << std::endl;
}