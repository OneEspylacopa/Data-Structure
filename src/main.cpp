#include <bits/stdc++.h>
#include "TrainSystem.h"

//#include <iostream>

//using namespace std;

TrainSystem sys;

/*sjtu::vector<string> func(const sjtu::vector<string> &y) {
	return y;
}*/

int main() {
	sys.SetTrainData("TrainData.dat");
	sys.SetUserData("TrainData.dat");
	
	sys.user.Register("¿Óπ∑µ∞", "001", "123456", true);
	sys.Export();
	
	User* user = sys.user.GetUser("001");
	if(user == nullptr) {
		return 0;
	}
	std::cout << user->GetName() << std::endl;
	std::cout << "ok" << std::endl;
	std::cout << user->GetUserType() << std::endl;
	
	return 0;
}
