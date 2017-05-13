#ifndef TICKET_HPP
#define TICKET_HPP

#include <string>

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

static string GetSeatType(SeatType type) {
	std::string result;
	if (type == FirstClass) result += "һ����";
	if (type == SecondClass) result += "������";
	if (type == NoSeat) result += "����";
	if (type == BusinessSeat) result += "������";
	if (type == HardSeat) result += "Ӳ��";
	if (type == SoftSeat) result += "����";
	if (type == HardSleeperUp) result += "Ӳ����";
	if (type == HardSleeperMiddle) result += "Ӳ����";
	if (type == HardSleeperDown) result += "Ӳ����";
	if (type == SoftSleeperDown) result += "������";
	if (type == AdvancedSoftSleeper) result += "�߼�����";
	if (type == SpecialSeat) result += "�ص���";
	return result;
}

static SeatType GetSeatType(const string &type) {
	if (type == "һ����") return FirstClass;
	if (type == "������") return SecondClass;
	if (type == "����") return NoSeat;
	if (type == "������") return BusinessSeat;
	if (type == "Ӳ��") return HardSeat;
	if (type == "����") return SoftSeat;
	if (type == "Ӳ����") return HardSleeperUp;
	if (type == "Ӳ����") return HardSleeperMiddle;
	if (type == "Ӳ����") return HardSleeperDown;
	if (type == "������") return SoftSleeperDown;
	if (type == "�߼�����") return AdvancedSoftSleeper;
	if (type == "�ص���") return SpecialSeat;
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
