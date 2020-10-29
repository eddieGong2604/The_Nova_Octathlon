//
// Created by tienl on 23/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_WEATHERSYS_H
#define ASSIGNMENT2CSCI251_WEATHERSYS_H
#include <iostream>
#include <vector>
#include "Weather.h"

class WeatherSys {
private:
    std::vector<Weather*> possibleWeathers;
public:
    WeatherSys(std::vector<Weather*>);
    ~WeatherSys();
    Weather* getWeather();
};


#endif //ASSIGNMENT2CSCI251_WEATHERSYS_H
