#include "TrainSystem.h"

User::User(TrainSystem *sys) : sys(sys) { }
User::User(TrainSystem *sys, const string &name, const string &userID, const string &password) : sys(sys), name(name), userID(userID), password(password) { }
User::~User() { }

void User::ModifyInfo(const string &_name, const string &_password) {
	name = _name;
	password = _password;
}

string User::GetName() const {
	return name;
}
string User::GetID() const {
	return userID;
}
string User::GetPassword() const {
	return password;
}

Log User::GetLog() const {
	return log;
}

GeneralUser::GeneralUser() : User(sys) {}
GeneralUser::~GeneralUser() {}

TicketInfo GeneralUser::QueryTicket(const string &start, const string &end, const Date &date) const {
	return sys->train.QueryTicket(start, end, date);
}

bool GeneralUser::BookTicket(const TicketInfo &info) {
	// return true if succeed, false if fail
	bool success = sys->train.BookTicket(info);
	if(success) {
		log.AddBook(info);
	}
	return success;
}

bool GeneralUser::ReturnTicket(const TicketInfo &info) {
	// return true if succeed, false if fail
	bool success = sys->train.ReturnTicket(info);
	if(success) {
		log.AddReturn(info);
	}
	return success;
}

Administrator::Administrator() : User(sys) {}
Administrator::~Administrator() {}

void Administrator::AddPlan() {
	
}
bool Administrator::ModifyPlan() {
	
}
bool Administrator::CancelPlan() {
	
}
bool Administrator::BeginToSell() {
	
}
bool Administrator::StopToSell() {
	
}

const Log Administrator::QueryUser(const string &userID) const {
	return sys->user.GetUser(userID)->GetLog();
}

string Administrator::SystemHistory() const {
	return AllUser::SystemHistory();
}
	
AllUser::AllUser(TrainSystem* sys) : sys(sys) {}
AllUser::~AllUser() {}

User* AllUser::GetUser(const string &userID) {
	if(!map.count(userID)) {
		return nullptr;
	} else {
		return &map[userID];
	}
}	
User* AllUser::Register(const string &name, const string &userID, const string &password) {
	if(map.count(userID)) {
		return nullptr;
	} else {
		return &(map[userID] = User(sys, name, userID, password));
	}
}
