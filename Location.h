//
// Created by tienl on 23/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_LOCATION_H
#define ASSIGNMENT2CSCI251_LOCATION_H

#include <iostream>
#include "SFeature.h"

class Location {
private:
    std::string name;
    SFeature* sFeature;
public:
    Location(const std::string &name,  SFeature &sFeature);
    ~Location();
    const std::string &getName() const;

    void setName(const std::string &name);

    const SFeature *getSFeature() const;

};


#endif //ASSIGNMENT2CSCI251_LOCATION_H
