//
// Created by tienl on 24/10/2020.
//

#include "Injury.h"

Injury::Injury(const std::string &name, double severity) : name(name), severity(severity) {}

const std::string &Injury::getName() const {
    return name;
}

void Injury::setName(const std::string &name) {
    Injury::name = name;
}

double Injury::getSeverity() const {
    return severity;
}

void Injury::setSeverity(double severity) {
    Injury::severity = severity;
}
