#include "Time.h"

Time::Time()
{
	hours = 4;
	min = 0;
}
Time::Time(int h, int mm)
{
	hours = h;
	min = mm;
}


void Time::SetHours(int TotalHours)
{
	hours = TotalHours;
}
void Time::SetMin(int TotalMin)
{
	min = TotalMin;
}
int Time::getHours()
{
	return hours;
}
int Time::getMin()
{
	return min;
}


void Time::IncrementHour()
{
	hours++;
}
void Time::IncrementMin()
{
	if (min+1 == 59 )
	{
		min = 0;
		hours++;
	}
	else
	{
		min++;
	}
}

void Time::MoveTime(int mm)
{
	min = mm + min;
	if (hours > 24) {
		hours = hours % 24; // uptade next day 
	}
	if (min >= 60) {   //uptade minutes and hours
		hours = hours + (min / 60);
		min = min - ((min / 60) * 60);
	}
}
Time::~Time()
{
	// Destructor
}
