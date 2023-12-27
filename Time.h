#pragma once
#include <iostream>
class Time
{


private:
	int hours;
	int min;

public:

	Time(int h, int mm);
	~Time();
	void MoveTime(int mm);


};

