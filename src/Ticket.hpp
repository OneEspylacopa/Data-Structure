#ifndef TICKET_HPP
#define TICKET_HPP

#include <cstring>

const int SEAT_TYPE_NUM = 12;

enum SeatType {
	FirstClass, // һ���� 
	SecondClass, // ������
	NoSeat, // ���� 
	BusinessSeat, // ������ 
	HardSeat, // Ӳ��
	SoftSeat, // ����
	HardSleeperUp, // Ӳ����
	HardSleeperMiddle, // Ӳ���� 
	HardSleeperDown, // Ӳ����
	SoftSleeperDown, // ������
	AdvancedSoftSleeper, // �߼�����
	SpecialSeat //�ص��� 
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
