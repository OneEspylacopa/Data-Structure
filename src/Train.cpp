#include "TrainSystem.h"

///////////////TrainNumber///////////////
TrainNumber::TrainNumber(const string &number) : number(number) {
	selling = false;
	canceled = false;
}
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
bool TrainNumber::StartSelling() {
	if(selling == true) {
		return false;
	} else {
		selling = true;
		return true;
	}
}
bool TrainNumber::StopSelling() {
	if(selling == true) {
		return false;
	} else {
		selling = true;
		return true;
	}
}
void TrainNumber::Cancel() {
	canceled = true;
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
vector<TrainNumber>::iterator TrainDay::GetNumber(const string &number) const {
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

bool TrainDay::StartSelling(const string &number) {
	if(!numberMap.count(number)) {
		return false;
	} else {
		return numberMap[number]->StartSelling();
	}
}
bool TrainDay::StopSelling(const string &number) {
	if(!numberMap.count(number)) {
		return false;
	} else {
		return numberMap[number]->StopSelling();
	}
}
bool TrainDay::AddPlan(const TrainNumber &trainNumber) {
	const string number = trainNumber.GetNumber();
	if(numberMap.count(number)) {
		return false;
	} else {
		train.push_back(trainNumber);
		numberMap[number] = --train.end();
		return true;
	}
}
bool TrainDay::ModifyPlan(const TrainNumber &trainNumber) {
	const string number = trainNumber.GetNumber();
	if(!numberMap.count(number)) {
		return false;
	} else {
		(*numberMap[number]) = trainNumber;
		return true;
	}
}
bool TrainDay::CancelPlan(const string &number) {
	if(!numberMap.count(number)) {
		return false;
	} else {
		numberMap[number]->Cancel();
		numberMap.erase(numberMap.find(number));
		return true;
	}
}
binifstream& TrainDay::operator>>(binifstream &fin) {
	vector<TrainNumber> &vec = train;
	
	size_t size;
	fin >> size;
	
	train.clear();
	train.resize(size);
	for(size_t i = 0; i < size; i++) {
		fin >> vec[i];
	}
	
	numberMap.clear();
	for(vector<TrainNumber>::iterator it = vec.begin(); it != vec.end(); it++) {
		numberMap[it->GetNumber()] = it;
	}
	return fin;
}
binofstream& TrainDay::operator<<(binofstream &fout) {
	const vector<TrainNumber> &vec = train;
	
	size_t size = vec.size();
	fout << size;
	
	for(size_t i = 0; i < size; i++) {
		fout << vec[i];
	}
	return fout;
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

bool Train::StartSelling(const Date &date, const string &number) {
	if(!trains.count(date)) {
		return false;
	} else {
		return trains[date].StartSelling(number);
	}
}
bool Train::StopSelling(const Date &date, const string &number) {
	if(!trains.count(date)) {
		return false;
	} else {
		return trains[date].StopSelling(number);
	}
}
bool Train::AddPlan(const Date &date, const TrainNumber &trainNumber) {
	return trains[date].AddPlan(trainNumber);
}
bool Train::ModifyPlan(const Date &date, const TrainNumber &trainNumber) {
	if(!trains.count(date)) {
		return false;
	} else {
		return trains[date].ModifyPlan(trainNumber);
	}
}
bool Train::CancelPlan(const Date &date, const string &number) {
	if(!trains.count(date)) {
		return false;
	} else {
		return trains[date].CancelPlan(number);
	}
}
binifstream& Train::operator>>(binifstream &fin) {
	fin >> trains;
	return fin;
}
binofstream& Train::operator<<(binofstream &fout) {
	fout << trains;
	return fout;
}
