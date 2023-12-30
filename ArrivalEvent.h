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
	int Priority;

public:
	 ArrivalEvent(string SPTyp, string Typ, int SStation, int EStation, Time ET, int ID_pass )
	{
		SPTYP = SPTyp;
		TYP = Typ;
		STARTS = SStation;
		ENDS = EStation;
		time.SetHours(ET.getHours());
		time.SetMin(ET.getMin());
		ID = ID_pass;
		//Priority = prio;
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

	void excute(Company* C)
	{
		if (TYP == "WP" || TYP == "NP")
		{
			Passengers* P = new Passengers(TYP, STARTS, ENDS, time, ID);
			C->addPassenger(P);
		}
		else if (TYP == "SP")
		{
			Passengers* P = new Passengers(SPTYP, TYP,time, STARTS, ENDS, ID);
			C->addPassenger(P);
		}
	}
}; 