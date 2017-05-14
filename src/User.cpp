#include "TrainSystem.h"

using sjtu::pair;

User::User(TrainSystem *sys) : sys(sys) { }
User::User(TrainSystem *sys, const string &name, const string &userID, const string &password, const bool &isAdmin) : sys(sys), name(name), userID(userID), password(password), isAdmin(isAdmin) { }
User::~User() { }

string User::ModifyInfo(const string &_name, const string &_password) {
	if(_name.size() < 5 || _name.size() > 16) {
		return string("用户名长度不正确");
	}
	if(_password.size() < 6 || _password.size() > 16) {
		return string("密码长度不正确");
	}
	name = _name;
	password = _password;
	return string();
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
    vector<TicketInfo> G = GetOrders();
    int pos;
    for (int i = 0; i < G.size(); i++) {
        if (G[i].date.GetDate() == info.date.GetDate() &&
            G[i].time.GetTime() == info.time.GetTime() &&
            G[i].trainNumber == info.trainNumber &&
            G[i].start == info.start &&
            G[i].end == info.end &&
            G[i].type == info.type &&
            G[i].price == info.price) {
            pos = i;
            break;
        }
    }
    if (G[pos].count < info.count) {
        return false;
    }
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
		return sjtu::make_pair((User*) nullptr, string("该用户不存在"));
	} else {
		if(map[userID].GetPassword() != SHA512::GetHash(password)) {
			return sjtu::make_pair((User*) nullptr, string("密码错误"));
		} else {
			return sjtu::make_pair(&map[userID], string());
		}
	}
}
pair<User*, string> AllUser::Register(const string &name, const string &userID, const string &password, const bool &isAdmin) {
	if(name.size() < 5 || name.size() > 16) {
		return sjtu::make_pair((User*) nullptr, string("用户名长度不正确"));
	}
	if(userID.size() != 9) {
		return sjtu::make_pair((User*) nullptr, string("ID格式不正确"));
	}
	if(userID == "000000000") {
		return sjtu::make_pair((User*) nullptr, string("该ID无效"));
	}
	if(password.size() < 6 || password.size() > 16) {
		return sjtu::make_pair((User*) nullptr, string("密码长度不正确"));
	}
	if(map.count(userID)) {
		return sjtu::make_pair((User*) nullptr, string("该ID已占用"));
	} else {
		return sjtu::make_pair(&(map[userID] = User(sys, name, userID, SHA512::GetHash(password), isAdmin)), string());
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
