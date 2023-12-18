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
//void Stations::AddPassengers(Passengers* P)
//{
//	if (getSStaion() < getEStaion())
//	{
//		for (int i = 2; i < 5; i++)
//		{
//			if (CalcPrio() == i)
//			{
//				StpassengersFW.Enqueue(P, i);
//			}
//		}
//		if (CalcPrio() == 1)
//		{
//			NtpassengersFW.Enqueue(P, 1);
//		}
//		if (getTyp == WP)
//		{
//			NtpassengersFW.Enqueue(P, 1);
//		}
//	}
//	if (getSStaion() > getEStaion())
//	{
//		for (int i = 2; i < 5; i++)
//		{
//			if (CalcPrio() == i)
//			{
//				StpassengersBW.Enqueue(P, i);
//			}
//		}
//		if (CalcPrio() == 1)
//		{
//			NtpassengersBW.Enqueue(P, 1);
//		}
//		if (getTyp() == WP)
//		{
//			NtpassengersBW.Enqueue(P, 1);
//		}
//	}
//}
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



