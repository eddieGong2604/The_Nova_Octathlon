//
// Created by tienl on 24/10/2020.
//

#include "FieldTrainer.h"
#include <random>
FieldTrainer::FieldTrainer(std::string name) : TeamStaff(name) {}

void FieldTrainer::improveFieldPerformance(Athlete &athlete) {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_real_distribution<double> randURD(impact- 1, impact-0.5);

    double realImpact = randURD(randEng);
    athlete.setWeight(athlete.getWeight() + realImpact);


}

void FieldTrainer::reportTeamStaffInfo() {
    std::cout << "*Field Trainer information:*" << std::endl
              << "-Name: " << name << std::endl
              << "-Impact on weight: " << impact << std::endl;
}