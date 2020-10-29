//
// Created by tienl on 23/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_FIELDEVENT_H
#define ASSIGNMENT2CSCI251_FIELDEVENT_H


#include "Event.h"

class FieldEvent: public Event {
private:
    //athlete will utilize his strength to throw this object as far as possible
    //for high jump, athlete has to "throw" him self as high as possible
    double weightOfObject;
public:
    FieldEvent(const std::string &name, EventType eventType, double impactResistancy, double weightOfObject);
    ~FieldEvent(){

    };
    double getDifficulty();

    void setWeightOfObject(double weightOfObject);
};


#endif //ASSIGNMENT2CSCI251_FIELDEVENT_H
