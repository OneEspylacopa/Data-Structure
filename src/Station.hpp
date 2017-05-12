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
	double price[SEAT_TYPE_NUM];
	
	Station() {
		arriveTime = Time("00:00");
		stopTime = Time("00:00");
		mileage = 0;
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			seatCount[i] = 0;
			price[i] = 0;
		}
	}
	
	Station(const string &name, const Time &arriveTime, const Time stopTime, const int &mileage, const int seatCount[SEAT_TYPE_NUM], const double price[SEAT_TYPE_NUM]) :
		name(name), arriveTime(arriveTime), stopTime(stopTime), mileage(mileage) {
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			this->seatCount[i] = seatCount[i];
			this->price[i] = price[i];
		}
	}

	binifstream operator>>(binifstream &fin) {
		fin >> name >> arriveTime >> stopTime >> mileage;
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			fin >> seatCount[i];
			fin >> price[i];
		}
		return fin;
	}
	binofstream operator<<(binofstream &fout) {
		fout << name << arriveTime << stopTime << mileage;
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			fout << seatCount[i];
			fout << price[i];
		}
		return fout;
	}
};

#endif
