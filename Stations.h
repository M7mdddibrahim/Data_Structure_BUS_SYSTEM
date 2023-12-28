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

	//// Lists to store the forward and backward passengers
	//List<Passengers*> NPF;      
	//List<Passengers*> NPB;
	//List<Passengers*> WPF;
	//List<Passengers*> WPB;

	//// priority queues of forward and backward Special Passengers
	//PriorityQueue<Passengers*> SPF;
	//PriorityQueue<Passengers*> SPB;


	/*_LINKEDLIST<Stations*>LS;*/
	PriorityQueue<Passengers*> StpassengersFW; //adym
	PriorityQueue<Passengers*> NtpassengersFW; //adym
	PriorityQueue<Passengers*> WCpassengersFW; //adym

	PriorityQueue<Passengers*> StpassengersBW; //adym
	PriorityQueue<Passengers*> NtpassengersBW; //adym
	PriorityQueue<Passengers*> WCpassengersBW; //adym

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

	Queue<Passengers*> getNormalPF();
	Queue<Passengers*> getNormalPB();
	Queue<Passengers*> getWheelPF();
	Queue<Passengers*> getWheelPB();
	PriorityQueue<Passengers*> getSpecialPF();
	PriorityQueue<Passengers*> getSpecialPB();

	// Functions
	void AddPassengers(Passengers* P);
	bool RemovePassenger(Queue<Passengers*> p, int id);
};
	//bool CheckFulljourney();   // checks if the bus complete the journey or not
	//bool CheckCapacity(MaxStationCapacity);    // checks if the stations has reached its full capacity or not 
	//int AddBus();       // add bus to the staion if the stations capacity is good to add 
	//int RemoveBus();  // remove a bus index from the capacity when its leaving the station