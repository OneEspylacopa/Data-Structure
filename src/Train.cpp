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
	if(!numberMap.count(info.trainNumber)) {
		return false;
	} else {
		numberMap[info.trainNumber]->BookTicket(info);
		return true;
	}
}
bool TrainDay::ReturnTicket(const TicketInfo &info) {
	if(!numberMap.count(info.trainNumber)) {
		return false;
	} else {
		numberMap[info.trainNumber]->ReturnTicket(info);
		return true;
	}
}
TrainNumber* TrainDay::GetNumber(const string &number) const {
	if(!numberMap.count(number)) {
		return nullptr;
	} else {
		return numberMap[number];
	}
}
vector<TicketInfo> TrainDay::QueryTicket(const string &start, const string &end) const {
	vector<TicketInfo> res;
	for(int i = 0; i < (int) train.size(); i++) {
		const vector<Station> &stations = train[i].stations;
		
		const Station *s = nullptr, *e = nullptr;
		for(int j = 0; j < (int) stations.size(); j++) {
			if(s == nullptr) {
				if(stations[j].name == start) {
					s = &stations[j];
				}
			} else {
				if(stations[j].name == end) {
					e = &stations[j];
				}
			}
		}
		
		if(s != nullptr && e != nullptr) {
			TicketInfo tmp;
			tmp.trainNumber = train[i].GetNumber();
			tmp.start = start;
			tmp.end = end;
			// tmp.date = 
			tmp.time = s->arriveTime;
			// tmp.type;
			// tmp.price;
			tmp.count = 1;
			res.push_back(tmp);
		}
	}
	return res;
}
///////////////Train///////////////
Train::Train(TrainSystem *sys) : sys(sys) { }
Train::~Train() { }

bool Train::BookTicket(const TicketInfo info) {
	return trains[info.date].BookTicket(info);
}

bool Train::ReturnTicket(const TicketInfo &info) {
	if(!trains.count(info.date)) {
		return false;
	} else {
		return trains[info.date].ReturnTicket(info);
	}
}


vector<TicketInfo> Train::QueryTicket(const string &start, const string &end, const Date &date) const {
	return trains[date].QueryTicket(start, end);
}

