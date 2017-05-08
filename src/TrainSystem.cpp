#include "TrainSystem.h"

using std::string;

TrainSystem::TrainSystem() : train(this), user(this) {
	binifstream ifTrainData;
	ifTrainData.open(pathTrainData.c_str());
	if(ifTrainData.is_open()) {
		ifTrainData >> train;
	}
	ifTrainData.close();
	
	binifstream ifUserData;
	ifUserData.open(pathUserData.c_str());
	if(ifUserData.is_open()) {
		ifUserData >> user;
	}
	ifUserData.close();
}
TrainSystem::~TrainSystem() {
	binofstream ofTrainData;
	ofTrainData.open(pathTrainData.c_str());
	ofTrainData << train;
	ofTrainData.close();
	
	binofstream ofUserData;
	ofUserData.open(pathUserData.c_str());
	ofUserData << user;
	ofUserData.close();
}

void TrainSystem::SetSystemHistory(const string &str) {
	pathSystemHistory = str;
}
void TrainSystem::SetTrainData(const string &str) {
	pathTrainData = str;
}
void TrainSystem::SetUserData(const string &str) {
	pathUserData = str;
}
string TrainSystem::GetSystemHistory() const {
	return pathSystemHistory;
}
string TrainSystem::GetTrainData() const {
	return pathTrainData;
}
string TrainSystem::GetUserData() const {
	return pathUserData;
}
