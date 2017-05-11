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

GeneralUser::GeneralUser() : User(sys) { }
GeneralUser::~GeneralUser() { }

vector<TicketsInfo> GeneralUser::QueryTicket(const Date &date, const string &start, const string &end) const {
	return sys->train.QueryTicket(date, start, end);
}

bool GeneralUser::BookTicket(const TicketInfo &info) {
	// return true if succeed, false if fail
	bool success = sys->train.BookTicket(info);
	if(success) {
		tickets[info] += info.count;
		log.AddBook(info);
	}
	return success;
}

bool GeneralUser::ReturnTicket(const TicketInfo &info) {
	// return true if succeed, false if fail
	bool success = sys->train.ReturnTicket(info);
	if(success) {
		tickets[info] -= info.count;
		if(tickets[info] == 0) {
			tickets.erase(tickets.find(info));
		}
		log.AddReturn(info);
	}
	return success;
}

Administrator::Administrator() : User(sys) {}
Administrator::~Administrator() {}

bool Administrator::AddPlan(const Date &date, const TrainNumber &trainNumber) {
	return sys->train.AddPlan(date, trainNumber);
}
bool Administrator::ModifyPlan(const Date &date, const TrainNumber &trainNumber) {
	return sys->train.ModifyPlan(date, trainNumber);
}
bool Administrator::CancelPlan(const Date &date, const string &number) {
	return sys->train.CancelPlan(date, number);
}
bool Administrator::StartSelling(const Date &date, const string &number) {
	return sys->train.StartSelling(date, number);
}
bool Administrator::StopSelling(const Date &date, const string &number) {
	return sys->train.StopSelling(date, number);
}

const Log Administrator::QueryUser(const string &userID) const {
	return sys->user.GetUser(userID)->GetLog();
}

string Administrator::SystemHistory() const {
	return sys->user.SystemHistory();
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
User* AllUser::Login(const string &userID, const string &password) {
	if(!map.count(userID)) {
		return nullptr;
	} else {
		if(map[userID].GetPassword() != SHA512::GetHash(password)) {
			return nullptr;
		} else {
			return &map[userID];
		}
	}
}
User* AllUser::Register(const string &name, const string &userID, const string &password) {
	if(map.count(userID)) {
		return nullptr;
	} else {
		return &(map[userID] = User(sys, name, userID, SHA512::GetHash(password)));
	}
}
string AllUser::SystemHistory() const {
	string result;
	int count;
	binifstream fin;
	fin.open(sys->GetSystemHistory().c_str());
	fin >> count;
	for(int i = 1; i <= count; i++) {
		string str;
		fin >> str;
		result.append(str);
	}
	return result;
}
binifstream& AllUser::operator>>(binifstream &fin) {
	fin >> map;
	return fin;
}
binofstream& AllUser::operator<<(binofstream &fout) {
	fout << map;
	return fout;
}
