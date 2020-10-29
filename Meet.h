//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_MEET_H
#define ASSIGNMENT2CSCI251_MEET_H

#include <iostream>
#include <random>
#include <vector>
#include "Team.h"
#include "InjurySys.h"
#include "WeatherSys.h"
#include "Performance.h"

class Meet {
private:
    int day;
    InjurySys *injurySys;
    Location *location;
    WeatherSys *weatherSys;
    std::vector<Event *> day1Events;
    std::vector<Event *> day2Events;
    std::vector<Team *> teams;
    std::vector<Athlete *> maleAthRank;
    std::vector<Athlete *> femaleAthRank;
    std::vector<Performance *> performances;
public:
    Meet(const int &day, Location *location, WeatherSys *weatherSys, const std::vector<Event *> day1Events,
         const std::vector<Event *> day2Events, std::vector<Team *> &teams, InjurySys *injurySys);

    ~Meet();

    void meet();

    void competitionDay(std::vector<Event *>, int);

    void reportInfo();

    static void sortRank(std::vector<Athlete *> &);

    static bool compareAthlete(Athlete *a1, Athlete *a2);

    void displayRanking();

    void displayRankingAthlete(std::vector<Athlete *>);
};


#endif //ASSIGNMENT2CSCI251_MEET_H
