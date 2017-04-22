#ifndef USER_HPP
#define USER_HPP

#include "base.hpp"

class AllUser : public Base {
private:
	map<string, User> map; // user's ID -> User 
	
protected:
	void SystemHistory(const ostream &fout) {
		// TODO
	}
	
public:
	AllUser() {}
	~Alluser() {}
	
	User& getUser(const string &userID) {
		return map[userID];
	}
	
	bool Login(const string &userID, const string &pwd) const {
		// return true if succeed, false if fail
		return map[userID].password == pwd;
	}
	
	bool Regester(const string &name, const string userID, const string password) {
		// return true if succeed, false if fail
		if(map.count(userID)) {
			return false;
		} else {
			map[userID] = User(name, userID, password);
			return true;
		}
	}
};

class User : public Alluser {
protected:
	string name; // username
	const string userID; // user's ID 
	string password; // user's password 
	Log mylog; // user's log
	
public:
	User() {
		password = "000000"; // default password
	}
	User(const string &name, const string &userID, const string &password) : name(name), userID(userID), password(password) { }
	~User() {}
	
	ifstream& operator>>(const ifstream &fin) {
		fin >> name >> userID >> password >> mylog;
		return fin;
	}
	ofstream& operator<<(const ofstream &fout) const {
		fout << name << " " << userID << " " << password << endl;
		return fout;
	}
	
	void OutputLog(const ofstream &fout) const {
		fout << mylog << endl;
	}
};

class GeneralUser : public User {
public:
	GeneralUser() {}
	~GeneralUser() {}
	
	TrainNumber QueryTicket(const string &start, const string &end, const Date &date) const {
		return train.QueryTicket(start, end, date);
	}
	
	bool BookTicket(const string &trainNumber, const string &start, const string &end, const size_t count) {
		// return true if succeed, false if fail
		bool success = train.BookTicket(trainNumber, start, end, count);
		if(success) {
			mylog.AddBook(const string &trainNumber, const string &start, const string &end, const size_t count);
		}
		return success;
	}
	
	bool ReturnTicket(const string &trainNumber, const string &start, const string &end, const size_t count) {
		// return true if succeed, false if fail
		bool success train.ReturnTicket(trainNumber, start, end, count);
		if(success) {
			mylog.AddReturn(const string &trainNumber, const string &start, const string &end, const size_t count);
		}
		return success;
	}
	
	void ModifyInformation(const string &nm, const string &pwd) {
		name = nm;
		password = pwd;
	}
};

class Administrator : public User {
public:
	Administrator() {}
	~Administrator() {}
	
	void AddPlan() {
		
	}
	
	bool ModifyPlan() {
		
	}
	
	bool CancelPlan() {
		
	}
	
	bool BeginToSell() {
		
	}
	
	bool StopToSell() {
		
	}
	
	const Log QueryUser(const string &userID) const {
		return getUser(userID).mylog;
	}
	
	void SystemHistory() const {
		AllUser::SystemHistory();
	}
};

#endif
