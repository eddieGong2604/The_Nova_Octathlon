//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_TRACKTRAINER_H
#define ASSIGNMENT2CSCI251_TRACKTRAINER_H


#include "TeamStaff.h"
#include "Athlete.h"

class TrackTrainer : private TeamStaff{
public:
    TrackTrainer(std::string name);
    ~TrackTrainer(){

    };
    void improveTrackPerformance(Athlete&athlete);
    void reportTeamStaffInfo();

};


#endif //ASSIGNMENT2CSCI251_TRACKTRAINER_H
