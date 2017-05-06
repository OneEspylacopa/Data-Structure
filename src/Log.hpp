#ifndef LOG_HPP
#define LOG_HPP
#include"vector.hpp"
#include"binfstream.hpp"
#include<string>
#include"Date.hpp"
#include"Time.hpp"
#include"Ticket.hpp"
class Log{
private:
	std::string GetInt(double x)
	{
		std::string s = '';
		int y = int (x);
		while (y != 0)
		{
			s += (y % 10) + '0';
			y /= 10;
		}
		x = x - y;
		s += '.'; 
		s += int (10 * x) + '0';
		return s;
    }
	std::string GetCHN(SeatType t)
	{
		std::string s = '';
		if (t == Firstclass) s += "һ����"; 
		if (t == SecondClass) s += "������";
		if (t == Noseat) s += "����";
		if (t == BusinessSeat) s += "������";
		if (t == HardSeat) s += "Ӳ��";
		if (t == SoftSeat) s += "����";
		if (t == HardSleeperUp) s += "Ӳ����";
		if (t == HardSleeperMiddle) s += "Ӳ����";
		if (t == HardSleeperDown) s += "Ӳ����";
		if (t == SoftSleeperDown) s += "������";
		if (t == AdvancedSoftSleeper) s += "�߼�����";
		if (t == SpecialSeat) s += "�ص���";
		return s;
	}
public:
	sjtu::vector<std::string>logs;
	
	Log() {
		n = 0;
	}
	void AddBook(const TicketInfo &info){
	    ++n;
	    std::string s;
	    s = "bought";
	    s += info.trainNumber + info.start + info.end +info.date.GetDate() + info.time.GetTime() +  GetCHN(info.type) + GetInt(info.price);
	    logs.push_back(s);
	}
	void AddReturn(const TicketInfo &info){
		++n;
	    std::string s;
	    s = "refunded";
	    s += info.trainNumber + info.start + info.end +info.date.GetDate() + info.time.GetTime()+  GetCHN(info.type) + GetInt(info.price);
	    logs.push_back(s);
	}
    friend binofstream& operator << (binofstream &fout, const Log &log)
    {
    	fout<<n<<'\n';
    	for (int i = 1;i <= n;++i) fout<<log[i]<<'\n';
    	return fout;
    }
    friend binofstream& operator >> (binofstream &fin, Log &log)
    {
    	int n0;
    	fin>>n0;
    	for (int i = 1;i <= n0;++i)
    	{
    		std::string s;
    		fin>>s;
    		log.push_back(s);
    	}
    	return fin;
    }
	~Log(){
	}
};
#endif
			    
	
    
	
