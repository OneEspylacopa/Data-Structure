#ifndef USER_HPP
#define USER_HPP

#include <cstring>
#include "base.hpp"
#include "map.hpp"
#include "binfstream.hpp"

using std::string;

class AllUser {
private:
	TrainSystem *sys;
	static string SystemHistory() {
		// TODO
	}
	
private:
	class User {
	protected:
		string name; // username
		string userID; // user's ID 
		string password; // user's password 
		Log log; // user's log
		
	public:
		User() {}
		User(const string &name, const string &userID, const string &password) : name(name), userID(userID), password(password) { }
		~User() {}
		
		friend binifstream& operator>>(binifstream &fin, User &rhs) {
			fin >> rhs.name >> rhs.userID >> rhs.password >> rhs.mylog;
			return fin;
		}
		friend binofstream& operator<<(binofstream &fout, const User &rhs) {
			fout << rhs.name << rhs.userID << rhs.password << rhs.mylog;
			return fout;
		}
		
		void ModifyInfo(const string &_name, const string &_password) {
			name = _name;
			password = _password;
		}
		
		string GetName() const {
			return name;
		}
		
		string GetID() const {
			return userID;
		}
		
		string GetPassword() const {
			return password;
		}
		
		Log GetLog() const {
			return log;
		}
	};
	
	class GeneralUser : public User {
	public:
		GeneralUser() {}
		~GeneralUser() {}
		
		TicketInfo QueryTicket(const string &start, const string &end, const Date &date) const {
			return sys->train.QueryTicket(start, end, date);
		}
		
		bool BookTicket(const TicketInfo &info) {
			// return true if succeed, false if fail
			bool success = sys->train.BookTicket(TicketInfo &info);
			if(success) {
				log.AddBook();
			}
			return success;
		}
		
		bool ReturnTicket(const string &trainNumber, const string &start, const string &end, const SeatType &type, const size_t count) {
			// return true if succeed, false if fail
			bool success = sys->train.ReturnTicket(trainNumber, start, end, type, count);
			if(success) {
				log.AddReturn(trainNumber, start, end, type, count);
			}
			return success;
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
			return GetUser(userID).mylog;
		}
		
		string SystemHistory() const {
			return AllUser::SystemHistory();
		}
	};
	
	sjtu::map<string, User> map; // user's ID -> User 
	
public:
	AllUser(TrainSystem* sys) : sys(sys) {}
	~AllUser() {}
	
	User* GetUser(const string &userID) {
		if(!map.count(userID)) {
			return nullptr;
		} else {
			return &map[userID];
		}
	}
	
	User* Register(const string &name, const string &userID, const string &password) {
		if(map.count(userID)) {
			return nullptr;
		} else {
			return &(map[userID] = User(name, userID, password));
		}
	}
};

#endif
