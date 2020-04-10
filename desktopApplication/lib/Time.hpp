#pragma once

#include <ostream>
#include <string>

class Time{
public:
	int hours, minutes, seconds;

	Time();
	Time(int hours, int minutes, int seconds);
	Time(std::string t);

	friend std::ostream& operator << (std::ostream& os, Time& t);
};