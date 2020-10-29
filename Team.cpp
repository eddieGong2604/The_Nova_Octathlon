//
// Created by tienl on 24/10/2020.
//

#include "Team.h"

Team::Team(const std::string &name, const Manager &manager, Athlete &maleAthlete, Athlete &femaleAthlete,
           const SportPsy &sportPsy, const Physio &physio, const TrackTrainer &trackTrainer,
           const FieldTrainer &fieldTrainer) : name(name), manager(manager), maleAthlete(&maleAthlete),
                                               femaleAthlete(&femaleAthlete), sportPsy(sportPsy), physio(physio),
                                               trackTrainer(trackTrainer), fieldTrainer(fieldTrainer) {}

const std::string &Team::getName() const {
    return name;
}

Team::~Team() {
    delete maleAthlete;
    delete femaleAthlete;
}
void Team::setName(const std::string &name) {
    Team::name = name;
}

const Manager &Team::getManager() const {
    return manager;
}

void Team::setManager(const Manager &manager) {
    Team::manager = manager;
}

Athlete *Team::getMaleAthlete() const {
    return maleAthlete;
}

void Team::setMaleAthlete(Athlete *maleAthlete) {
    Team::maleAthlete = maleAthlete;
}

Athlete *Team::getFemaleAthlete() const {
    return femaleAthlete;
}

void Team::setFemaleAthlete(Athlete *femaleAthlete) {
    Team::femaleAthlete = femaleAthlete;
}

const SportPsy &Team::getSportPsy() const {
    return sportPsy;
}

void Team::setSportPsy(const SportPsy &sportPsy) {
    Team::sportPsy = sportPsy;
}

const Physio &Team::getPhysio() const {
    return physio;
}

void Team::setPhysio(const Physio &physio) {
    Team::physio = physio;
}

const TrackTrainer &Team::getTrackTrainer() const {
    return trackTrainer;
}

void Team::setTrackTrainer(const TrackTrainer &trackTrainer) {
    Team::trackTrainer = trackTrainer;
}

const FieldTrainer &Team::getFieldTrainer() const {
    return fieldTrainer;
}

void Team::setFieldTrainer(const FieldTrainer &fieldTrainer) {
    Team::fieldTrainer = fieldTrainer;
}
void Team::recoverAndTrain() {

    //set meet points back to 0
    maleAthlete->setMeetPoint(0);
    femaleAthlete->setMeetPoint(0);
    //improve track performance
    trackTrainer.improveTrackPerformance(*maleAthlete);
    trackTrainer.improveTrackPerformance(*femaleAthlete);
    //improve field performance
    fieldTrainer.improveFieldPerformance(*maleAthlete);
    fieldTrainer.improveFieldPerformance(*femaleAthlete);
    //improve mental health
    sportPsy.improveMentalHealth(*maleAthlete);
    sportPsy.improveMentalHealth(*femaleAthlete);
    //improve readiness
    physio.improveEndurance(*maleAthlete);
    physio.improveEndurance(*femaleAthlete);
}


void Team::reportAllTeamInfo() {
    std::cout << std::endl;
    std::cout << "____TEAM: " << name << "____"<< std::endl;
    manager.reportTeamStaffInfo();
    std::cout << std::endl;
    maleAthlete->reportInfoAthelete();
    std::cout << std::endl;
    femaleAthlete->reportInfoAthelete();
    std::cout << std::endl;
    trackTrainer.reportTeamStaffInfo();
    std::cout << std::endl;
    fieldTrainer.reportTeamStaffInfo();
    std::cout << std::endl;
    physio.reportTeamStaffInfo();
    std::cout << std::endl;
    sportPsy.reportTeamStaffInfo();
    std::cout << std::endl;
}

void Team::reportAtheleInfoOnly() {
    std::cout << std::endl;
    std::cout << "____TEAM: " << name << "____"<< std::endl;
    maleAthlete->reportInfoAthelete();
    std::cout << std::endl;
    femaleAthlete->reportInfoAthelete();
    std::cout << std::endl;
}