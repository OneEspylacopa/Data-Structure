#include "TrainSystem.h"
#include "fstream"
#include <iostream>
#include <bits/stdc++.h>

///////////////TrainNumber///////////////
TrainNumber::TrainNumber() { }
TrainNumber::~TrainNumber() { }
TrainNumber::TrainNumber(const string &number) : number(number) {
	selling = false;
	canceled = false;
}
string TrainNumber::GetNumber() const {
	return number;
}
vector<Station> TrainNumber::GetStations() const {
	return stations;
}
void TrainNumber::AddStation(const Station &station) {
	stations.push_back(station);
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
		return true;
	} else {
		return false;
	}
}
vector<TicketsInfo> TrainNumber::QueryTicket(const string &start, const string &end) const {
	vector<TicketsInfo> res;
	
	for(int i = 0; i < (int) stations.size(); i++) {
		if(stations[i].name == start) { // 模糊搜索 
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
		//train.push_back(trainNumber);
		//numberMap[number] = --train.end();
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
	std::ifstream fin(path.c_str());
	if(!fin.is_open()) {
		return;
	}
	
	Date date;
	
	string number, str;
	fin >> str;
	
	while(!fin.eof()) {
		string strType1, strType2, strType3;
		SeatType type1, type2, type3;
		
		number = str;
		TrainNumber trainNumber(number);
		
		fin >> str;
		std::cout << number << std::endl;
		
		int cnt = 0;
		for(int i = 0; i < (int) str.size(); i++) {
			if(str[i] == ',') {
				cnt++;
				continue;
			}
			if(cnt == 5) {
				strType1 += str[i];
			} else if(cnt == 6) {
				strType2 += str[i];
			} else if(cnt == 7) {
				strType3 += str[i];
			}
		}
		type1 = GetSeatType(strType1);
		type2 = GetSeatType(strType2);
		type3 = GetSeatType(strType3);
		
		string date;
		for(;;) {
			Station station;
			string arriveTime, stopTime;
			string price1, price2, price3;
			
			fin >> str;
			if(fin.eof()) break;
			
			if(str[0] >= 'A' && str[0] <= 'Z') {
				break;
			}
			
			//std::cout << str << std::endl;
			
			int cnt = 0;
			for(int i = 0; i < (int) str.size(); i++) {
				if(str[i] == ',') {
					cnt++;
					continue;
				}
				if(cnt == 0) {
					station.name += str[i];
				} else if(cnt == 1) {
					date += str[i];
				} else if(cnt == 2) {
					arriveTime += str[i];
				} else if(cnt == 3) {
					stopTime += str[i];
				} else if(cnt == 4) {
					if(str[i] >= '0' && str[i]<= '9') {
						station.mileage = station.mileage * 10 + str[i] - '0';
					}
				} else if(cnt == 5) {
					if(str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
						price1 += str[i];
					}
				} else if(cnt == 6) {
					if(str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
						price2 += str[i];
					}
				} else if(cnt == 7) {
					if(str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
						price3 += str[i];
					}
				}
			}
			if(arriveTime != "起点站") {
				station.arriveTime = Time(arriveTime.c_str());
			}
			if(stopTime != "终到站") {
				station.stopTime = Time(stopTime.c_str());
			}
			for(int i = 0; i < SEAT_TYPE_NUM; i++) {
				station.seatCount[i] = 2000;
			}
			station.price[(int) type1] = atof(price1.c_str());
			station.price[(int) type2] = atof(price2.c_str());
			station.price[(int) type3] = atof(price3.c_str());
		}
		
		AddPlan(date, trainNumber);
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
