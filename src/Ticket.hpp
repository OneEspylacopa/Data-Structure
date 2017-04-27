#ifndef TICKET_HPP
#define TICKET_HPP

#include <cstring>

const int SEAT_TYPE_NUM = 12;

enum SeatType {
	FirstClass, // 一等座 
	SecondClass, // 二等座
	NoSeat, // 无座 
	BusinessSeat, // 商务座 
	HardSeat, // 硬座
	SoftSeat, // 软座
	HardSleeperUp, // 硬卧上
	HardSleeperMiddle, // 硬卧中 
	HardSleeperDown, // 硬卧下
	SoftSleeperDown, // 软卧下
	AdvancedSoftSleeper, // 高级软卧
	SpecialSeat //特等座 
};

class TickInfo {
public:
	string start;
	string end;
	Date date;
	int price;
	SeatType type;
	
	TicketInfo(const string &start, const string &end, const Date &date, const int &price, const SeatType type) :
		start(start),
		end(end),
		date(date),
		price(price),
		type(type)
	{ }
};

#endif
