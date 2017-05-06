#include "TrainSystem.h"

///////////////TrainNumber///////////////
string TrainNumber::GetNumber() const {
	return number;
}	
bool TrainNumber::BookTicket(const TicketInfo &info) {
	vector<Station>::iterator it_start = stations.end(), it_end = stations.end();
	
	for(vector<Station>::iterator it = stations.begin(); it != stations.end(); it++) {
		if(it->name == info.start) {
			it_start = it;
		} else if(it->name == info.end) {
			it_end = it;
		}
	}
	
	bool flag = true;
	
	if(it_start != stations.end() && it_end != stations.end()) {
		for(vector<Station>::iterator it = it_start; it != it_end; it++) {
			if(it->seatCount[(int) info.type] < info.count) {
				flag = false;
				break;
			}
		}
		
		if(flag == false) {
			return false;
		}
		
		for(vector<Station>::iterator it = it_start; it != it_end; it++) {
			it->seatCount[(int) info.type] -= info.count;
		}
		
		return true;
	} else {
		return false;
	}
}
bool TrainNumber::ReturnTicket(const TicketInfo &info) {
	vector<Station>::iterator it_start = stations.end(), it_end = stations.end();
	
	for(vector<Station>::iterator it = stations.begin(); it != stations.end(); it++) {
		if(it->name == info.start) {
			it_start = it;
		} else if(it->name == info.end) {
			it_end = it;
		}
	}
	
	if(it_start != stations.end() && it_end != stations.end()) {
		for(vector<Station>::iterator it = it_start; it != it_end; it++) {
			it->seatCount[(int) info.type] += info.count;
		}
	} else {
		return false;
	}
}

///////////////TrainDay///////////////
bool TrainDay::BookTicket(const TicketInfo &info) {
	for(vector<TrainNumber>::iterator it = train.begin(); it != train.end(); it++) {
		if(it->GetNumber() == info.trainNumber) {
			it->BookTicket(info);
			return true;
		}
	}
	return false;
}
bool TrainDay::ReturnTicket(const TicketInfo &info) {
	for(vector<TrainNumber>::iterator it = train.begin(); it != train.end(); it++) {
		if(it->GetNumber() == info.trainNumber) {
			it->ReturnTicket(info);
			return true;
		}
	}
	return false;
}

///////////////Train///////////////
Train::Train(TrainSystem *sys) : sys(sys) { }
Train::~Train() { }

bool Train::BookTicket(const TicketInfo info) {
	return trains[info.date].BookTicket(info);
}
/*bool Train::ReturnTicket(const TicketInfo &info) {
	if(!trains.count(info.date)) {
		return false;
	} else {
		return trains[info.date].ReturnTicket(info);
	}
}*/

bool Train::ReturnTicket(const TicketInfo &info) {
	if(!trains.count(info.date)) {
		return false;
	} else {
		return trains[info.date].ReturnTicket(info);
	}
}


TicketInfo Train::QueryTicket(const string &start, const string &end, const Date &date) const {
	// TODO
}

