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
<<<<<<< Updated upstream
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
=======
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

Stations::Stations(int Stationum)
{
	numofstations = Stationum;
>>>>>>> Stashed changes
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

bool Stations::RemovePassenger(Queue<Passengers*> p, int id)
{
	bool x = false;
	Queue<Passengers*> Temp;
	Passengers* PA = nullptr;
	while (!(p.IsEmpty()))
	{
		p.Dequeue(PA);
		if (PA->getID() == id)
		{
			x = PA->getID() == id;
		}
		else
		{
			Temp.Enqueue(PA);
		}
	}
	while (!(Temp.IsEmpty()))
	{
		Temp.Dequeue(PA);
		p.Enqueue(PA);
	}
	return x;
}


Queue<Passengers*> Stations::getNormalPF()
{
	return WNPFW;
}

Queue<Passengers*> Stations::getNormalPB()
{
	return WNPBW;
}
Queue<Passengers*> Stations::getWheelPF()
{
	return WWPFW;
}
Queue<Passengers*> Stations::getWheelPB()
{
	return WWPBW;
}
PriorityQueue<Passengers*> Stations::getSpecialPF()
{
	return WSPFW;
}
PriorityQueue<Passengers*> Stations::getSpecialPB()
{
	return WSPBW;
}


