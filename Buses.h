#pragma once
#include"Passengers.h"
#include"Time.h"
#include"DEFS.h"
#include<iostream>
#include <chrono>
#include <thread>
#include <string>
#include "PriorityQueue.h"
#include "List.h"
using namespace std;


class Buses
{
private:
	BusType BT;             // Type of Bus (Wheel, Mixed)
	int WBCapacity;         // Wheel Bus Capcity
	int MBCapacity;         // Mixed Bus Capacity
	int WCHT;              // Wheel Checkup Time
	int MCHT;              // Mixed Checkup Time
	int J;                // Number of Finished Trips
	int WBC;               // WBus_Count
	int MBC;              // MBus_Count
	int TB;               // Total Number of Buses
	int WSpeed;           // Speed of Wheel Busses
	int MSpeed;     // Speed of Mixed Busses
	int nextBusStation; // bus next station
	int currBusStation; // bus Curren station
	float BusUtil;  // Bus Utilization  
	int ID;
	string Direction;  // Direction of the Bus
	//Time Mt; // Move Time
	int TDC; // Total Passengers Transported by the Bus
	int TBT; // Total Busy Time for this Bus
	//Time TSIM; // Total Simulation Time
	PriorityQueue<Passengers*> MBus;
	PriorityQueue<Passengers*> WBus;
	int status;  // 0 for moving, 1 for waiting

public:
	Buses()
	{
		status = 0;
		WBCapacity = 0;
		MBCapacity = 0;
		WCHT = 0;
		MCHT = 0;
		J = 0;
		MSpeed = 0;
		WSpeed = 0;
		ID = 0;
		MBC = 0;
		WBC = 0;
		TB = 0;
		BusUtil = 0;
	}
	Buses(BusType bustype, int WBusCapacity, int MBusCapacity, int WCheckupTime, int MCheckupTime, int j, int MS, int WS, int WBcount, int MBcount, int id)
	{
		BT = bustype;
		WBCapacity = WBusCapacity;
		MBCapacity = MBusCapacity;
		WCHT = WCheckupTime;
		MCHT = MCheckupTime;
		J = j;
		MSpeed = MS;
		WSpeed = WS;
		WBC = WBcount;
		MBC = MBcount;
		ID = id;
	}

	// Setters
	void SetStatus(int newStatus)
	{
		status = newStatus;
	}
	void Set_BusType(BusType bustype)
	{
		BT = bustype;
	}
	void Set_TotalNumberofBuses(int WBCount, int MBCount)
	{
		WBC = WBCount;
		MBC = MBCount;
		TB = WBC + MBC;
	}
	void SetID()
	{
		for (int i = 0; i < TB; i++)
		{
			ID = i;
		}
	}
	void Set_MBusCount(int MBcount)
	{
		MBC = MBcount;
	}
	void Set_WBusCount(int WBcount)
	{
		WBC = WBcount;
	}
	void Set_MBusCapacity(int mbcapacity)
	{
		MBCapacity = mbcapacity;
	}
	void Set_WBusCapacity(int wbcapacity)
	{
		WBCapacity = wbcapacity;
	}
	void Set_WCheckupTime(int wbcheckup)
	{
		WCHT = wbcheckup;
	}
	void Set_MCheckupTime(int mbcheckup)
	{
		MCHT = mbcheckup;
	}
	void Set_CurrBusStation(int CurrStation)
	{
		currBusStation = CurrStation;
	}
	void Set_NextBusStation(int nextStation)
	{
		nextBusStation = nextStation;
	}
	void SetTotalPassengers(int TP)
	{
		TDC = TP;
	}
	void SetFinishedJourneys(int Journey)
	{
		J = Journey;
	}
	void SetBusyTime(int T)
	{
		TBT = T;
	}
	// Getters
	BusType Getbustype()
	{
		return BT;
	}
	int Get_WBusCapacity()
	{
		return WBCapacity;
	}
	int Get_MBusCapacity()
	{
		return MBCapacity;
	}
	int Get_WCheckupTime()
	{
		return WCHT;
	}
	int Get_MCheckupTime()
	{
		return MCHT;
	}
	int GetFinishedTrips()
	{
		return J;
	}
	int Get_WSpeed()
	{
		return WSpeed;
	}
	int Get_MSpeed()
	{
		return MSpeed;
	}
	int Get_WBus_Count()
	{
		return WBC;
	}
	int Get_MBus_Count()
	{
		return MBC;
	}
	int Get_TotalNumberofBuses()
	{
		return TB = WBC + MBC;
	}
	int GetID()
	{
		return ID;
	}
	int GetStatus() const
	{
		return status;
	}
	int GetCurrBusStation()
	{
		return currBusStation;
	}
	int GetnextBusStation()
	{
		return nextBusStation;
	}
	int getTotalPassengers()
	{
		return TDC;
	}
	int GetBusyTime()
	{
		return TBT;
	}


	//// Member Functions
	float BusUtilization()
	{
		int TSIM = 18 * 60;
		int j = GetFinishedTrips();
		if (BT == WBUS)
		{
			if (j != 0)
			{
				BusUtil = (TDC / ((WBC * j) * (TBT / TSIM)));
			}
			else if (j == 0)
			{
				BusUtil = 0;
			}
		}
		else if (BT == MBUS)
		{
			if (j != 0)
			{
				BusUtil = (TDC / ((MBC * j) * (TBT / TSIM)));
			}
			else if (j == 0)
			{
				BusUtil = 0;
			}
		}
		return (BusUtil * 100);
	}

	bool firstpassenger(Passengers *& P)
	{
		if (P->getTyp() == "SP" || P->getTyp() == "NP")
		{
			return MBus.Peek(P);
		}
		else if (P->getTyp() == "WP")
		{
			return WBus.Peek(P);
		}
	}
	void addPassenger(Passengers*& P)
	{
		int Prio = abs(P->getEStaion() - P->getSStaion());
		if (P->getTyp() == "SP" || P->getTyp() == "NP")
		{
			MBus.Enqueue(P, Prio);
		}
		else if (P->getTyp() == "WP")
		{
			WBus.Enqueue(P, Prio);
		}
	}

	void removePassenger(Passengers*& P)
	{
		if (P->getTyp() == "SP" || P->getTyp() == "NP")
		{
			MBus.Dequeue(P);
		}
		else if (P->getTyp() == "WP")
		{
			WBus.Dequeue(P);
		}
	}


	void MoveFromWaitingToMoving()  // used in Phase 2 function Abdelrahman was here   Need more conditions 
	{
		if (GetStatus() == 1)
		{
			cout << "Moving Bus " << GetID() << " from waiting to moving." << endl;
			SetStatus(0); // Set status to moving
		}
		else
		{
			cout << "Bus " << GetID() << " is not in the waiting state." << endl;
		}
	}

	string GetBusDirection()
	{
		Passengers P;
		int stationdiff = P.getSStaion() - P.getEStaion();
		if (stationdiff < 0)
		{
			Direction = "FWD";
		}
		else
		{
			Direction = "BCK";
		}
		return Direction;
	}

};

