//
// Created by tienl on 24/10/2020.
//

#include "Athlete.h"
#include "Location.h"
#include "Weather.h"

#include <random>

Athlete::Athlete(std::string athName, Gender agender) {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_real_distribution<double> randURD(75, 85);
    name = athName;
    mental = randURD(randEng);
    endurance = randURD(randEng);
    weight = randURD(randEng);
    accelaration = randURD(randEng);
    gender = agender;
    meetPoint = 0;
    totalPoints = 0;
}

double Athlete::calculateSpeed(double impact, double acc, double endurance, double mental) {
    //event condition has impact on athlete performance
    return 0.12 * (acc * 50 + endurance * 30 + mental * 20 - impact * 10) / 100;
}

double Athlete::calculateStrength(double impact, double weight, double endurance, double mental) {
    //event condition has impact on athlete performance
    return 3.14 * (weight * 40 + endurance * 30 + mental * 20 - impact * 10) / 100;
}


void Athlete::calculateSpeedAndStrength(Event event) {
    double impactOnFieldAttribute = 0;
    double impactOnTrackAttribute = 0;
    if (event.getEventType() == FIELD) {
        impactOnFieldAttribute += event.getImpact();
    } else {
        impactOnTrackAttribute += event.getImpact();
    }
    //average speed is calculated based on accelaration and endurance and mental health
    avrSpeed = calculateSpeed(impactOnTrackAttribute, accelaration, endurance, mental);

    //avg strength is calculated based on weight and endurance and mental health
    avrStrength = calculateStrength(impactOnFieldAttribute, weight, endurance, mental);
}


const std::string &Athlete::getName() const {
    return name;
}

void Athlete::setName(const std::string &name) {
    Athlete::name = name;
}

Gender Athlete::getGender() const {
    return gender;
}

void Athlete::setGender(Gender gender) {
    Athlete::gender = gender;
}

double Athlete::getMental() const {
    return mental;
}

void Athlete::setMental(double mental) {
    Athlete::mental = mental;
}

double Athlete::getEndurance() const {
    return endurance;
}

void Athlete::setEndurance(double endurance) {
    Athlete::endurance = endurance;
}

double Athlete::getWeight() const {
    return weight;
}

void Athlete::setWeight(double weight) {
    Athlete::weight = weight;
}

double Athlete::getAccelaration() const {
    return accelaration;
}

void Athlete::setAccelaration(double accelaration) {
    Athlete::accelaration = accelaration;
}

double Athlete::getAvrSpeed() const {
    return avrSpeed;
}

void Athlete::setAvrSpeed(double avrSpeed) {
    Athlete::avrSpeed = avrSpeed;
}

double Athlete::getAvrStrength() const {
    return avrStrength;
}

void Athlete::setAvrStrength(double avrStrength) {
    Athlete::avrStrength = avrStrength;
}

double Athlete::getMeetPoint() const {
    return meetPoint;
}

void Athlete::setMeetPoint(double meetPoint) {
    Athlete::meetPoint = meetPoint;
}

double Athlete::getTotalPoints() const {
    return totalPoints;
}

void Athlete::setTotalPoints(double totalPoints) {
    Athlete::totalPoints = totalPoints;
}

void Athlete::setInjury(Injury *injury) {
    if (injury) {
        std::cout << name << "has suffered from " << injury->getName() << " which has severity rate of " << injury->getSeverity() << std::endl;
        mental -= injury->getSeverity();
        endurance -= injury->getSeverity();
        weight -= injury->getSeverity();
        accelaration -= injury->getSeverity();
        if(mental < 50){
            mental = 50;
        }
        if(endurance < 50){
            endurance = 50;
        }
        if(weight < 50){
            weight = 50;
        }
        if(accelaration < 50){
            accelaration = 50;
        }

    }
}

void Athlete::reportInfoAthelete()  {
    std::cout << "*Athlete information:*" << std::endl
       << "-Name: " << name << std::endl
       << "-Gender: " << (gender==0 ? "Male" : "Female") << std::endl
       << "-Mental Health: " << mental << std::endl
       << "-Endurance: " << endurance << std::endl
       << "-Weight: " << weight << std::endl
       << "-Accelaration: " << accelaration << std::endl;
}
