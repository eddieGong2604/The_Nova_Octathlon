//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_INJURYSYS_H
#define ASSIGNMENT2CSCI251_INJURYSYS_H

#include <vector>
#include "Injury.h"

class InjurySys {
private:
    std::vector<Injury*> injuries;
public:
    InjurySys();
    ~InjurySys();
    Injury* getInjury();
};


#endif //ASSIGNMENT2CSCI251_INJURYSYS_H
