#ifndef TRAINSYSTEM_H
#define TRAINSYSTEM_H

#include <string>
using std::string;

class TrainSystem;

#include "Train.h"
#include "User.h"

class TrainSystem {
private:
	string pathSystemHistory;
	string pathTrainData;
	string pathUserData;
	
public:
	Train train;
	AllUser user;
	
	TrainSystem();
	~TrainSystem();
	
	void SetSystemHistory(const string &str);
	void SetTrainData(const string &str);
	void SetUserData(const string &str);
	string GetSystemHistory() const;
	string GetTrainData() const;
	string GetUserData() const;
};

#endif
