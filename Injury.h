//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_INJURY_H
#define ASSIGNMENT2CSCI251_INJURY_H

#include <iostream>
class Injury {
private:
    std::string name;
    double severity;
public:
    Injury(const std::string &name, double severity);
    ~Injury(){

    };
    const std::string &getName() const;

    void setName(const std::string &name);

    double getSeverity() const;

    void setSeverity(double severity);
};


#endif //ASSIGNMENT2CSCI251_INJURY_H
