//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_PHYSIO_H
#define ASSIGNMENT2CSCI251_PHYSIO_H


#include "TeamStaff.h"
#include "Athlete.h"

class Physio: private TeamStaff {
public:
    Physio(std::string name);
    ~Physio(){};
    void improveEndurance(Athlete& athlete);
    void reportTeamStaffInfo();
};


#endif //ASSIGNMENT2CSCI251_PHYSIO_H
