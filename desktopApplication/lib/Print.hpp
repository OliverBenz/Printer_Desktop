#pragma once

#include <string>
#include <ostream>
#include "Date.hpp"
#include "Time.hpp"

class Print{
	int id, roll, count;
	float length, weight, price;

	std::string user, projectName, notes, status, printName;

	Date date, dateUntil, datePlanned, dateDone;
	Time time, timeReal;

public:
	Print();
	Print(int id, int roll, int count, float length, float weight, float price);
	Print(std::string print);

	Time getTimeDiff();
	std::string getUser();
	std::string getPrintName();

	friend std::ostream& operator <<(std::ostream& os, Print p);
};

