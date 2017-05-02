#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <string>

#include "TrainSystem.hpp"
#include "Date.hpp"
#include "vector.hpp"
#include "Station.hpp"
#include "Ticket.hpp"
#include "vector.hpp"

using std::string;
using sjtu::vector;

class TrainNumber {
private:
	string number;
	vector<Station> stations;
	
public:
	
	TrainNumber(const string &number) : number(number) { }
	
	string GetNumber() const {
		return number;
	}
	
	vector<Station>& GetStation() {
		return stations;
	}
	
	bool BookTicket(const TicketInfo &info) {
		vector<Station>::iterator it_start = stations.end(), it_end = stations.end();
		
		for(vector<Station>::iterator it = stations.begin(); it != stations.end(); it++) {
			if(it->name == info.start) {
				it_start = it;
			} else if(it->name == info.end) {
				it_end = it;
			}
		}
		
		bool flag = true;
		
		if(it_start != stations.end() && it_end != stations.end()) {
			for(vector<Station>::iterator it = it_start; it != it_end; it++) {
				if(it->seatCount[(int) type] < info.count) {
					flag = false;
					break;
				}
			}
			
			if(flag == false) {
				return false;
			}
			
			for(vector<Station>::iterator it = it_start; it != it_end; it++) {
				it->seatCount[(int) type] -= info.count;
			}
			
			return true;
		} else {
			return false;
		}
	}
	
	bool ReturnTicket(const TicketInfo &info) {
		vector<station>::iterator it_start = stations.end(), it_end = stations.end();
		
		for(vector<station>::iterator it = stations.begin(); it != stations.end(); it++) {
			if(it->name == info.start) {
				it_start = it;
			} else if(it->name == info.end) {
				it_end = it;
			}
		}
		
		if(it_start != stations.end() && it_end != stations.end()) {
			for(vector<station>::iterator it = it_start; it != it_end; it++) {
				it->seatCount[(int) type] += info.count;
			}
		} else {
			return false;
		}
	}
};

class TrainDay {
private:
	vector<TrainNumber> train;
	
public:
	
	const vector<TrainNumber>& GetTrain() const {
		return train;
	}
	
	bool BookTicket(const TicketInfo &info) {
		for(vector<TrainNumber>::iterator it = train.begin(); it != train.end(); it++) {
			if(it->GetNumber() == info.trainNumber) {
				it->BookTicket(info);
				return true;
			}
		}
		return false;
	}
	
	bool ReturnTicket(const TicketInfo &info) {
		for(vector<TrainNumber>::iterator it = train.begin(); it != train.end(); it++) {
			if(it->GetNumber() == info.trainNumber) {
				it->ReturnTicket(info);
				return true;
			}
		}
		return false;
	}
};

class Train {
private:
	TrainSystem *sys;
	map<Date, TrainDay> trains;
	
public:
	Train(TrainSystem *sys) : sys(sys) { }
	~Train() { }
	
	TrainDay& GetTrainDay(const Date &date) {
		return trains[date];
	}
	
	bool BookTicket(const TicketInfo info) {
		return trains[info.date].BookTicket(info);
	}
	
	bool ReturnTicket(const TicketInfo &info) {
		if(!trains.count(info.date)) {
			return false;
		} else {
			return trains[info.date].ReturnTicket(info);
		}
	}
};

#endif
