#ifndef BASE_HPP
#define BASE_HPP

#include "train.hpp"
#include "user.hpp"

class Base {
protected:
	Train train;
	AllUser user;
	ofstream systemHistory;
	ofstream trainData;
	ofstream userData;
	
public:
	Base() {}
	~Base() {}	
};

#endif
