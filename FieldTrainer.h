//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_FIELDTRAINER_H
#define ASSIGNMENT2CSCI251_FIELDTRAINER_H


#include "TeamStaff.h"
#include "Athlete.h"

class FieldTrainer: private TeamStaff{
public:
    FieldTrainer(std::string name);
    ~FieldTrainer(){};
    void improveFieldPerformance(Athlete& athlete);
    void reportTeamStaffInfo();
};


#endif //ASSIGNMENT2CSCI251_FIELDTRAINER_H
