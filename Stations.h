#pragma once
#include "Buses.h"
#include "Passengers.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "List.h"
#include <string>
#include "NPQ.h"
#include "Time.h"
#include <iostream>
using namespace std;

class Company;
class Stations
{
private:
	int Distance;
	int numofstations;
	int StationZero;
	int MaxStationCapacity;
	string StationLocation;
	int StationEnd;
	int StationId;
	int BusId;
	int TBS;    // Time Betweeen Stations
	Company* C;
	Queue<Buses*>Qbus;

	// Passengers waiting lists
	PriorityQueue<Passengers*> WSPFW;
	PriorityQueue<Passengers*> WSPBW;

	Queue<Passengers*> WWPFW;
	Queue<Passengers*> WWPBW;

	Queue<Passengers*> WNPFW;
	Queue<Passengers*> WNPBW;

	// Buses Waiting at Stations
	Queue<Buses*> FWBusList;
	Queue<Buses*> BWBusList;
public:
	Stations();
	Stations(string loc, int Stid, int Stationsnum, int TS);
	Stations(int Stationsnum);
	// Setters
	void setStationid(int Stid);
	void setLocation(string loc);
	void setStationsnumber(int Stationsnum);
	void SetTimeBetweenSta(int time);
	// Getters
	int getStationID();
	int getStationsnumber();
	int getTimeBetweenSta();
	Queue<Buses*>& getFWBusList();
	Queue<Buses*>& getBWBusList();
	Queue<Passengers*>& getNormalPF();
	Queue<Passengers*>& getNormalPB();
	Queue<Passengers*>& getWheelPF();
	Queue<Passengers*>& getWheelPB();
	PriorityQueue<Passengers*>& getSpecialPF();
	PriorityQueue<Passengers*>& getSpecialPB();
	// Functions
	void AddPassengers(Passengers* P);
	bool RemovePassenger(Queue<Passengers*>&p, int id);
	void changeBusStatus(int busId, Queue<Buses*>& FWBusList, Queue<Buses*>& BWBusList); // from moving to waiting 
	void MoveBusFromWaitingToMoving(int busId, Queue<Buses*>& FWBusList, Queue<Buses*>& BWBusList, Queue<Buses*>& MBMovingFW, Queue<Buses*>& MBMovingBW, Queue<Buses*>& WBMovingFW, Queue<Buses*>& WBMovingBW); // from waiting to moving 
	void BoardingWP(Queue<Passengers*>& WWPFW, Queue<Passengers*>& WWPBW, Queue<Buses*>& FWBusList, Queue<Buses*>& BWBusList);
	//void busWaitingToMoving(Queue<Buses*> FWBusList, Queue<Buses*> BWBusListQueue<Buses*> BWBusList);
	void FinishPass( Queue<Passengers*>& Completed);
	void BoardingSPNP(PriorityQueue<Passengers*>& WSPFW, PriorityQueue<Passengers*>& WSPBW, Queue<Passengers*>& WNPFW, Queue<Passengers*>& WNPBW, Queue<Buses*>& FWBusList, Queue<Buses*>& BWBusList);
};

