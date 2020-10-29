//
// Created by tienl on 24/10/2020.
//

#include "Performance.h"
#include <random>

Performance::Performance(Athlete &athlete, Event *event, InjurySys *injurySys) {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_real_distribution<double> randURD(0,0.2);
    athlete.setInjury(injurySys->getInjury());

    athlete.calculateSpeedAndStrength(*event);

    if (event->getEventType() == TRACK) {
        TrackEvent * trackEvent = dynamic_cast<TrackEvent *>(event);
        result = calPerformance(trackEvent->getDifficulty(), athlete.getAvrSpeed());
        //get tired, acc decrease a bit
        athlete.setAccelaration(athlete.getAccelaration() - randURD(randEng));

    } else {
        //get tired, weight decrease a bit
        athlete.setWeight(athlete.getWeight() - randURD(randEng));
        result = calPerformance(athlete.getAvrStrength(), dynamic_cast<FieldEvent *>(event)->getDifficulty());
    }
    //athlete get tired, endurance decrease a bit
    athlete.setEndurance(athlete.getEndurance() - randURD(randEng));

    this->athlete = &athlete;
    this->event = event;

}

void Performance::awardPointsToAthlete() {
    double point = 0;
    if (event->getEventType() == TRACK) {
        if (event->getB() - result <= 0) {
            std::cout << "No points awarded to " << athlete->getName() << std::endl;
            athlete->setMeetPoint(athlete->getMeetPoint() + 0);
        } else {
            point = event->getA() * pow(event->getB() - result, event->getC());
            std::cout << point << " points awarded to " << athlete->getName() << std::endl;
        }
    } else {
        if (event->getName() == "High jump") {
            //convert from metre to cm
            result *= 100;
        }
        if (result - event->getB() <= 0) {
            std::cout << "No points awarded to " << athlete->getName() << std::endl;
            athlete->setMeetPoint(athlete->getMeetPoint() + 0);
        } else {
            point = event->getA() * pow(result - event->getB(), event->getC());
            std::cout << point << " points awarded to " << athlete->getName() << std::endl;
        }
    }
    athlete->setMeetPoint(athlete->getMeetPoint() + point);
    athlete->setTotalPoints(athlete->getTotalPoints() + point);

}

Athlete *Performance::getAthlete() const {
    return athlete;
}

void Performance::setAthlete(Athlete *athlete) {
    Performance::athlete = athlete;
}

Event *Performance::getEvent() const {
    return event;
}

void Performance::setEvent(Event *event) {
    Performance::event = event;
}

double Performance::calPerformance(double a, double b) {

    return a / b;
}

double Performance::getResult() const {
    return result > 0 ? result : 0;
}

Performance::~Performance() {
}