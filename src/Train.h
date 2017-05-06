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
public:
	vector<TrainNumber> train;
	
	bool BookTicket(const TicketInfo &info);
	bool ReturnTicket(const TicketInfo &info);
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
	TicketInfo QueryTicket(const string &start, const string &end, const Date &date) const;
};

#endif
