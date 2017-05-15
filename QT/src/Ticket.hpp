#ifndef TICKET_HPP
#define TICKET_HPP

#include <string>

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

static string GetSeatType(SeatType type) {
	std::string result;
	if (type == FirstClass) result += "一等座";
	if (type == SecondClass) result += "二等座";
	if (type == NoSeat) result += "无座";
	if (type == BusinessSeat) result += "商务座";
	if (type == HardSeat) result += "硬座";
	if (type == SoftSeat) result += "软座";
	if (type == HardSleeperUp) result += "硬卧上";
	if (type == HardSleeperMiddle) result += "硬卧中";
	if (type == HardSleeperDown) result += "硬卧下";
	if (type == SoftSleeperDown) result += "软卧下";
	if (type == AdvancedSoftSleeper) result += "高级软卧";
	if (type == SpecialSeat) result += "特等座";
	return result;
}

static SeatType GetSeatType(const string &type) {
	if (type == "一等座") return FirstClass;
	if (type == "二等座") return SecondClass;
	if (type == "无座") return NoSeat;
	if (type == "商务座") return BusinessSeat;
	if (type == "硬座") return HardSeat;
	if (type == "软座") return SoftSeat;
	if (type == "硬卧上") return HardSleeperUp;
	if (type == "硬卧中") return HardSleeperMiddle;
	if (type == "硬卧下") return HardSleeperDown;
	if (type == "软卧下") return SoftSleeperDown;
	if (type == "高级软卧") return AdvancedSoftSleeper;
	if (type == "特等座") return SpecialSeat;
	//throw(false);
	return FirstClass;
}

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
	
	friend binifstream& operator>>(binifstream &fin, TicketInfo &info) {
		fin >> info.trainNumber;
		fin >> info.start;
		fin >> info.end;
		fin >> info.date;
		fin >> info.time;
		fin >> info.type;
		fin >> info.price;
		fin >> info.count;
		return fin;
	}
	friend binofstream& operator<<(binofstream &fout, const TicketInfo &info) {
		fout << info.trainNumber;
		fout << info.start;
		fout << info.end;
		fout << info.date;
		fout << info.time;
		fout << info.type;
		fout << info.price;
		fout << info.count;
		return fout;
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
	
	friend binifstream& operator>>(binifstream &fin, TicketsInfo &info) {
		fin >> info.trainNumber;
		fin >> info.start;
		fin >> info.end;
		fin >> info.date;
		fin >> info.time;
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			fin >> info.price[i];
			fin >> info.count[i];
		}
		return fin;
	}
	friend binofstream& operator<<(binofstream &fout, const TicketsInfo &info) {
		fout << info.trainNumber;
		fout << info.start;
		fout << info.end;
		fout << info.date;
		fout << info.time;
		for(int i = 0; i < SEAT_TYPE_NUM; i++) {
			fout << info.price[i];
			fout << info.count[i];
		}
		return fout;
	}
};

#endif
