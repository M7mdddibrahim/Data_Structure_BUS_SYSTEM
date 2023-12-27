#pragma once
#include "Buses.h"
#include "Passengers.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "List.h"
#include <string>
#include "NPQ.h"
#include <iostream>
using namespace std;


class Stations: public Passengers
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
	Queue<Buses*>Qbus;
	/*_LINKEDLIST<Stations*>LS;*/
	PriorityQueue<Passengers*> StpassengersFW;
	PriorityQueue<Passengers*> NtpassengersFW;
	PriorityQueue<Passengers*> WCpassengersFW;

	PriorityQueue<Passengers*> StpassengersBW;
	PriorityQueue<Passengers*> NtpassengersBW;
	PriorityQueue<Passengers*> WCpassengersBW;

	// Passengers waiting lists
	PriorityQueue<Passengers*> WSPFW;
	PriorityQueue<Passengers*> WSPBW;

	Queue<Passengers*> WWPFW;
	Queue<Passengers*> WWPBW;

	//NPQ<Passengers*> WNPFW;
	//NPQ<Passengers*> WNPBW;

	// Buses Waiting at Stations
	Queue<Buses*> FWBusList;
	Queue<Buses*> BWBusList;

public:
	Stations();
	Stations(string loc, int Stid, int Stationsnum, int TS);
	void AddPassengers(Passengers* P);
	void setStationid(int Stid);
	void setLocation(string loc);
	void setStationsnumber(int Stationsnum);
	void SetTimeBetweenSta(int time);
	int getStationID();
	int getStationsnumber();
	int getTimeBetweenSta();


};
	//bool CheckFulljourney();   // checks if the bus complete the journey or not
	//bool CheckCapacity(MaxStationCapacity);    // checks if the stations has reached its full capacity or not 
	//int AddBus();       // add bus to the staion if the stations capacity is good to add 
	//int RemoveBus();  // remove a bus index from the capacity when its leaving the station