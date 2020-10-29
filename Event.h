//
// Created by tienl on 23/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_EVENT_H
#define ASSIGNMENT2CSCI251_EVENT_H

#include <iostream>
#include "EventType.h"
#include "Location.h"
#include "Weather.h"

class Event {
protected:
    std::string name;
    EventType eventType;
    double impactResistancy;
    //event condition impact on athlete
    double impact;
    //fields for calculate points
    double A;
    double B;
    double C;
public:
    Event(const std::string &name, EventType eventType, double impactResistancy);

    virtual ~Event();

    const std::string &getName() const;

    void setName(const std::string &name);

    EventType getEventType() const;

    void setEventType(EventType eventType);

    double getImpactResistancy() const;

    void setImpactResistancy(double impactResistancy);

    bool isEventAbleToHappen();

    void setABC(double a, double b, double c);

    double getB() const;

    double getImpact() const;

    void setImpact(Location&, Weather&);

    virtual double getDifficulty(){
        return 0;
    };

    double getA() const;

    double getC() const;
};


#endif //ASSIGNMENT2CSCI251_EVENT_H
