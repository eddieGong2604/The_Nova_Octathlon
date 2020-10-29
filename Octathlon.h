//
// Created by tienl on 23/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_OCTATHLON_H
#define ASSIGNMENT2CSCI251_OCTATHLON_H


#include <random>
#include <vector>
#include "WeatherSys.h"
#include "Location.h"
#include "Event.h"
#include "Team.h"
#include "InjurySys.h"
#include "Meet.h"

class Octathlon {
private:
    WeatherSys* weatherSys;
    InjurySys* injurySys;
    int teamQuantity;
    int meetQuantity;

    //fixed locations with fixed feature
    std::vector<Location*> allLocations;
    std::vector<Event*> firstDayEvents;
    std::vector<Event*> secondDayEvents;
    std::vector<Team*> teams;

    std::vector<Athlete> maleRnk;
    std::vector<Athlete> femaleRnk;
    std::vector<Meet*> meets;
public:
    Octathlon(int, int);
    ~Octathlon();
    void initInjurySys();
    void initWeatherSystem();
    void initLocation();
    void initEvent();
    void initTeam();
    void startTheNovaOcthalon();

    void recoverAndTrainOct(int);

    void currentSeasonSummary();
    void finalSeasonSummary();
    static bool compareTwoAthleteOnAccumulatedPoints(Athlete, Athlete);
};


#endif //ASSIGNMENT2CSCI251_OCTATHLON_H
