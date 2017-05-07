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
	
public:
	vector<Station> stations;
	
public:
	TrainNumber(const string &number);
	
	string GetNumber() const;
	
	bool BookTicket(const TicketInfo &info);
	bool ReturnTicket(const TicketInfo &info);
};

class TrainDay {
private:
	map<string, TrainNumber*> numberMap;
	vector<TrainNumber> train;
	
	TrainNumber* GetNumber(const string &number) const;
	
public:
	bool BookTicket(const TicketInfo &info);
	bool ReturnTicket(const TicketInfo &info);
	
	vector<TicketInfo> QueryTicket(const string &start, const string &end) const;
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
};

#endif
