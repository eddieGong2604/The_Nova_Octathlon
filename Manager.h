//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_MANAGER_H
#define ASSIGNMENT2CSCI251_MANAGER_H


#include "TeamStaff.h"

class Manager: private TeamStaff{
public:
    Manager(std::string name);
    void reportTeamStaffInfo();
    ~Manager(){};
};


#endif //ASSIGNMENT2CSCI251_MANAGER_H
