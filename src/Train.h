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
	
	binifstream& operator>>(binifstream &fin);
	binofstream& operator<<(binofstream &fout);
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
	
	binifstream& operator>>(binifstream &fin);
	binofstream& operator<<(binofstream &fout);
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
	
	void Import(const string &path);
	
	binifstream& operator>>(binifstream &fin);
	binofstream& operator<<(binofstream &fout);
};

#endif
