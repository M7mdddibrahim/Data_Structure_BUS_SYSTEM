#include "Passengers.h"


Passengers::Passengers()
{
	//AT = 0;
	SStaion = 0;
	EStaion = 0;
	ON_OFFTime = 0;
	Priority = 0;
}

void Passengers::setID(int id)
{
	ID = id;
}

void  Passengers::setSPtyp(string spTyp)
{
	SPTyp = spTyp;
}
void  Passengers::setTyp(string T)
{
	Typ = T;
}

void  Passengers::setAT(Time& Atime)
{
	AT = Atime;
}
void  Passengers::setLT(int leaveTime)
{
	LT = leaveTime;
}

void  Passengers::setSStaion(int SStation)
{
	SStaion = SStation;
}

void  Passengers::setEStaion(int EStation)
{
	EStaion = EStation;
}

void  Passengers::setOn_OffTime(int OnOffTime)
{
	ON_OFFTime = OnOffTime;
}

int  Passengers::getOn_OffTime()
{
	return(ON_OFFTime);
}
string  Passengers::getSPtyp()
{
	return SPTyp;
}

string  Passengers::getTyp()
{
	return Typ;
}

Time  Passengers::getAT()
{
	return AT;
}

int  Passengers::getID()
{
	return ID;
}
int  Passengers::getSStaion()
{
	return SStaion;
}

int  Passengers::getEStaion()
{
	return EStaion;
}

void  Passengers::CalcPrio()
{
	if (Typ == "SP")
	{
		if (SPTyp == "aged")
		{
			Priority = 4;
			return;
		}
		if (SPTyp == "POD") // zu el e7tigat el 5asa
		{
			Priority = 3;
			return;
		}
		if (SPTyp == "PW")
		{
			Priority = 2;
			return;
		}
	}
	if (Typ == "NP")
	{
		Priority = 1;
		return;
	}
	if (Typ == "WP")
	{
		Priority = 0;
		return;
	}
}

void  Passengers::setPrio(int Prio)
{
	Priority = Prio;
}

int  Passengers::getPrio()
{
	return Priority;
}

void  Passengers::setPassengerDir()
{
	int E = getEStaion();
	int S = getSStaion();
	if ((S - E) < 0)
	{
		PassDir = "FWD";
	}
	else
	{
		PassDir = "BCK";
	}
}
string  Passengers::getPassengerDir()
{
	return PassDir;
}

//operator overloading of the peocess
ostream& operator<<(ostream& output, Passengers* p1)
{
	output << p1->ID << " "; //print the id of the process
	return output;
}

bool operator==(Passengers& p1, Passengers& p2) 
{
	return p1.ID == p2.ID; // Check if the IDs are equal
}

bool operator!=(Passengers& p1, Passengers& p2)
{
	return p1.ID == p2.ID; // Check if the IDs are equal
}
ostream& operator<<(ostream& output, Passengers p1)
{
	output << p1.ID << " "; //print the id of the process
	return output;
}