//
// Created by tienl on 23/10/2020.
//

#include "TrackEvent.h"

TrackEvent::TrackEvent(const std::string &name, EventType eventType, double impactResistancy,
                       double lengthOfTheRace) : Event(name, eventType, impactResistancy),
                                                 lengthOfTheRace(lengthOfTheRace) {


}

double TrackEvent::getDifficulty()  {
    return lengthOfTheRace;
}

void TrackEvent::setLengthOfTheRace(double lengthOfTheRace) {
    TrackEvent::lengthOfTheRace = lengthOfTheRace;
}
