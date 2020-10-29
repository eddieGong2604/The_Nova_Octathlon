//
// Created by tienl on 24/10/2020.
//

#include <algorithm>
#include "Meet.h"
#include "Performance.h"

Meet::Meet(const int &day, Location *location, WeatherSys *weatherSys, const std::vector<Event *> day1Events,
           const std::vector<Event *> day2Events, std::vector<Team *> &teams, InjurySys *injurySys) : day(day),
                                                                                                      location(
                                                                                                              location),
                                                                                                      weatherSys(
                                                                                                              weatherSys),
                                                                                                      day1Events(
                                                                                                              day1Events),
                                                                                                      day2Events(
                                                                                                              day2Events),
                                                                                                      teams(teams),
                                                                                                      injurySys(
                                                                                                              injurySys) {
}

Meet::~Meet() {
	for(auto a : performances){
		delete a;
	}
	performances.clear();
}

void Meet::competitionDay(std::vector<Event *> dayEvents, int day) {
    std::cout << "Day " << day << std::endl;
    Weather weatherToday = *weatherSys->getWeather();
    std::cout << "The weather today is " << weatherToday.getName() << " with impact value of "
              << weatherToday.getImpact() << std::endl;

    for (int i = 0; i < dayEvents.size(); i++) {
        std::cout << std::endl;

        std::cout << "***" << dayEvents[i]->getName() << "***" << std::endl;

        dayEvents[i]->setImpact(*location, weatherToday);

        std::cout << "Location and Weather impact rate: " << dayEvents[i]->getImpact() << std::endl;

        //check if impact from location and weather make event be cancelled or not
        if (dayEvents[i]->isEventAbleToHappen()) {
            //if able to happen
            for (int j = 0; j < teams.size(); j++) {
                Performance *performanceMale = new Performance(*teams[j]->getMaleAthlete(), dayEvents[i], injurySys);

                Performance *performanceFemale = new Performance(*teams[j]->getFemaleAthlete(), dayEvents[i],
                                                                 injurySys);
                std::cout << std::endl;
                if (dayEvents[i]->getEventType() == TRACK) {
                    std::cout << performanceMale->getAthlete()->getName() << " finished the race in: "
                              << performanceMale->getResult() << " seconds." << std::endl;
                } else {
                    std::cout << performanceMale->getAthlete()->getName() << " finished the event with : ";
                    if (dayEvents[i]->getName() == "High jump") {
                        std::cout << performanceMale->getResult() * 100 << " centimeters." << std::endl;
                    } else {
                        std::cout << performanceMale->getResult() << " meters." << std::endl;
                    }
                }
                //award points to athlete
                performanceMale->awardPointsToAthlete();

                std::cout << std::endl;
                if (dayEvents[i]->getEventType() == TRACK) {
                    std::cout << performanceFemale->getAthlete()->getName() << " finished the race in: "
                              << performanceFemale->getResult() << " seconds." << std::endl;
                } else {
                    std::cout << performanceFemale->getAthlete()->getName() << " finished the event with : ";
                    if (dayEvents[i]->getName() == "High jump") {
                    	//convert to centimeters for high jump
                        std::cout << performanceFemale->getResult() * 100 << " centimeters" << std::endl;
                    } else {
                        std::cout << performanceFemale->getResult() << " meters" << std::endl;
                    }
                }
                //award points to athlete
                performanceFemale->awardPointsToAthlete();

                performances.push_back(performanceMale);
                performances.push_back(performanceFemale);
            }
        } else {
            //if called off
            std::cout << dayEvents[i]->getName()
                      << " can not happen today due to extreme condition posed by current location and weather"
                      << std::endl;
        }
    }

}


void Meet::meet() {
    std::cout << std::endl;
    std::cout << "Before-meet attributes" << std::endl;
    reportInfo();
    competitionDay(day1Events, day);
    std::cout << std::endl;
    std::cout << std::endl;
    competitionDay(day2Events, day + 1);
    std::cout << std::endl;
    displayRanking();
    std::cout << "Meet-end attributes" << std::endl;
    std::cout << "The athletes has tried their best. Now their attributes is decreased due to tiredness" << std::endl;

    reportInfo();

}

void Meet::displayRanking() {
    for (int i = 0; i < teams.size(); i++) {
        maleAthRank.push_back(teams[i]->getMaleAthlete());
        femaleAthRank.push_back(teams[i]->getFemaleAthlete());
    }
    //sort rank
    sortRank(maleAthRank);
    sortRank(femaleAthRank);
    std::cout << "***********Meet End Summary***********" << std::endl;
    std::cout << "Male Ranking: " << std::endl;
    displayRankingAthlete(maleAthRank);
    std::cout << std::endl;

    std::cout << "Female Ranking: " << std::endl;
    displayRankingAthlete(femaleAthRank);
    std::cout << std::endl;

};

void Meet::reportInfo() {
    for (int i = 0; i < teams.size(); i++) {
        teams[i]->reportAtheleInfoOnly();
    }
}

void Meet::sortRank(std::vector<Athlete *> &athRanks) {
    std::sort(athRanks.begin(), athRanks.end(), compareAthlete);
}

bool Meet::compareAthlete(Athlete *a1, Athlete *a2) {
    return (a1->getMeetPoint() > a2->getMeetPoint());
}

void Meet::displayRankingAthlete(std::vector<Athlete *> athleteRank) {
    std::string highestMedal[] = {"GOLD", "SILVER", "BRONZE"};
    int currentMedalPointer = 0;
    int nextMedalPointer = 0;
    for (int i = 0; i < athleteRank.size(); i++) {
        if (i >= 1) {
            nextMedalPointer++;
            //if the next athlete has different point, highest medal be reduced
            if (athleteRank[i]->getMeetPoint() != athleteRank[i - 1]->getMeetPoint()) {
                currentMedalPointer = nextMedalPointer;
                //has medal, athlete mental health will not be impacted
                if (currentMedalPointer <= 2) {
                    std::cout << currentMedalPointer + 1 << ". " << athleteRank[i]->getName() << " "
                              << athleteRank[i]->getMeetPoint() << " points " << highestMedal[currentMedalPointer]
                              << std::endl;
                }
                    //no medal, athlete mental health will be impacted based on the ranking
                    //the lower, the worse
                else {
                    athleteRank[i]->setMental(athleteRank[i]->getMental() - i / 10);
                    std::cout << i + 1 << ". " << athleteRank[i]->getName() << " " << athleteRank[i]->getMeetPoint()
                              << " points " << std::endl;
                }
            }
                //next athlete has same points
            else {
                //has medal
                if (currentMedalPointer <= 2) {
                    std::cout << currentMedalPointer + 1 << ". " << athleteRank[i]->getName() << " "
                              << athleteRank[i]->getMeetPoint() << " points " << highestMedal[currentMedalPointer]
                              << std::endl;
                }
                    //no medal, mental health impacted
                else {
                    athleteRank[i]->setMental(athleteRank[i]->getMental() - i / 10);
                    std::cout << i + 1 << ". " << athleteRank[i]->getName() << " " << athleteRank[i]->getMeetPoint()
                              << " points " << std::endl;
                }
            }
        }
            //output the leader board
        else {
            std::cout << currentMedalPointer + 1 << ". " << athleteRank[i]->getName() << " "
                      << athleteRank[i]->getMeetPoint() << " points " << highestMedal[currentMedalPointer] << std::endl;
        }
    }
}