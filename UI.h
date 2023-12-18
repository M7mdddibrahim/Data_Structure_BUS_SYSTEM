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
class UI
{
private:
	Stations s;
	int CurrentStation;

public:
	UI();
	void ChoosingMode(int x);
	void RunningProgram();
	void PrintTime(int hour, int min);
	void PrintStation(int station);
	int getStation();
	void PrintPassengers(List<Passengers> NPF, List<Passengers> NPB, List<Passengers> WPF, List<Passengers> WPB, List<Passengers> SPF, List<Passengers> SPB);
	void PrintBuses(List<Buses> MBus, List<Buses>WBus);
	void PrintLine();
	void PrintFinishedPass(List<Passengers> Finishing_list);
	void InteractiveMode();
	void SilentMode();

};

