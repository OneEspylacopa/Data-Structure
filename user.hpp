#ifndef USER_HPP
#define USER_HPP

#include <fstream>
#include <cstring>
#include "base.hpp"
#include "map.hpp"

using std::string;

class AllUser {
private:
	static void SystemHistory(const std::ofstream &fout) {
		// TODO
	}
	
private:
	class User {
	protected:
		string name; // username
		string userID; // user's ID 
		string password; // user's password 
		Log mylog; // user's log
		
	public:
		User() {}
		User(const string &name, const string &userID, const string &password) : name(name), userID(userID), password(password) { }
		~User() {}
		
		friend std::ifstream& operator>>(std::ifstream &fin, User &rhs) {
			fin >> rhs.name >> rhs.userID >> rhs.password >> rhs.mylog;
			return fin;
		}
		friend std::ofstream& operator<<(std::ofstream &fout, const User &rhs) const {
			fout << rhs.name << " " << rhs.userID << " " << rhs.password << std::endl;
			return fout;
		}
		
		void OutputLog(const std::ofstream &fout) const {
			fout << mylog << std::endl;
		}
		
		string GetPassword() const {
			return password;
		}
	};
	
	class GeneralUser : public User {
	public:
		GeneralUser() {}
		~GeneralUser() {}
		
		TrainNumber QueryTicket(const ststring &start, const string &end, const Date &date) const {
			return train.QueryTicket(start, end, date);
		}
		
		bool BookTicket(const string &trainNumber, const string &start, const string &end, const size_t count) {
			// return true if succeed, false if fail
			bool success = train.BookTicket(trainNumber, start, end, count);
			if(success) {
				mylog.AddBook(trainNumber, start, end, count);
			}
			return success;
		}
		
		bool ReturnTicket(const string &trainNumber, const string &start, const string &end, const size_t count) {
			// return true if succeed, false if fail
			bool success = train.ReturnTicket(trainNumber, start, end, count);
			if(success) {
				mylog.AddReturn(trainNumber, start, end, count);
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
		
		void SystemHistory(const ofstream &fout) const {
			AllUser::SystemHistory(fout);
		}
	};
	
	sjtu::map<string, User> map; // user's ID -> User 
	
public:
	AllUser() {}
	~AllUser() {}
	
	User& getUser(const string &userID) {
		return map[userID];
	}
	
	bool Login(const string &userID, const string &pwd) const {
		// return true if succeed, false if fail
		return map[userID].GetPassword() == pwd;
	}
	
	bool Register(const string &name, const string userID, const string password = "000000") {
		// return true if succeed, false if fail
		if(map.count(userID)) {
			return false;
		} else {
			map.insert(sjtu::make_pair(userID, User(name, userID, password)));
			return true;
		}
	}
};

#endif
