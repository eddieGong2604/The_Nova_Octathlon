//
// Created by tienl on 23/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_SFEATURE_H
#define ASSIGNMENT2CSCI251_SFEATURE_H

#include <iostream>
#include "EventType.h"

class SFeature {
private:
    std::string name;
    double impact;
    EventType affectEventType;
public:
    SFeature(std::string, EventType, double);

    const std::string &getName() const;

    void setName(const std::string &name);

    double getImpact() const;

    void setImpact(double impact);

    EventType getAffectEventType() const;

    void setAffectEventType(EventType affectEventType);

    friend std::ostream &operator<<(std::ostream &os, const SFeature &feature);
};


#endif //ASSIGNMENT2CSCI251_SFEATURE_H
