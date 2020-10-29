//
// Created by tienl on 23/10/2020.
//

#include "Event.h"


Event::Event(const std::string &aname, EventType aeventType, double aimpactResistancy)  {
    name = aname;
    eventType = aeventType;
    impactResistancy = aimpactResistancy;
}

const std::string &Event::getName() const {
    return name;
}

void Event::setName(const std::string &name) {
    Event::name = name;
}

EventType Event::getEventType() const {
    return eventType;
}

void Event::setEventType(EventType eventType) {
    Event::eventType = eventType;
}

double Event::getImpactResistancy() const {
    return impactResistancy;
}

void Event::setImpactResistancy(double impactResistancy) {
    Event::impactResistancy = impactResistancy;
}

void Event::setImpact(Location &location,Weather &weather){
    double impact = 0;
    //calculate the impact caused by location special feature
    // and weather
    if(location.getSFeature()->getAffectEventType() == eventType){
        impact+=location.getSFeature()->getImpact();
    }
    if(weather.getAffectEvent() == eventType){
        impact+= weather.getImpact();
    }
    this->impact = impact;
}

bool Event::isEventAbleToHappen() {
    //if the event can resist the impact then it can happen
    //else it will be cancelled
    return impactResistancy > impact;
}

void Event::setABC(double aA, double bB, double cC) {
    A = aA;
    B = bB;
    C = cC;
}

double Event::getB() const {
    return B;
}

double Event::getImpact() const {
    return impact;
}

double Event::getA() const {
    return A;
}

double Event::getC() const {
    return C;
}

Event::~Event() {

}

