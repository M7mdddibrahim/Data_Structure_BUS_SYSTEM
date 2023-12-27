#include "Time.h"

Time::Time(int h, int mm)
{

	hours = h;
	min = mm;


}

Time::~Time()
{
	// Destructor
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
