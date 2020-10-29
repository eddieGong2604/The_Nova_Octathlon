//
// Created by tienl on 24/10/2020.
//

#include "InjurySys.h"
#include <random>
InjurySys::InjurySys() {
    Injury *brokenLeg = new Injury("leg broken", 7);
    Injury *brokenArm= new Injury("arm broken", 6);
    Injury *strain = new Injury("strain", 5);
    injuries.push_back(brokenArm);
    injuries.push_back(brokenLeg);
    injuries.push_back(strain);
}
InjurySys::~InjurySys() {
    for(auto a : injuries){
        delete a;
    }
    injuries.clear();
}
Injury* InjurySys::getInjury() {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_int_distribution<int> randURD(0, 29);
    //injury rate is 10%
    int index = randURD(randEng);
    if(index < 2){
        return injuries[index];
    }
    else{
        return NULL;
    }
}