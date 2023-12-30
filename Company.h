#pragma once
#include"Buses.h"
#include"Passengers.h"
#include"Stations.h"
#include"List.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include<fstream>
#include <string>
#include "UI.h"
#include <iostream>
#include <WiNdows.h>
#include <sstream>
#include<cstdlib>
using namespace std;

class Event;
constexpr auto no_ofMaxStations = 100;

class Company
{
	UI* ui;
	List<Buses> WBus;
	List<Buses> MBus;
	int no_ofStations;
	int Time_Between_Stations, WBusses_Count, MBusses_Count;
	int WBus_Capacity, MBus_Capacity, no_ofTrips, WBus_CheckupTime, MBus_CheckupTime;
	int WaitingMin, get_on_off_Time;
	int NumofEvents;
	char Event_type;
	string Pass_type;
	int timerH, timerM;
	int ArrTime , ID , SStation, EStation;
	int LTime;
	int hour;
	int min, current_station;

	// new lists starts from here 
	Time Timer;
	Queue<Event*> EventList;
	Stations stationArray[no_ofMaxStations];

	Queue<Passengers*> Completed; // passengers completed list

	Queue<Buses*> MBCheckup;
	Queue<Buses*> WBCheckup;

	Queue<Buses*> MBMovingFW;
	Queue<Buses*> MBMovingBW;

	Queue<Buses*> WBMovingFW;
	Queue<Buses*> WBMovingBW;

	Queue<Buses*> MGB; // mixed buses at garage (Station Zero)
	Queue<Buses*> WGB; // wheel buses at garage (Station Zero)

public:
	
	Company();
	void output();
	void loadFile();
	void simulation();
	//bool Leave_List(List<Passengers>current);
	void addPassenger(Passengers* P);
	//bool Leave_Passenger(int id);
	void Leave_Passenger(int STARTS, int id);
	void randomleave();
	void Next_station();
	void timeConverter(ifstream& inputFile);
	void releaseBusFromStationZero(Queue<Buses*> MGB, Queue<Buses*> WGB);
	void BoardingWPassengers();

};
