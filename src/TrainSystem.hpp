#ifndef BASE_HPP
#define BASE_HPP

#include <binfstream>
#include "train.hpp"
#include "user.hpp"

class TrainSystem {
private:
	Train train;
	Alluser user;
	
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
	
	void setInSystemHistory() {
		
	}
};

#endif
