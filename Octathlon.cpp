//
// Created by tienl on 23/10/2020.
//

#include "Octathlon.h"
#include "TrackEvent.h"
#include "FieldEvent.h"
#include <vector>
#include <algorithm>

Octathlon::Octathlon(int numTeam, int numMeet) {
    if (numTeam >= 1 && numTeam <= 8 && numMeet >= 1 && numMeet <= 8) {
        teamQuantity = numTeam;
        meetQuantity = numMeet;
    } else {
        std::cerr << "Number of teams and meets must be in the range [1..8]" << std::endl;
        exit(1);
    }
}

Octathlon::~Octathlon() {
    delete weatherSys;
    delete injurySys;
    for (auto a : meets) {
        delete a;
    }
    meets.clear();
    for (auto a : allLocations) {
        delete a;
    }
    allLocations.clear();
    for (auto a : firstDayEvents) {
        delete a;
    }
    firstDayEvents.clear();

    for (auto a : secondDayEvents) {
        delete a;
    }
    secondDayEvents.clear();

    for (auto a : teams) {
        delete a;
    }
    teams.clear();


}

void Octathlon::initInjurySys() {
    InjurySys *injurySys1 = new InjurySys();
    injurySys = injurySys1;
}

void Octathlon::initWeatherSystem() {
    std::vector<Weather *> weathers;
    Weather *weather = new Weather("Sunny", 0, TRACK);
    weathers.push_back(weather);
    weather = new Weather("Rainy", 5, TRACK);
    weathers.push_back(weather);
    weather = new Weather("Windy", 8, FIELD);
    weathers.push_back(weather);
    WeatherSys *weatherSys1 = new WeatherSys(weathers);
    weatherSys = weatherSys1;
}

void Octathlon::initLocation() {
    std::vector<std::string> locationNames = {
            "Hanoi", "Saigon", "Sydney", "Perth", "Brisbane", "Melbourne", "Wollongong", "Kiama"
    };
    std::vector<std::string> specialFeatureNames = {
            "100m sloped upward", "200m sloped downward", "Normal Field", "Mountain Area",
            "Jungle Area", "Heaps of Sand", "Muddy area", "Unstable road"
    };
    std::vector<double> impact = {
            5, 10, 0, 10, 5, 15, 5, 5
    };

    std::vector<EventType> types = {
            TRACK, TRACK, TRACK, FIELD, FIELD, TRACK, FIELD, TRACK
    };

    for (int i = 0; i < 8; i++) {
        SFeature *sFeature = new SFeature(specialFeatureNames[i], types[i], impact[i]);
        Location *location = new Location(locationNames[i], *sFeature);
        allLocations.push_back(location);
    }
}

void Octathlon::initEvent() {
    std::vector<std::string> day1eventNames = {"100 metre running race", "Discus throw", "Javelin throw",
                                               "400 metre running race"};

    std::vector<std::string> day2eventNames = {"110 metre hurdles", "Shot Put", "High jump", "1500 metre running race"};

    std::vector<double> impactResistDay1 = {8, 7, 6, 5};
    std::vector<double> impactResistDay2 = {8, 7, 6, 5};
    std::vector<double> AsDay1 = {25.4347, 12.91, 10.14, 1.53775};
    std::vector<double> AsDay2 = {5.74352, 51.39, 0.8465, 1.53775};
    std::vector<double> BsDay1 = {18, 4, 7, 82};
    std::vector<double> BsDay2 = {28.5, 1.5, 75, 480};
    std::vector<double> CsDay1 = {1.81, 1.1, 1.08, 1.81};
    std::vector<double> CsDay2 = {1.92, 1.05, 1.42, 1.85};

    std::vector<double> difficultyDay1 = {100, 5, 2, 500};
    std::vector<double> difficultyDay2 = {200, 10, 80, 2000};
    std::vector<EventType> typesDay1 = {TRACK, FIELD, FIELD, TRACK};
    std::vector<EventType> typesDay2 = {TRACK, FIELD, FIELD, TRACK};
    for (int i = 0; i < 4; i++) {
        if (typesDay1[i] == TRACK) {
            TrackEvent *event = new TrackEvent(day1eventNames[i], typesDay1[i], impactResistDay1[i], difficultyDay1[i]);
            event->setABC(AsDay1[i], BsDay1[i], CsDay1[i]);
            firstDayEvents.push_back(event);
        } else {
            FieldEvent *event = new FieldEvent(day1eventNames[i], typesDay1[i], impactResistDay1[i], difficultyDay1[i]);
            event->setABC(AsDay1[i], BsDay1[i], CsDay1[i]);
            firstDayEvents.push_back(event);
        }
    }
    for (int i = 0; i < 4; i++) {
        if (typesDay2[i] == TRACK) {
            TrackEvent *event = new TrackEvent(day2eventNames[i], typesDay2[i], impactResistDay2[i], difficultyDay2[i]);
            event->setABC(AsDay2[i], BsDay2[i], CsDay2[i]);
            secondDayEvents.push_back(event);
        } else {
            FieldEvent *event = new FieldEvent(day2eventNames[i], typesDay2[i], impactResistDay2[i], difficultyDay2[i]);
            event->setABC(AsDay2[i], BsDay2[i], CsDay2[i]);
            secondDayEvents.push_back(event);
        }
    }
}

void Octathlon::initTeam() {

    std::vector<std::string> teamNames = {"Chelsea", "Man Utd", "Man City", "Arsenal", "Liverpool", "Tottenham",
                                          "Aston Villa", "Everton"};
    std::vector<std::string> maleAthleteName = {
            "Drogba M.", "Lampard M.", "Cech M.", "Henry M.", "Kai M.", "Werner M.",
            "Cahill M.", "Cesar M."
    };

    std::vector<std::string> femaleAthletename = {
            "Maria F.", "Sofia F.", "Song F.", "Nikita F.", "Bella F.", "Naomi F.",
            "Paige F.", "Lee F."
    };
    std::vector<std::string> trackTrainerName = {
            "Mourinho TT.", "Nguyen Huu Thang TT.", "Steven Gerrard TT.", "Pep Guardiola TT.", "Ole TT.",
            "Park Hang Seo TT.", "Carlo Acelotti TT.", "McCathy TT."
    };
    std::vector<std::string> fieldTrainerName = {
            "Son Min TF.", "Harry Kane TF.", "Kepa TF.", "Caballero TF.", "De Gea TF.",
            "PickFord TF.", "Scezny TF.", "Manuel TF."
    };

    std::vector<std::string> managerName = {
            "Shane Mg.", "Teddy Mg.", "Loc Mg.", "Mahajanz Mg.", "Jayden Mg.", "Armstrong Mg.",
            "Alan Mg.", "Walker Mg."
    };
    std::vector<std::string> physioName = {
            "Simpson Phy.", "Chanathip Phy.", "Danga Phy.", "Diablo Phy.", "Dibala Phy.", "Jaque Phy.",
            "Marcevski Phy.", "Fatima Phy."
    };

    std::vector<std::string> psyName = {
            "Novak Psy.", "Nadal Psy.", "Federer Psy.", "Ferer Psy.", "David Psy.", "Rafeal Psy.",
            "Roger Psy.", "Djokovic Psy."
    };
    for (int i = 0; i < teamQuantity; i++) {
        Athlete *maleAthlete = new Athlete(maleAthleteName[i], M);
        Athlete *femaleAthlete = new Athlete(femaleAthletename[i], F);
        TrackTrainer trackTrainer  = TrackTrainer(trackTrainerName[i]);
        FieldTrainer fieldTrainer =  FieldTrainer(fieldTrainerName[i]);
        SportPsy sportPsy =  SportPsy(psyName[i]);
        Physio physio =  Physio(physioName[i]);
        Manager manager =  Manager(managerName[i]);
        Team *team = new Team(teamNames[i], manager, *maleAthlete, *femaleAthlete, sportPsy,
                              physio, trackTrainer, fieldTrainer);
        teams.push_back(team);
    }
}

void Octathlon::startTheNovaOcthalon() {
    int currentDate = 1;
    //record dates
    std::vector<int> dates;


    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_int_distribution<int> rand(6, 8);

    //report on teams
    std::cout << "THE NOVA OCTATHLON TEAMS INTRODUCTION" << std::endl;

    for (int i = 0; i < teams.size(); i++) {
        teams[i]->reportAllTeamInfo();
        std::cout << std::endl;
    }
    //report on season ahead
    std::cout << "*****************THE NOVA OCTATHLON SEASON*****************" << std::endl << std::endl << std::endl;

    std::cout << "The nova octathlon meets this season will be happening in these days in these locations: "
              << std::endl;

    for (int i = 0; i < meetQuantity; i++) {
        std::cout << "- Day: " << currentDate << "," << currentDate + 1  << " Location: " << allLocations[i]->getName() << std::endl
                  << "Special Feature: " << allLocations[i]->getSFeature()->getName() << std::endl
                  << "This feature has impact rate of " << allLocations[i]->getSFeature()->getImpact()
                  << " and affects "
                  << (allLocations[i]->getSFeature()->getAffectEventType() == 1 ? "field events" : "track events")
                  << std::endl;

        dates.push_back(currentDate);
        currentDate += rand(randEng);
    }

    for (int i = 0; i < meetQuantity; i++) {
        Meet *meet = new Meet(dates[i], allLocations[i], weatherSys, firstDayEvents, secondDayEvents,
                              teams,
                              injurySys);
        meet->meet();
        meets.push_back(meet);
        currentSeasonSummary();
        if (i != meetQuantity - 1) {
            recoverAndTrainOct(dates[i + 1] - dates[i]);
        }
    }

    finalSeasonSummary();

}

void Octathlon::recoverAndTrainOct(int day) {
    std::cout << std::endl;
    std::cout << "Recover and Train in " << day-1 << " day" << std::endl;
    std::cout << std::endl;
    for(int i = 0 ; i < day-1; i++){
        for (int i = 0; i < teams.size(); i++) {
            teams[i]->recoverAndTrain();
        }   
    }

}

bool Octathlon::compareTwoAthleteOnAccumulatedPoints(Athlete a1, Athlete a2) {
    return a1.getTotalPoints() > a2.getTotalPoints();
}

void Octathlon::currentSeasonSummary() {
    std::cout << "OVERALL TABLE" << std::endl;

    for (int i = 0; i < teams.size(); i++) {
        maleRnk.push_back(*teams[i]->getMaleAthlete());
        femaleRnk.push_back(*teams[i]->getFemaleAthlete());
    }
    std::cout << "Male Athletes and Points (Unranked): " << std::endl;
    for (int i = 0; i < maleRnk.size(); i++) {
        std::cout << i + 1 << ". " << maleRnk[i].getName() << " " << maleRnk[i].getTotalPoints() << " points"
                  << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Female Athletes and Points (Unranked): " << std::endl;
    for (int i = 0; i < femaleRnk.size(); i++) {
        std::cout << i + 1 << ". " << femaleRnk[i].getName() << " " << femaleRnk[i].getTotalPoints() << " points"
                  << std::endl;
    }
    maleRnk.erase(maleRnk.begin(), maleRnk.end());
    femaleRnk.erase(femaleRnk.begin(), femaleRnk.end());
}

void Octathlon::finalSeasonSummary() {
    for (int i = 0; i < teams.size(); i++) {
        maleRnk.push_back(*teams[i]->getMaleAthlete());
        femaleRnk.push_back(*teams[i]->getFemaleAthlete());
    }
    std::sort(maleRnk.begin(), maleRnk.end(), compareTwoAthleteOnAccumulatedPoints);
    std::sort(femaleRnk.begin(), femaleRnk.end(), compareTwoAthleteOnAccumulatedPoints);
    std::cout << std::endl;
    std::cout << "***THE NOVA OCTATHLON HAS COME TO AN END. HERE'S THE FINAL TABLE**" << std::endl;
    std::cout << std::endl;

    std::cout << "Male ranking: " << std::endl;
    for (int i = 0; i < maleRnk.size(); i++) {
        std::cout << i + 1 << ". " << maleRnk[i].getName() << " " << maleRnk[i].getTotalPoints() << " points"
                  << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Female ranking: " << std::endl;
    for (int i = 0; i < femaleRnk.size(); i++) {
        std::cout << i + 1 << ". " << femaleRnk[i].getName() << " " << femaleRnk[i].getTotalPoints() << " points"
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << "MALE TROPHY WINNER ISSSSSSSSSSS: " << maleRnk[0].getName() << std::endl;
    std::cout << "FEMALE TROPHY WINNER ISSSSSSSSSSS: " << femaleRnk[0].getName() << std::endl;

}