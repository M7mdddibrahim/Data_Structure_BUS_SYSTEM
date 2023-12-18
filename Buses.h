#pragma once
#include"Passengers.h"
#include"Time.h"
#include"DEFS.h"
#include<iostream>
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
	int MBC;              //MBus_Count
	int TB;               // Total Number of Buses
	int WSpeed;           // Speed of Wheel Busses
	int MSpeed;     // Speed of Mixed Busses
	float BusUtil;  // Bus Utilization  
	int ID;
	string Direction;  // Direction of the Bus
	//Time Mt; // Move Time
	//Passengers TDC; // Total Passengers Transported by the Bus
	//Time TBT; // Total Busy Time for this Bus
	//Time TSIM; // Total Simulation Time

public:
	Buses()
	{
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
		return TB=WBC+MBC;
	}
	int GetID()
	{
		return ID;
	}
	//Time GetMoveTime();
	//Time GetBusyTime();
	//Time GetSimulationTime();


	//// Member Functions
	//float BusUtilization()
	//{
	//	int j = GetFinishedTrips();
	//	if (BT == WBUS)
	//	{
	//		if (j != 0)
	//		{
	//			BusUtil = (TDC / ((WBC * j) * (TBT / TSIM)));
	//		}
	//		else if (j == 0)
	//		{
	//			BusUtil = 0;
	//		}
	//	}
	//	else if (BT == MBUS)
	//	{
	//		if (j != 0)
	//		{
	//			BusUtil = (TDC / ((MBC * j) * (TBT / TSIM)));
	//		}
	//		else if (j == 0)
	//		{
	//			BusUtil = 0;
	//		}
	//	}
	//	return (BusUtil * 100);
	//}
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
