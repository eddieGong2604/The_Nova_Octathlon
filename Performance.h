//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_PERFORMANCE_H
#define ASSIGNMENT2CSCI251_PERFORMANCE_H


#include "Athlete.h"
#include "FieldEvent.h"
#include "TrackEvent.h"
#include "InjurySys.h"

class Performance {
private:
    Athlete *athlete;
    Event *event;
    double result;
public:
    Performance(Athlete &athlete, Event *event, InjurySys *injurySys);
    ~Performance();
    Athlete *getAthlete() const;

    void setAthlete(Athlete *athlete);

    Event *getEvent() const;

    void setEvent(Event *event);

    double getPerformance();

    double getResult() const;

    void awardPointsToAthlete();

    static double calPerformance(double,double);

};


#endif //ASSIGNMENT2CSCI251_PERFORMANCE_H
