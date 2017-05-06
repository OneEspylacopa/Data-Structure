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
};

#endif
