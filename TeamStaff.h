//
// Created by tienl on 24/10/2020.
//

#ifndef ASSIGNMENT2CSCI251_TEAMSTAFF_H
#define ASSIGNMENT2CSCI251_TEAMSTAFF_H

#include <iostream>
class TeamStaff {
protected:
    std::string name;
    double impact;
public:
    TeamStaff(std::string name);
    virtual ~TeamStaff(){

    };
    std::string getName() const;

    void setName(std::string name);

    double getImpact() const;

    void setImpact(double impact);

    virtual void reportTeamStaffInfo(){
        return;
    };
};


#endif //ASSIGNMENT2CSCI251_TEAMSTAFF_H
