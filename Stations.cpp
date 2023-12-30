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
Stations::Stations(int Stationsnum)
{
	numofstations = Stationsnum;
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


Queue<Buses*> Stations::getFWBusList()
{
	return FWBusList;
}

Queue<Buses*> Stations::getBWBusList()
{
	return BWBusList;
}

Queue<Passengers*>& Stations::getNormalPF()
{
	return WNPFW;
}

Queue<Passengers*>& Stations::getNormalPB()
{
	return WNPBW;
}
Queue<Passengers*>& Stations::getWheelPF()
{
	return WWPFW;
}
Queue<Passengers*>& Stations::getWheelPB()
{
	return WWPBW;
}
PriorityQueue<Passengers*>& Stations::getSpecialPF()
{
	return WSPFW;
}
PriorityQueue<Passengers*>& Stations::getSpecialPB()
{
	return WSPBW;
}


bool Stations::RemovePassenger(Queue<Passengers*>& p, int id)
{
	bool x = false;
	Queue<Passengers*> Temp;
	Passengers* PA = nullptr;
	while (!p.IsEmpty())
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
	while (!Temp.IsEmpty())
	{
		Temp.Dequeue(PA);
		p.Enqueue(PA);
	}
	return x;
}


void Stations::changeBusStatus(int busId, Queue<Buses*> &FWBusList, Queue<Buses*> &BWBusList)
{
	// Use Queue for both forward and backward bus lists
	Queue<Buses*> tempFWBusList;
	Queue<Buses*> tempBWBusList;

	Buses* currentBus = nullptr;

	// Search in the forward bus list
	while (!FWBusList.IsEmpty())
	{
		Buses* tempBus = nullptr;
		FWBusList.Dequeue(tempBus);

		if (tempBus->GetID() == busId)
		{
			currentBus = tempBus;
			tempFWBusList.Enqueue(tempBus);
			break;
		}

		tempFWBusList.Enqueue(tempBus); // Enqueue the bus back to the original list
	}

	// Search in the backward bus list if not found in the forward list
	if (currentBus == nullptr)
	{
		while (!tempBWBusList.IsEmpty())
		{
			Buses* tempBus = nullptr;
			BWBusList.Dequeue(tempBus);

			if (tempBus->GetID() == busId)
			{
				currentBus = tempBus;
				tempBWBusList.Enqueue(tempBus);
				break;
			}

			tempBWBusList.Enqueue(tempBus); // Enqueue the bus back to the original list
		}
	}

	if (currentBus != nullptr)
	{
		cout << "Changing status of Bus " << busId << " from moving to waiting." << endl;

		// Assuming 0 represents moving and 1 represents waiting
		currentBus->SetStatus(1); // Set status to waiting
	}
	else
	{
		cout << "Bus " << busId << " not found at the station." << endl;
	}
	
	while (!tempBWBusList.IsEmpty()) {
		Buses* tempBus = nullptr;
		tempBWBusList.Dequeue(tempBus);
		BWBusList.Enqueue(tempBus);
	}

	while (!tempFWBusList.IsEmpty()) {
		Buses* tempBus = nullptr;
		tempFWBusList.Dequeue(tempBus);
		FWBusList.Enqueue(tempBus);
	}


}


void Stations::MoveBusFromWaitingToMoving(int busId, Queue<Buses*> FWBusList, Queue<Buses*> BWBusList)
{
	// Use Queue for both forward and backward bus lists
	Queue<Buses*> tempFWBusList;
	Queue<Buses*> tempBWBusList;

	Buses* currentBus = nullptr;

	// Search in the forward bus list
	while (!FWBusList.IsEmpty())
	{
		Buses* tempBus = nullptr;
		FWBusList.Dequeue(tempBus);

		if (tempBus->GetID() == busId)
		{
			currentBus = tempBus;
			tempFWBusList.Enqueue(tempBus);
			break;
		}

		tempFWBusList.Enqueue(tempBus); // Enqueue the bus back to the original list
	}

	// Search in the backward bus list if not found in the forward list
	if (currentBus == nullptr)
	{
		while (!tempBWBusList.IsEmpty())
		{
			Buses* tempBus = nullptr;
			BWBusList.Dequeue(tempBus);

			if (tempBus->GetID() == busId)
			{
				currentBus = tempBus;
				tempBWBusList.Enqueue(tempBus);
				break;
			}

			tempBWBusList.Enqueue(tempBus); // Enqueue the bus back to the original list
		}
	}

	if (currentBus != nullptr)
	{
		currentBus->MoveFromWaitingToMoving();
	}
	else
	{
		cout << "Bus " << busId << " not found at the station." << endl;
	}

	while (!tempBWBusList.IsEmpty()) {
		Buses* tempBus = nullptr;
		tempBWBusList.Dequeue(tempBus);
		BWBusList.Enqueue(tempBus);
	}

	while (!tempFWBusList.IsEmpty()) {
		Buses* tempBus = nullptr;
		tempFWBusList.Dequeue(tempBus);
		FWBusList.Enqueue(tempBus);
	}
}

void Stations::releaseBusFromStationZero(Queue<int>& stationZero, List<int>& buses)
{
}

void Stations::BoardingWP(Queue<Passengers*> WWPFW, Queue<Passengers*> WWPBW, Queue<Buses*> FWBusList, Queue<Buses*> BWBusList)
{	
	// keda hydno 3ala awl wa7d fe el list wala ana bythy2ly
	Passengers* TempPFW;
	Passengers* TempPBW;
	Buses* TempFWBus;
	Buses* TempBWBus;
	Queue<Passengers*> Lltfry8FW;
	Passengers* PFW;
	Queue<Passengers*> Lltfry8BW;
	Passengers* PBW;
	while (!WWPFW.IsEmpty() && !WWPBW.IsEmpty())
	{
		if (WWPFW.peek(TempPFW))
		{
			FWBusList.peek(TempFWBus);
			if (TempPFW->getSStaion() == TempFWBus->GetCurrBusStation()) 
			{
				WWPFW.Dequeue(TempPFW);
				TempFWBus->addPassenger(TempPFW);
			}
			else
			{
				WWPFW.Dequeue(TempPFW);
				Lltfry8FW.Enqueue(TempPFW);
			}
		}
		else if (WWPBW.peek(TempPBW))
		{
			BWBusList.peek(TempBWBus);
			if (TempPBW->getSStaion() == TempBWBus->GetCurrBusStation())
			{
				TempBWBus->addPassenger(TempPBW);
			}
			else
			{
				WWPBW.Dequeue(TempPBW);
				Lltfry8BW.Enqueue(TempPBW);
			}
		}
	}
	while (!Lltfry8FW.IsEmpty() || !Lltfry8BW.IsEmpty())
	{
		Lltfry8FW.Dequeue(PFW);
		WWPFW.Enqueue(PFW);
		Lltfry8BW.Dequeue(PBW);
		WWPBW.Enqueue(PFW);
	}
}




