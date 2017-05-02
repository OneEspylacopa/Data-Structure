#ifndef TRAINSYSTEM_HPP
#define TRAINSYSTEM_HPP

#include <cstring>

#include "Train.hpp"
#include "User.hpp"

using std::string;

class TrainSystem {
private:
	string pathSystemHistory;
	string pathTrainData;
	string pathUserData;
	
public:
	Train train;
	AllUser user;
	
	TrainSystem() : train(this), user(this) { }
	~TrainSystem() { }
	
	void SetSystemHistory(const string &str) {
		pathSystemHistory = str;
	}
	
	void SetTrainData(const string &str) {
		pathTrainData = str;
	}
	
	void SetUserData(const string &str) {
		pathUserData = str;
	}
	
	string GetSystemHistory() const {
		return pathSystemhistory;
	}
	
	string GetTrainData() const {
		return pathTraindata;
	}
	
	string GetUserData() const {
		return pathUserData;
	}
};

#endif
