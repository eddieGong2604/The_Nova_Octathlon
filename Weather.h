//
// Created by tienl on 23/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_WEATHER_H
#define ASSIGNMENT2CSCI251_WEATHER_H

#include <iostream>
#include "EventType.h"

class Weather {
private:
    std::string name;
    double impact;
    EventType affectEvent;
public:
    Weather(std::string, double, EventType);

    const std::string &getName() const;

    void setName(const std::string &name);

    double getImpact() const;

    void setImpact(double impact);

    EventType getAffectEvent() const;

    void setAffectEvent(EventType affectEvent);

    friend std::ostream &operator<<(std::ostream &os, const Weather &weather);
};


#endif //ASSIGNMENT2CSCI251_WEATHER_H
