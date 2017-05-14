#ifndef USER_H
#define USER_H

#include <cstring>

#include "TrainSystem.h"
#include "map.hpp"
#include "binfstream.hpp"
#include "Log.hpp"
#include "Ticket.hpp"

#include <bits/stdc++.h>
using std::string;
using sjtu::pair;

class User {
private:
	TrainSystem *sys;
	
	string name; // username
	string userID; // user's ID
	string password; // user's password
	bool isAdmin;
	
	Log log; // user's log
	
	map<TicketInfo, int> tickets; // info -> count
	
public:
	User() { }
	User(TrainSystem *sys);
	User(TrainSystem *sys, const string &name, const string &userID, const string &password, const bool &isAdmin);
	~User();
	
    string ModifyInfo(const string &_name, const string &_password);
	
	string GetName() const;
	string GetID() const;
	string GetPassword() const;
	Log GetLog() const;
	
	int GetUserType() const;
	
	//General User
	vector<TicketsInfo> QueryTicket(const Date &date, const string &start, const string &end) const;
	vector<TicketInfo> GetOrders() const;
	
	bool BookTicket(const TicketInfo &info);
	bool ReturnTicket(const TicketInfo &info);
	
	//Administrator
	bool AddPlan(const Date &date, const TrainNumber &trainNumber);
	bool ModifyPlan(const Date &date, const TrainNumber &trainNumber);
	bool CancelPlan(const Date &date, const string &number);
	bool StartSelling(const Date &date, const string &number);
	bool StopSelling(const Date &date, const string &number);
	
	const Log QueryUser(const string &userID) const;
	
	string SystemHistory() const;
	
	// I/O
	friend binifstream& operator>>(binifstream &fin, User &rhs) {
		fin >> rhs.name >> rhs.userID >> rhs.password >> rhs.isAdmin >> rhs.log >> rhs.tickets;
		return fin;
	}
	friend binofstream& operator<<(binofstream &fout, const User &rhs) {
		fout << rhs.name << rhs.userID << rhs.password << rhs.isAdmin << rhs.log << rhs.tickets;
		return fout;
	}
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
	pair<User*, string> Login(const string &userID, const string &password);
	pair<User*, string> Register(const string &name, const string &userID, const string &password, const bool &isAdmin);
	
	string SystemHistory() const;
	
	void Import(const string &path);
	
	friend binifstream& operator>>(binifstream &fin, AllUser &user) {
		fin >> user.map;
		return fin;
	}
	friend binofstream& operator<<(binofstream &fout, const AllUser &user) {
		fout << user.map;
		return fout;
	}
};

#endif
