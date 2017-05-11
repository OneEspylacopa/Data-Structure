#include "TrainSystem.h"
#include "fstream"

///////////////TrainNumber///////////////
TrainNumber::TrainNumber() { }
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
vector<TicketsInfo> TrainNumber::QueryTicket(const string &start, const string &end) const {
	vector<TicketsInfo> res;
	
	for(int i = 0; i < (int) stations.size(); i++) {
		if(stations[i].name == start) { // Ä£ºýËÑË÷ 
			for(int j = i + 1; j < (int) stations.size(); j++) {
				if(stations[j].name == end) {
					TicketsInfo info;
					info.trainNumber = number;
					info.start = start;
					info.end = end;
					info.time = stations[i].arriveTime;
					for(int l = 0; l < 12; l++) {
						info.count[l] = stations[i].seatCount[l];
						info.price[l] = 0;
					}
					for(int k = i; k < j; k++) {
						for(int l = 0; l < 12; l++) {
							const int &tmp = stations[k].seatCount[l];
							if(tmp < info.count[l]) {
								info.count[l] = tmp;
							}
							info.price[l] += stations[i].price[l];
						}
					}
				}
			}
		}
	}
	
	return res;
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
binifstream& TrainNumber::operator>>(binifstream &fin) {
	vector<Station> &vec = stations;
	
	fin >> number;
	fin >> selling;
	fin >> canceled;
	
	size_t size;
	fin >> size;
	
	vec.clear();
	vec.resize(size);
	
	for(size_t i = 0; i < size; i++) {
		fin >> vec[i];
	}
	
	return fin;
}
binofstream& TrainNumber::operator<<(binofstream &fout) {
	const vector<Station> &vec = stations;
	
	fout << number;
	fout << selling;
	fout << canceled;
	
	size_t size = vec.size();
	fout << size;
	for(size_t i = 0; i < size; i++) {
		fout << vec[i];
	}
	
	return fout;
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
vector<TicketsInfo> TrainDay::QueryTicket(const string &start, const string &end) const {
	vector<TicketsInfo> res;
	for(int i = 0; i < (int) train.size(); i++) {
		vector<TicketsInfo> ret;
		while(!ret.empty()) {
			res.push_back(ret.back());
			ret.pop_back();
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
vector<TicketsInfo> Train::QueryTicket(const Date &date, const string &start, const string &end) const {
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
void Train::Import(const string &path) {
	ifstream fin(path.c_str());
	if(!fin.is_open()) {
		return;
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
