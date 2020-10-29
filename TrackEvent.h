//
// Created by tienl on 23/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_TRACKEVENT_H
#define ASSIGNMENT2CSCI251_TRACKEVENT_H


#include "Event.h"

class TrackEvent: public Event {
private:
    //the length of the track event is recorded to later calculate points
    double lengthOfTheRace;
public:
    TrackEvent(const std::string &name, EventType eventType, double impactResistancy, double lengthOfTheRace);
    ~TrackEvent(){

    }
    double getDifficulty();
    void setLengthOfTheRace(double lengthOfTheRace);
};


#endif //ASSIGNMENT2CSCI251_TRACKEVENT_H
