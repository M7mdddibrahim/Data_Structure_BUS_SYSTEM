#pragma once
#include <iostream>
class Time
{

private:
	int hours;
	int min;

public:
	Time();
	Time(int h, int mm);

	// Setters
	void SetHours(int TotalHours);
	void SetMin(int TotalMin);

	// Getters
	int getHours();
	int getMin();

	// Function
	void IncrementHour();
	void IncrementMin();
	void MoveTime(int mm);
	bool operator==(const Time& other) const;
	bool operator!=(const Time& other) const;
	~Time();


};

