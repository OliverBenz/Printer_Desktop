#include "Print.hpp"
#include <sstream>
#include <vector>
#include <algorithm>

Print::Print() {
	id = 0; roll = 0; count = 0;
	length = 0.0f; weight = 0.0f; price = 0.0f;
	user = ""; projectName = ""; notes = ""; status = ""; printName = "";

	date = Date(); dateUntil = Date(); datePlanned = Date(); dateDone = Date();
	time = Time(); timeReal = Time();
}

Print::Print(int id, int roll, int count, float length, float weight, float price) {
	this->id = id;
	this->roll = roll;
	this->count = count;
	this->length = length;
	this->weight = weight;
	this->price = price;
}

Print::Print(std::string line) {
	std::stringstream ssLine(line);

	std::vector<std::string> values;
	std::string temp;
	while (getline(ssLine, temp, '@')) values.push_back(temp);

	// Replace ',' in float values with '.'
	for (size_t i = 13; i <= 15; i++) replace(values[i].begin(), values[i].end(), ',', '.');

	this->id = stoi(values[0]);
	this->roll = stoi(values[1]);
	this->count = stoi(values[2]);
	this->length = stof(values[13]);
	this->weight = stof(values[14]);
	this->price = stof(values[15]);

	this->time = Time(values[12]);
	this->timeReal = Time(values[16]);

	this->user = values[3];
	this->projectName = values[8];
	this->notes = values[9];
	this->status = values[10];
	this->printName = values[11];

	this->date = Date(values[4]);
	this->dateUntil = Date(values[5]);
	this->datePlanned = Date(values[6]);
	this->dateDone = Date(values[7]);

}

// Getter
Time Print::getTimeDiff() {
	if (timeReal.hours != -1 && timeReal.minutes != -1) {
		Time t(time.hours - timeReal.hours, time.minutes - timeReal.minutes, time.seconds - timeReal.seconds);
		return t;
	}
	
	return Time();
}

std::string Print::getUser() {
	return user;
}

std::string Print::getPrintName() {
	return printName;
}


std::ostream& operator <<(std::ostream& os, Print p) {
	os << "------------------------------" << std::endl;
	os << p.id << " - " << p.user << ": " << p.printName << " - " << p.status << std::endl;
	os << "Time: " << p.time << "  Length: " << p.length << "  Weight: " << p.weight << "  Price: " << p.price << std::endl;
	os << "Roll: " << p.roll << "  Count: " << p.count << std::endl;

	os << "Date: " << p.date << "  Duedate: " << p.dateUntil << "  Planned: " << p.datePlanned;
	if (p.status == "Done") os << "  Done: " << p.dateDone << std::endl;
	else os << std::endl;

	return os;
}