#include "TrainSystem.h"
#include "fstream"

///////////////TrainNumber///////////////
TrainNumber::TrainNumber() {
	selling = false;
	canceled = false;
}
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
		if(stations[i].name.find(start) != string::npos) {
			for(int j = i + 1; j < (int) stations.size(); j++) {
				if(stations[j].name.find(end) != string::npos) {
					TicketsInfo info;
					info.trainNumber = number;
					info.start = stations[i].name;
					info.end = stations[j].name;
					info.time = stations[i].stopTime;
					
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
					res.push_back(info);
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
		vector<TicketsInfo> ret = train[i].QueryTicket(start, end);
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
	if(!trains.count(date)) {
		return vector<TicketsInfo>();
    } else {
		vector<TicketsInfo> ret = trains[date].QueryTicket(start, end);
		for(int i = 0; i < (int) ret.size(); i++) {
			ret[i].date = date;
		}
		return ret;
	}
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
TrainNumber Train::GetTrainNumber(const Date &date, const string &number) {
	
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
			
			int cnt = 0;
			for(int i = 0; i < (int) str.size(); i++) {
				if(str[i] == ',') {
					cnt++;
					continue;
				}
				if(cnt == 0) {
					station.name += str[i];
				} else if(cnt == 1) {
					if(date.size() < 10) {
						date += str[i];
					}
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
                station.seatCount[i] = 0;
			}
            station.seatCount[(int) type1] = 2000;
            station.seatCount[(int) type2] = 2000;
            station.seatCount[(int) type3] = 2000;
			station.price[(int) type1] = atof(price1.c_str());
			station.price[(int) type2] = atof(price2.c_str());
			station.price[(int) type3] = atof(price3.c_str());

			trainNumber.AddStation(station);
		}
		
		AddPlan(Date(date), trainNumber);
	}
}
