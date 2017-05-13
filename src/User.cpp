#include "TrainSystem.h"

User::User(TrainSystem *sys) : sys(sys) { }
User::User(TrainSystem *sys, const string &name, const string &userID, const string &password, const bool &isAdmin) : sys(sys), name(name), userID(userID), password(password), isAdmin(isAdmin) { }
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

vector<TicketsInfo> User::QueryTicket(const Date &date, const string &start, const string &end) const {
	return sys->train.QueryTicket(date, start, end);
}
vector<TicketInfo> User::GetOrders() const {
	vector<TicketInfo> result;
	for(map<TicketInfo, int>::const_iterator it = tickets.cbegin(); it != tickets.cend(); it++) {
		result.push_back(it->first);
		result[(int) result.size() - 1].count = it->second;
	}
	return result;
}
bool User::BookTicket(const TicketInfo &info) {
	// return true if succeed, false if fail
	bool success = sys->train.BookTicket(info);
	if(success) {
		tickets[info] += info.count;
		log.AddBook(info);
	}
	return success;
}

bool User::ReturnTicket(const TicketInfo &info) {
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

int User::GetUserType() const {
	return isAdmin;
}

bool User::AddPlan(const Date &date, const TrainNumber &trainNumber) {
	if(!isAdmin) {
		return false;
	}
	return sys->train.AddPlan(date, trainNumber);
}
bool User::ModifyPlan(const Date &date, const TrainNumber &trainNumber) {
	if(!isAdmin) {
		return false;
	}
	return sys->train.ModifyPlan(date, trainNumber);
}
bool User::CancelPlan(const Date &date, const string &number) {
	if(!isAdmin) {
		return false;
	}
	return sys->train.CancelPlan(date, number);
}
bool User::StartSelling(const Date &date, const string &number) {
	if(!isAdmin) {
		return false;
	}
	return sys->train.StartSelling(date, number);
}
bool User::StopSelling(const Date &date, const string &number) {
	if(!isAdmin) {
		return false;
	}
	return sys->train.StopSelling(date, number);
}

const Log User::QueryUser(const string &userID) const {
	if(!isAdmin) {
		return Log();
	}
	return sys->user.GetUser(userID)->GetLog();
}

string User::SystemHistory() const {
	if(!isAdmin) {
		return "";
	}
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
pair<User*, string> AllUser::Login(const string &userID, const string &password) {
	if(!map.count(userID)) {
		return make_pair(nullptr, "该用户不存在");
	} else {
		if(map[userID].GetPassword() != SHA512::GetHash(password)) {
			return make_pair(nullptr, "密码错误");
		} else {
			return make_pair(&map[userID], "");
		}
	}
}
pair<User*, string> AllUser::Register(const string &name, const string &userID, const string &password, const bool &isAdmin) {
	if(name.size() < 5 || name.size() > 16) {
		return make_pair(nullptr, "用户名长度不正确");
	}
	if(userID.size() != 9) {
		return make_pair(nullptr, "ID格式不正确");
	}
	if(password.size() < 6 || password.size() > 16) {
		return make_pair(nullptr, "密码长度不正确");
	}
	if(map.count(userID)) {
		return make_pair(nullptr, "该ID已占用");
	} else {
		return make_pair(&(map[userID] = User(sys, name, userID, SHA512::GetHash(password), isAdmin)), "");
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
void AllUser::Import(const string &path) {
	std::ifstream fin(path.c_str());
	if(!fin.is_open()) {
		return;
	}
	
	while(!fin.eof()) {
		
	}
}
