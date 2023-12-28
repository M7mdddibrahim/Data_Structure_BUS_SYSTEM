#pragma once
#include "Event.h"

class LeaveEvent : public Event
{

public:
	LeaveEvent(Time t, int id, int starts)
	{
		time.SetHours(t.getHours());
		time.SetMin(t.getMin());
		ID = id;
		STARTS = starts;
	}
	virtual void execute(Company* C)
	{
		C->Leave_Passenger(STARTS, ID);
	}

	//void setNPassengerData(string Typ, int SStation, int ET, int ID)
	//{
	//	/*Type = Typ;
	//	STRTStation = SStation;
	//	TimeStamp = ET;
	//	Id = ID;*/
	//}
	/*Passengers* excute1()
	{
		Passengers* Npassenger = new Passengers(Type, STRTStation, TimeStamp, Id);
		return Npassenger;
	}*/
};