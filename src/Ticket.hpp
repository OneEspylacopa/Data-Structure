#ifndef TICKET_HPP
#define TICKET_HPP

#include <cstring>

const int SEAT_TYPE_NUM = 12;

enum SeatType {
	FirstClass = 0, // 一等座 
	SecondClass = 1, // 二等座
	NoSeat = 2, // 无座 
	BusinessSeat = 3, // 商务座 
	HardSeat = 4, // 硬座
	SoftSeat = 5, // 软座
	HardSleeperUp = 6, // 硬卧上
	HardSleeperMiddle = 7, // 硬卧中 
	HardSleeperDown = 8, // 硬卧下
	SoftSleeperDown = 9, // 软卧下
	AdvancedSoftSleeper = 10, // 高级软卧
	SpecialSeat = 11 //特等座 
};

class TicketInfo {
public:
	string trainNumber;
	string start;
	string end;
	Date date;
	Time time;
	SeatType type;
	int price;
	int count;
	
	TicketInfo() { }
	TicketInfo(const string &trainNumber, const string &start, const string &end, const Date &date, const Time &time, const SeatType type, const int &price, const int count) :
		trainNumber(trainNumber),
		start(start),
		end(end),
		date(date),
		time(time),
		type(type),
		price(price),
		count(count)
	{ }
	
	binifstream& operator>>(binifstream &fin) {
		fin >> trainNumber;
		fin >> start;
		fin >> end;
		fin >> date;
		fin >> time;
		fin >> type;
		fin >> price;
		fin >> count;
	}
	binofstream& operator<<(binofstream &fout) {
		fout << trainNumber;
		fout << start;
		fout << end;
		fout << date;
		fout << time;
		fout << type;
		fout << price;
		fout << count;
	}
	
	bool operator<(const TicketInfo &b) const {
		if(trainNumber != b.trainNumber) {
			return trainNumber < b.trainNumber;
		} else if(start != b.start) {
			return start < b.start;
		} else if(end != b.end) {
			return end < b.end;
		} else if(date != b.date) {
			return date < b.date;
		} else if(time != b.time) {
			return time < b.time;
		} else if(type != b.type) {
			return type < b.type;
		} else {
			return price < b.price;
		}
	}
};

class TicketsInfo {
public:
	string trainNumber;
	string start;
	string end;
	Date date;
	Time time;
	int price[SEAT_TYPE_NUM];
	int count[SEAT_TYPE_NUM];
	
	TicketsInfo() { }
	TicketsInfo(const string &trainNumber, const string &start, const string &end, const Date &date, const Time &time, const int _price[SEAT_TYPE_NUM], const int _count[SEAT_TYPE_NUM]) :
		trainNumber(trainNumber),
		start(start),
		end(end),
		date(date),
		time(time) {
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			price[i] = _price[i];
			count[i] = _count[i];
		}
	}
	
	binifstream& operator>>(binifstream &fin) {
		fin >> trainNumber;
		fin >> start;
		fin >> end;
		fin >> date;
		fin >> time;
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			fin >> price[i];
			fin >> count[i];
		}
	}
	binofstream& operator<<(binofstream &fout) {
		fout << trainNumber;
		fout << start;
		fout << end;
		fout << date;
		fout << time;
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			fout << price[i];
			fout << count[i];
		}
	}
};

#endif
