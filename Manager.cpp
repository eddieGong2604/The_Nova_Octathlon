//
// Created by tienl on 24/10/2020.
//

#include "Manager.h"

Manager::Manager(std::string name) : TeamStaff(name) {}

void Manager::reportTeamStaffInfo() {
    std::cout << "*Manager information:*" << std::endl
              << "-Name: " << name << std::endl;
}