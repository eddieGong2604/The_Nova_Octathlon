//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_SPORTPSY_H
#define ASSIGNMENT2CSCI251_SPORTPSY_H


#include "TeamStaff.h"
#include "Athlete.h"

class SportPsy: private TeamStaff{
public:
    SportPsy(std::string name);
    ~SportPsy(){};
    void improveMentalHealth(Athlete&athlete);
    void reportTeamStaffInfo();
};


#endif //ASSIGNMENT2CSCI251_SPORTPSY_H
