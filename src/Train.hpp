#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <string>
#include "TrainSystem.hpp"
#include "Date.hpp"
#include "vector.hpp"
#include "Station.hpp"
#include "Ticket.hpp"

using std::string;

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
	
	bool BookTicket(const string &start, const string &end, const SeatType type, const size_t count) {
		vector<station>::iterator it_start = stations.end(), it_end = stations.end();
		
		for(vector<station>::iterator it = stations.begin(); it != stations.end(); it++) {
			if(it->name == start) {
				it_start = it;
			} else if(it->name == end) {
				it_end = it;
			}
		}
		
		bool flag = true;
		
		if(it_start != stations.end() && it_end != stations.end()) {
			for(vector<station>::iterator it = it_start; it != it_end; it++) {
				if(it->seatCount[(int) type] < count) {
					flag = false;
					break;
				}
			}
			
			if(flag == false) {
				return false;
			}
			
			for(vector<station>::iterator it = it_start; it != it_end; it++) {
				it->seatCount[(int) type] -= count;
			}
		} else {
			return false;
		}
	}
	
	bool ReturnTicket(const string &start, const string &end, const SeatType type, const size_t count) {
		vector<station>::iterator it_start = stations.end(), it_end = stations.end();
		
		for(vector<station>::iterator it = stations.begin(); it != stations.end(); it++) {
			if(it->name == start) {
				it_start = it;
			} else if(it->name == end) {
				it_end = it;
			}
		}
		
		if(it_start != stations.end() && it_end != stations.end()) {
			for(vector<station>::iterator it = it_start; it != it_end; it++) {
				it->seatCount[(int) type] += count;
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
	
	bool BookTicket(const string &trainNumber, const string &start, const string &end, const SeatType type, const size_t count) {
		for(vector<TrainNumber>::iterator it = train.begin(); it != train.end(); it++) {
			if(it->GetNumber == trainNumber) {
				it->BookTicket(start, end, type, count);
				return true;
			}
		}
		return false;
	}
	
	bool ReturnTicket(const string &trainNumber, const string &start, const string &end, const SeatType type, const size_t count) {
		for(vector<TrainNumber>::iterator it = train.begin(); it != train.end(); it++) {
			if(it->GetNumber() == trainNumber) {
				it->ReturnTicket(start, end, type, count);
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
	
	bool BookTicket(const Date &date, const string &trainNumber, const string &start, const string &end, const SeatType type, const size_t count) {
		return trains[date].BookTicket(trainNumber, start, end, type, count);
	}
	
	bool ReturnTicket(const Date &date, const string &trainNumber, const string &start, const string &end, const SeatType type, const size_t count) {
		if(!trains.count(date)) {
			return false;
		} else {
			return trains[date].ReturnTicket(trainNumber, start, end, type, count);
		}
	}
};

#endif
