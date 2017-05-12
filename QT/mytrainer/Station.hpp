#ifndef STATION_HPP
#define STATION_HPP

#include <cstring>
#include "binfstream.hpp"

#include "Time.hpp"
#include "Ticket.hpp"

using std::string;

class Station {
public:
	string name;
	Time arriveTime;
	Time stopTime;
	int mileage;
	int seatCount[SEAT_TYPE_NUM];
	
	Station(const string &name, const Time &arriveTime, const Time stopTime, const int &mileage, const int seatCount[SEAT_TYPE_NUM]) :
		name(name), arriveTime(arriveTime), stopTime(stopTime), mileage(mileage) {
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			this->seatCount[i] = seatCount[i];
		}
	}

	binifstream operator>>(binifstream &fin) {
		fin >> name >> arriveTime >> stopTime >> mileage;
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			fin >> seatCount[i];
		}
		return fin;
	}
	binofstream operator<<(binofstream &fout) {
		fout << name << arriveTime << stopTime << mileage;
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			fout << seatCount[i];
		}
		return fout;
	}
};

#endif
