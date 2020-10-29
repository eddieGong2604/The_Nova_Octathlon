//
// Created by tienl on 23/10/2020.
//

#include "Location.h"

Location::Location(const std::string &name, SFeature &sFeature) : name(name), sFeature(&sFeature) {

}
Location::~Location() {
    delete sFeature;
}
const std::string &Location::getName() const {
    return name;
}

void Location::setName(const std::string &name) {
    Location::name = name;
}

const SFeature *Location::getSFeature() const {
    return sFeature;
}

