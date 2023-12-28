#pragma once
#include "Event.h"
#include "Passengers.h"
#include<iostream>
using namespace std;

class ArrivalEvent : public Event
{
protected:
/*	int A;*/ //denoted an arrival event
	string TYP; //is the passenger type(SP / WP / NP) For SP, an extra word is added at the end of the line to show if the passenger is aged, POD, Pregnant
	int ENDS; // END station
	string SPTYP;
	int ON_OFFT;

public:
	 ArrivalEvent(Time time, string SPTyp, string Typ, int SStation, int EStation, Time ET, int ID_pass)
	{
		SPTYP = SPTyp;
		TYP = Typ;
		STARTS = SStation;
		ENDS = EStation;
		time.SetHours(ET.getHours());
		time.SetMin(ET.getMin());
		ID = ID_pass;
	}
	ArrivalEvent(string Typ, int SStation, int EStation, Time ET, int ID_pass)
	{
		TYP = Typ;
		STARTS = SStation;
		ENDS = EStation;
		time.SetHours(ET.getHours());
		time.SetMin(ET.getMin());
		ID = ID_pass;
	}

	bool isSPEmpty()
	{
		return SPTYP.empty();
	}

	void excute(Company* C)
	{
		if (isSPEmpty())
		{
			Passengers* P = new Passengers(TYP, STARTS, ENDS, time, ID);
			C->addPassenger(P);
		}
		/*else
		{
			Passengers* P = new Passengers(time , specialP, Type, STRTStation, ENDstation, TimeStamp, ID);
			C->addPassenger(P);
		}*/
	}
}; 