#pragma once
#include"Buses.h"
#include"Passengers.h"
#include"Stations.h"
#include"List.h"
#include"ArrivalEvent.h"
#include<fstream>
#include"Event.h"
#include <vector>
#include <string>
#include "Queue.h"
#include "PriorityQueue.h"
#include"LeaveEvent.h"
#include "Event.h"
#include "UI.h"
#include <iostream>
#include <WiNdows.h>
#include <sstream>
#include<cstdlib>
using namespace std;


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
	List<Passengers> NPF;
	List<Passengers> NPB;
	List<Passengers> WPF;
	List<Passengers> WPB;
	List<Passengers> SPF;
	List<Passengers> SPB;
	List<Passengers> Finishing_list;


public:
	
	Company();
	void output();
	void loadFile();
	void simulation();
	void timeIncremeter();
	bool Leave_List(List<Passengers>current);
	bool Leave_Passenger(int id);
	void randomleave(List<Passengers> NPF, List<Passengers> NPB, List<Passengers> WPF, List<Passengers> WPB, List<Passengers> SPF, List<Passengers> SPB);
	void Next_station();
	int timeConverter(ifstream& inputFile);

};
