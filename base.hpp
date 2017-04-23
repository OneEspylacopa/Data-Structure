#ifndef BASE_HPP
#define BASE_HPP

#include <fstream>
#include "train.hpp"
#include "user.hpp"

class Base {
public:
	Train train;
	AllUser user;
	std::ofstream systemHistory;
	std::ofstream trainData;
	std::ofstream userData;
	
	Base() {}
	~Base() {}	
};

#endif
