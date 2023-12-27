#pragma once
#include "Event.h"
#include "Passengers.h"
#include<iostream>
using namespace std;

class ArrivalEvent : public Event
{
protected:
	int A; //denoted an arrival event
	int TYP; //is the passenger type(SP / WP / NP) For SP, an extra word is added at the end of the line to show if the passenger is aged, POD, Pregnant
	int END; // start station

public:
	 ArrivalEvent(Time time, string SPTyp, string Typ, int SStation, int EStation, int ET, int ID_pass)
	{
		specialP = SPTyp;
		Type = Typ;
		STRTStation = SStation;
		ENDstation = EStation;
		TimeStamp = ET;
		ID = ID_pass;
	}
	ArrivalEvent(string Typ, int SStation, int EStation, int ET, int ID_pass)
	{
		Type = Typ;
		STRTStation = SStation;
		ENDstation = EStation;
		TimeStamp = ET;
		ID = ID_pass;
	}

	bool isSPEmpty()
	{
		return specialP.empty();
	}

	void excute(Company* C)
	{
		if (isSPEmpty())
		{
			Passengers* P = new Passengers(Type, STRTStation, ENDstation, TimeStamp, ID);
			C->addPassenger(P);
		}
		/*else
		{
			Passengers* P = new Passengers(time , specialP, Type, STRTStation, ENDstation, TimeStamp, ID);
			C->addPassenger(P);
		}*/
	}
}; 