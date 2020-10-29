//
// Created by tienl on 23/10/2020.
//

#include "SFeature.h"
#include "Octathlon.h"
#include <random>
SFeature::SFeature(std::string aname, EventType aeventType, double aimpactRange) {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_real_distribution<double> imRand(aimpactRange-1, aimpactRange);
    name = aname;
    affectEventType = aeventType;

    double addedIm = imRand(randEng);
    impact = addedIm > 0 ? addedIm : 0;
}

const std::string &SFeature::getName() const {
    return name;
}

void SFeature::setName(const std::string &name) {
    SFeature::name = name;
}

double SFeature::getImpact() const {
    return impact;
}

void SFeature::setImpact(double impact) {
    SFeature::impact = impact;
}

EventType SFeature::getAffectEventType() const {
    return affectEventType;
}

void SFeature::setAffectEventType(EventType affectEventType) {
    SFeature::affectEventType = affectEventType;
}

std::ostream &operator<<(std::ostream &os, const SFeature &feature) {
    os << "name: " << feature.name << " affectEventType: " << feature.affectEventType;
    return os;
}
