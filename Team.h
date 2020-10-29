//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_TEAM_H
#define ASSIGNMENT2CSCI251_TEAM_H

#include <iostream>
#include "Manager.h"
#include "Athlete.h"
#include "SportPsy.h"
#include "Physio.h"
#include "TrackTrainer.h"
#include "FieldTrainer.h"

class Team {
private:
    std::string name;
    Manager manager;
    Athlete *maleAthlete;
    Athlete *femaleAthlete;
    SportPsy sportPsy;
    Physio physio;
    TrackTrainer trackTrainer;
    FieldTrainer fieldTrainer;
public:
    Team(const std::string &name, const Manager &manager, Athlete &maleAthlete, Athlete &femaleAthlete,
         const SportPsy &sportPsy, const Physio &physio, const TrackTrainer &trackTrainer,
         const FieldTrainer &fieldTrainer);
    ~Team();
    const std::string &getName() const;

    void setName(const std::string &name);

    const Manager &getManager() const;

    void setManager(const Manager &manager);

    Athlete *getMaleAthlete() const;

    void setMaleAthlete(Athlete *maleAthlete);

    Athlete *getFemaleAthlete() const;

    void setFemaleAthlete(Athlete *femaleAthlete);

    const SportPsy &getSportPsy() const;

    void setSportPsy(const SportPsy &sportPsy);

    const Physio &getPhysio() const;

    void setPhysio(const Physio &physio);

    const TrackTrainer &getTrackTrainer() const;

    void setTrackTrainer(const TrackTrainer &trackTrainer);

    const FieldTrainer &getFieldTrainer() const;

    void setFieldTrainer(const FieldTrainer &fieldTrainer);

    void recoverAndTrain();
    void reportAllTeamInfo();

    void reportAtheleInfoOnly();
};


#endif //ASSIGNMENT2CSCI251_TEAM_H
