//
// Created by tienl on 23/10/2020.
//

#include "WeatherSys.h"
#include <random>

WeatherSys::WeatherSys(std::vector<Weather *> apossibleWeathers) {
    possibleWeathers = apossibleWeathers;
}

Weather *WeatherSys::getWeather() {
    std::random_device randomDevice;
    std::default_random_engine randEng(randomDevice());
    std::uniform_int_distribution<int> randURD(0, possibleWeathers.size() - 1);
    return possibleWeathers[randURD(randEng)];
}

WeatherSys::~WeatherSys() {
    for (auto a : possibleWeathers) {
        delete a;
    }
    possibleWeathers.clear();
}