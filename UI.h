#pragma once
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip> // for setw()
#include <chrono> // for sleep_for()
#include <thread> // for sleep_for()
#include"Passengers.h"
#include"Buses.h"
#include"Stations.h"
#include"List.h"
using namespace std;
class Company;
class UI
{
private:
	Time T;
	Stations s;
	int CurrentStation;

public:
	UI();
	void ChoosingMode(int x);
	void RunningProgram();
	void PrintTime(Time T);
	void PrintStation(int station);
	int getStation();
	void PrintPassengers(Queue<Passengers*> WNPFW, Queue<Passengers*> WNPBW, Queue<Passengers*> WWPFW, Queue<Passengers*> WWPBW, PriorityQueue<Passengers*> WSPFW, PriorityQueue<Passengers*> WSPBW);
	void PrintBuses(List<Buses> MBus, List<Buses>WBus);
	void PrintLine();
	void PrintFinishedPass(Queue<Passengers*> Completed);
	void InteractiveMode();
	void SilentMode();

	void awaitFunction();

};

