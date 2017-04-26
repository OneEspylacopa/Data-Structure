#ifndef BASE_HPP
#define BASE_HPP

#include <binfstream>
#include "train.hpp"
#include "user.hpp"

class TrainSystem {
private:
	binifstream iSystemHistory;
	binifstream iTrainData;
	binifstream iUserData;
	
	binofstream oSystemHistory;
	binofstream oTrainData;
	binofstream oUserData;
	
public:
	Train train;
	AllUser user;
	
	
	Base() : train(this), user(this) {}
	~Base() {}
	
	void SetISystemHistory(const string &str) {
		
	}
	
	void SetITrainData(const string &str) {
		
	}
	
	void SetIUserData(const string &str) {
		
	}
	
	void SetOSystemHistory(const string &str) {
		
	}
	
	void SetOTrainData(const string &str) {
		
	}
	
	void SetOUserData(const string &str) {
		
	}
};

#endif
