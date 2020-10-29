//
// Created by tienl on 23/10/2020.
//

#include "FieldEvent.h"

FieldEvent::FieldEvent(const std::string &name, EventType eventType, double impactResistancy, double weightOfObject)
        : Event(name, eventType, impactResistancy), weightOfObject(weightOfObject) {}

double FieldEvent::getDifficulty() {
    return weightOfObject;
}

void FieldEvent::setWeightOfObject(double weightOfObject) {
    FieldEvent::weightOfObject = weightOfObject;
}
