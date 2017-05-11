#ifndef USER_H
#define USER_H

#include <cstring>

#include "TrainSystem.h"
#include "map.hpp"
#include "binfstream.hpp"
#include "Log.hpp"
#include "Ticket.hpp"

using std::string;

class User {
protected:
	TrainSystem *sys;
	
	string name; // username
	string userID; // user's ID 
	string password; // user's password 
	Log log; // user's log
	
	map<TicketInfo, int> tickets; // info -> count
	
public:
	User() { }
	User(TrainSystem *sys);
	User(TrainSystem *sys, const string &name, const string &userID, const string &password);
	~User();
	
	friend binifstream& operator>>(binifstream &fin, User &rhs) {
		fin >> rhs.name >> rhs.userID >> rhs.password >> rhs.log;
		return fin;
	}
	friend binofstream& operator<<(binofstream &fout, const User &rhs) {
		fout << rhs.name << rhs.userID << rhs.password << rhs.log;
		return fout;
	}

	void ModifyInfo(const string &_name, const string &_password);
	
	string GetName() const;
	string GetID() const;
	string GetPassword() const;
	Log GetLog() const;
};

class GeneralUser : public User {
public:
	GeneralUser();
	~GeneralUser();
	
	vector<TicketsInfo> QueryTicket(const string &start, const string &end, const Date &date) const;
	
	bool BookTicket(const TicketInfo &info);
	bool ReturnTicket(const TicketInfo &info);
};

class Administrator : public User {
public:
	Administrator();
	~Administrator();
	
	bool AddPlan(const Date &date, const TrainNumber &trainNumber);
	bool ModifyPlan(const Date &date, const TrainNumber &trainNumber);
	bool CancelPlan(const Date &date, const string &number);
	bool StartSelling(const Date &date, const string &number);
	bool StopSelling(const Date &date, const string &number);
	
	const Log QueryUser(const string &userID) const;
	
	string SystemHistory() const;
};
	
class AllUser {
private:
	TrainSystem *sys;
	
private:
	sjtu::map<string, User> map; // user's ID -> User 
	
public:
	AllUser(TrainSystem* sys);
	~AllUser();
	
	User* GetUser(const string &userID);
	User* Login(const string &userID, const string &password);
	User* Register(const string &name, const string &userID, const string &password);
	
	string SystemHistory() const;
	
	binifstream& operator>>(binifstream &fin);
	binofstream& operator<<(binofstream &fout);
};

#endif
