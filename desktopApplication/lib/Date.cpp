#include "Date.hpp"
#include <sstream>
#include <vector>

Date::Date() {
	day = -1;
	month = -1;
	year = -1;
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(std::string d) {
	if (d == "") {
		this->day = -1;
		this->month = -1;
		this->year = -1;
	}
	else {
		std::stringstream ss(d);

		std::vector<std::string> vals;
		std::string temp;
		while (getline(ss, temp, '.')) vals.push_back(temp);

		this->day = stoi(vals[0]);
		this->month = stoi(vals[1]);
		this->year = stoi(vals[2]);
	}
}

std::ostream& operator << (std::ostream& os, Date& d) {
	return (os << d.day << "." << d.month << "." << d.year);
}