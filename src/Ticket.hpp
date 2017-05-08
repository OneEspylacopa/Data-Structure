#ifndef TICKET_HPP
#define TICKET_HPP

#include <cstring>

const int SEAT_TYPE_NUM = 12;

enum SeatType {
	FirstClass = 0, // һ���� 
	SecondClass = 1, // ������
	NoSeat = 2, // ���� 
	BusinessSeat = 3, // ������ 
	HardSeat = 4, // Ӳ��
	SoftSeat = 5, // ����
	HardSleeperUp = 6, // Ӳ����
	HardSleeperMiddle = 7, // Ӳ���� 
	HardSleeperDown = 8, // Ӳ����
	SoftSleeperDown = 9, // ������
	AdvancedSoftSleeper = 10, // �߼�����
	SpecialSeat = 11 //�ص��� 
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
};

#endif
