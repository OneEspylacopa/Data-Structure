#include "TrainSystem.h"

using std::string;

TrainSystem::TrainSystem() : train(this), user(this) { }
TrainSystem::~TrainSystem() { }

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
