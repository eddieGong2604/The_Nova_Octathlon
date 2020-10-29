//
// Created by tienl on 24/10/2020.
//

#include "TrackTrainer.h"
#include <random>
TrackTrainer::TrackTrainer(std::string name) : TeamStaff(name) {}
void TrackTrainer::improveTrackPerformance(Athlete &athlete) {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_real_distribution<double> randURD(impact- 1, impact- 0.5);

    double realImpact = randURD(randEng);
    athlete.setAccelaration(athlete.getAccelaration() + realImpact);


}
void TrackTrainer::reportTeamStaffInfo() {
    std::cout << "*Track Trainer information:*" << std::endl
              << "-Name: " << name << std::endl
              << "-Impact on accelaration: " << impact << std::endl;
}