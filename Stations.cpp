#include "Stations.h"

Stations::Stations()
{
	numofstations = 0;
	StationZero = 0;
	MaxStationCapacity = 0;
	StationLocation = "";
	StationEnd = 0;
	StationId = 0;
	BusId = 0;
}

Stations::Stations(string loc, int Stid, int Stationsnum, int TS)
{
	numofstations = 0;
	StationZero = 0;
	MaxStationCapacity = 0;
	StationLocation = "";
	StationEnd = 0;
	StationId = 0;
	BusId = 0;
	/*setStationid(Stid);
	setLocation(loc);
	setStationsnumber(Stationsnum);*/
}
void Stations::AddPassengers(Passengers* P)
{
	if (P->getTyp() == "SP")
	{
		if (P->getEStaion() > P->getSStaion())
			WSPFW.Enqueue(P, P->getPrio());
		else
			WSPBW.Enqueue(P, P->getPrio());
	}
	else if (P->getTyp() == "NP")
	{
		if (P->getEStaion() > P->getSStaion())
			WNPFW.Enqueue(P);
		else
			WNPBW.Enqueue(P);
	}
	else if (P->getTyp() == "WP")
	{
		if (P->getEStaion() > P->getSStaion())
			WWPFW.Enqueue(P);
		else
			WWPBW.Enqueue(P);
	}
}
void Stations::setLocation(string loc)
{
	StationLocation = loc;

}
void Stations::setStationid(int Stid)
{
	StationId = Stid;

}
void Stations::setStationsnumber(int Stationsnum) {

	numofstations = Stationsnum;
}
void Stations::SetTimeBetweenSta(int time)
{
	TBS = time;
}

int Stations::getStationID()
{
	return StationId;
}
int Stations::getStationsnumber()
{
	return numofstations;
}

int Stations::getTimeBetweenSta()
{
	return TBS;
}



