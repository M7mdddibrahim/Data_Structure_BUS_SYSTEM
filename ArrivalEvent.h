#pragma once
#include "Event.h"
#include "Passengers.h"
//
//class ArrivalEvent : public Event
//{
//protected:
//	int A; //denoted an arrival event
//	int TYP; //is the passenger type(SP / WP / NP) For SP, an extra word is added at the end of the line to show if the passenger is aged, POD, Pregnant
//	int END; // start station
//
//public:
//	/*void setNPassengerData(string SPTyp, string Typ, int SStation, int EStation, int ET, int ID_pass)
//	{
//		specialP = SPTyp;
//		Type = Typ;
//		STRTStation = SStation;
//		ENDstation = EStation;
//		TimeStamp = ET;
//		ID = ID_pass;
//	}*/
//	/*Passengers* excute1()
//	{
//		Passengers* Npassenger = new Passengers(specialP, Type, STRTStation, ENDstation, TimeStamp, ID);
//		return Npassenger;
//	}*/
//};