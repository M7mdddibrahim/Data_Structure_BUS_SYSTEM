#pragma once
#include"Queue.h"
#include "PriorityQueue.h"
#include<iostream>
using namespace std;
class Passengers
{
private:
	string SPTyp; // passenger Special Type
	string Typ; // passenger type
	int AT; // Arrival Time
	int SStaion; //Start Station
	int EStaion; // End Station
	int ON_OFFTime; // passenger Get on/Off Time
	int Priority; // passenger Priority
	int LT; 
	int ID;
	string PassDir;

public:
	Passengers();
	Passengers(string spTyp, string T, int AT, int SS, int ES, int OnOffTime, int Prio)
	{
		setSPtyp(spTyp);
		setTyp(T);
		setAT(AT);
		setSStaion(SS);
		setEStaion(ES);
		setOn_OffTime(OnOffTime);
		setPrio(Prio);
	}

	Passengers(string T, int AT, int SS, int ES, int OnOffTime)
	{
		setTyp(T);
		setAT(AT);
		setSStaion(SS);
		setEStaion(ES);
		setOn_OffTime(OnOffTime);
	}

	void setID(int id);
	void setSPtyp(string spTyp);
	void setTyp(string T);

	void setAT(int Atime);
	void setLT(int leaveTime);

	void setSStaion(int SStation);

	void setEStaion(int EStation);
	void setOn_OffTime(int OnOffTime);

	int getOn_OffTime();
	string getSPtyp();

	string getTyp();
	int getAT();
	int getID();
	int getSStaion();

	int getEStaion();

	void CalcPrio();

	void setPrio(int Prio);

	int getPrio();

	void setPassengerDir();
	string getPassengerDir();
	friend ostream& operator<<(ostream& output, Passengers* p1);
	friend bool operator==(Passengers& p1, Passengers& p2);
	friend bool operator!=(Passengers& p1, Passengers& p2);
	friend ostream& operator<<(ostream& output, Passengers p1);

};
