#ifndef TRAIN_H
#define TRAIN_H

#include <string>

#include "TrainSystem.h"
#include "Date.hpp"
#include "Station.hpp"
#include "Ticket.hpp"
#include "vector.hpp"
#include "map.hpp"

using std::string;
using sjtu::vector;
using sjtu::map;

class TrainNumber {
private:
	string number;
	bool selling;
	bool canceled;
	
	vector<Station> stations;
	
public:
	TrainNumber();
	~TrainNumber();
	TrainNumber(const string &number);
	
	string GetNumber() const;
	vector<Station> GetStations() const;
	void AddStation(const Station &station);
	
	bool BookTicket(const TicketInfo &info);
	bool ReturnTicket(const TicketInfo &info);
	vector<TicketsInfo> QueryTicket(const string &start, const string &end) const;
	
	bool StartSelling();
	bool StopSelling();
	
	void Cancel();
	
	friend binifstream& operator>>(binifstream &fin, TrainNumber &trainNumber) {
		vector<Station> &vec = trainNumber.stations;
		
		fin >> trainNumber.number;
		fin >> trainNumber.selling;
		fin >> trainNumber.canceled;
		
		size_t size;
		fin >> size;
		
		vec.clear();
		vec.resize(size);
		
		for(size_t i = 0; i < size; i++) {
			fin >> vec[i];
		}
		
		return fin;
	}
	friend binofstream& operator<<(binofstream &fout, const TrainNumber &trainNumber) {
		const vector<Station> &vec = trainNumber.stations;
		
		fout << trainNumber.number;
		fout << trainNumber.selling;
		fout << trainNumber.canceled;
		
		size_t size = vec.size();
		fout << size;
		
		for(size_t i = 0; i < size; i++) {
			fout << vec[i];
		}
		
		return fout;
	}
};

class TrainDay {
private:
	map<string, vector<TrainNumber>::iterator> numberMap;
	vector<TrainNumber> train;
	
	vector<TrainNumber>::iterator GetNumber(const string &number) const;
	
public:
	bool BookTicket(const TicketInfo &info);
	bool ReturnTicket(const TicketInfo &info);
	vector<TicketsInfo> QueryTicket(const string &start, const string &end) const;
	
	bool StartSelling(const string &number);
	bool StopSelling(const string &number);
	bool AddPlan(const TrainNumber &trainNumber);
	bool ModifyPlan(const TrainNumber &trainNumber);
	bool CancelPlan(const string &number);
	
	friend binifstream& operator>>(binifstream &fin, TrainDay &trainDay) {
		vector<TrainNumber> &train = trainDay.train;
		
		size_t size;
		fin >> size;
		
		train.clear();
		train.resize(size);
		for(size_t i = 0; i < size; i++) {
			fin >> train[i];
		}
		
		trainDay.numberMap.clear();
		for(vector<TrainNumber>::iterator it = train.begin(); it != train.end(); it++) {
			trainDay.numberMap[it->GetNumber()] = it;
		}
		return fin;
	}
	friend binofstream& operator<<(binofstream &fout, const TrainDay &trainDay) {
		const vector<TrainNumber> &train = trainDay.train;
		
		size_t size = train.size();
		fout << size;
		
		for(size_t i = 0; i < size; i++) {
			fout << train[i];
		}
		return fout;
	}
};

class Train {
private:
	TrainSystem *sys;
	
	map<Date, TrainDay> trains;
	
public:
	Train(TrainSystem *sys);
	~Train();
	
	bool BookTicket(const TicketInfo info);
	bool ReturnTicket(const TicketInfo &info);
	vector<TicketsInfo> QueryTicket(const Date &date, const string &start, const string &end) const;
	
	bool StartSelling(const Date &date, const string &number);
	bool StopSelling(const Date &date, const string &number);
	bool AddPlan(const Date &date, const TrainNumber &trainNumber);
	bool ModifyPlan(const Date &date, const TrainNumber &trainNumber);
	bool CancelPlan(const Date &date, const string &number);
	TrainNumber GetTrainNumber(const Date &date, const string &number);
	
	void Import(const string &path);
	
	friend binifstream& operator>>(binifstream &fin, Train &train) {
		fin >> train.trains;
		return fin;
	}
	friend binofstream& operator<<(binofstream &fout, const Train &train) {
		fout << train.trains;
		return fout;
	}
};

#endif
