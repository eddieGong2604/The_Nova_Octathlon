//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_ATHLETE_H
#define ASSIGNMENT2CSCI251_ATHLETE_H

#include <iostream>
#include "Gender.h"
#include "Event.h"
#include "Location.h"
#include "Weather.h"
#include "Injury.h"


class Athlete {
private:
    std::string name;
    Gender gender;
    //psychologist takes care of mental
    double mental;
    //physio takes care of endurance
    double endurance;

    //trainer field take care of weight
    double weight;

    //trainer track take care of accelaration
    double accelaration;


    //attributes used to calculate performance points
    double avrSpeed;
    double avrStrength;

    //points related
    double meetPoint;
    double totalPoints;

public:
    Athlete(std::string, Gender);
    const std::string &getName() const;

    void setName(const std::string &name);

    Gender getGender() const;

    void setGender(Gender gender);

    double getMental() const;

    void setMental(double mental);

    double getEndurance() const;

    void setEndurance(double endurance);

    double getWeight() const;

    void setWeight(double weight);

    double getAccelaration() const;

    void setAccelaration(double accelaration);

    double getAvrSpeed() const;

    void setAvrSpeed(double avrSpeed);

    double getAvrStrength() const;

    void setAvrStrength(double avrStrength);

    double getMeetPoint() const;

    void setMeetPoint(double meetPoint);

    double getTotalPoints() const;

    void setTotalPoints(double totalPoints);

    void calculateSpeedAndStrength(Event);
    static double calculateSpeed(double, double , double , double);
    static double calculateStrength(double, double , double , double);

    void setInjury(Injury*);

    void reportInfoAthelete();

};


#endif //ASSIGNMENT2CSCI251_ATHLETE_H
