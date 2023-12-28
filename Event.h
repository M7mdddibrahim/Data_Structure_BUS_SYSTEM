#pragma once
#include<iostream>
#include"Company.h"
#include <string>
using namespace std;

class Event
{
protected:
    Time time;
    int ID;
    int STARTS;


    //int ID;
    //int STRT;
    //int timeStep; // ET
    //char event_type;
    //List<Passengers*> Arr;
    //List<Passengers*> leave;
    //string specialP;
    //string Type;
    //int STRTStation;
    //int ENDstation;
    //int TimeStamp ;

public:
    Event();
<<<<<<< Updated upstream
    void  set_Event_type(char e);
    char get_EventType();
    virtual void excute(Company* C) = 0;
    int convertToTimeStep(int hours, int minutes);
=======
    virtual void excute(Company* C) = 0;
    /*int convertToTimeStep(int hours, int minutes);
>>>>>>> Stashed changes
    int main();
    void  set_Event_type(char e);
    char get_EventType();*/

};
