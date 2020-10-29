//
// Created by tienl on 23/10/2020.
//

#include "Weather.h"
#include <random>

Weather::Weather(std::string aname, double aimpact, EventType aaffectEvent) {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_real_distribution<double> randURD(aimpact-1, aimpact);
    double aIm = randURD(randEng);
    name = aname;
    impact = aIm > 0 ? aIm : 0;
    affectEvent = aaffectEvent;
}

const std::string &Weather::getName() const {
    return name;
}

void Weather::setName(const std::string &name) {
    Weather::name = name;
}

double Weather::getImpact() const {
    return impact;
}

void Weather::setImpact(double impact) {
    Weather::impact = impact;
}

EventType Weather::getAffectEvent() const {
    return affectEvent;
}

void Weather::setAffectEvent(EventType affectEvent) {
    Weather::affectEvent = affectEvent;
}

std::ostream &operator<<(std::ostream &os, const Weather &weather) {
    os << "name: " << weather.name << " affectEvent: " << weather.affectEvent;
    return os;
}
