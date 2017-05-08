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
	
public:
	vector<Station> stations;
	
public:
	TrainNumber(const string &number);
	
	string GetNumber() const;
	
	bool BookTicket(const TicketInfo &info);
	bool ReturnTicket(const TicketInfo &info);
	
	bool StartSelling();
	bool StopSelling();
	
	void Cancel();
	
	binifstream& operator>>(binifstream &fin) {
		vector<Station> &vec = stations;
		
		fin >> number;
		fin >> selling;
		fin >> canceled;
		
		size_t size;
		fin >> size;
		
		vec.clear();
		vec.resize(size);
		
		for(size_t i = 0; i < size; i++) {
			fin >> vec[i];
		}
		
		return fin;
	}
	binofstream& operator<<(binofstream &fout) {
		const vector<Station> &vec = stations;
		
		fout << number;
		fout << selling;
		fout << canceled;
		
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
	vector<TicketInfo> QueryTicket(const string &start, const string &end) const;
	
	bool StartSelling(const string &number);
	bool StopSelling(const string &number);
	bool AddPlan(const TrainNumber &trainNumber);
	bool ModifyPlan(const TrainNumber &trainNumber);
	bool CancelPlan(const string &number);
	
	binifstream& operator>>(binifstream &fin);
	binofstream& operator<<(binofstream &fout);
};

class Train {
private:
	TrainSystem *sys;
	
public:
	map<Date, TrainDay> trains;
	
public:
	Train(TrainSystem *sys);
	~Train();
	
	bool BookTicket(const TicketInfo info);
	bool ReturnTicket(const TicketInfo &info);
	vector<TicketInfo> QueryTicket(const string &start, const string &end, const Date &date) const;
	
	bool StartSelling(const Date &date, const string &number);
	bool StopSelling(const Date &date, const string &number);
	bool AddPlan(const Date &date, const TrainNumber &trainNumber);
	bool ModifyPlan(const Date &date, const TrainNumber &trainNumber);
	bool CancelPlan(const Date &date, const string &number);
	
	binifstream& operator>>(binifstream &fin);
	binofstream& operator<<(binofstream &fout);
};

#endif
