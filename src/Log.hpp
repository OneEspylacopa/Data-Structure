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
		std::string s = "";
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
		std::string s = "";
		if (t == FirstClass) s += "一等座"; 
		if (t == SecondClass) s += "二等座";
		if (t == NoSeat) s += "无座";
		if (t == BusinessSeat) s += "商务座";
		if (t == HardSeat) s += "硬座";
		if (t == SoftSeat) s += "软座";
		if (t == HardSleeperUp) s += "硬卧上";
		if (t == HardSleeperMiddle) s += "硬卧中";
		if (t == HardSleeperDown) s += "硬卧下";
		if (t == SoftSleeperDown) s += "软卧下";
		if (t == AdvancedSoftSleeper) s += "高级软卧";
		if (t == SpecialSeat) s += "特等座";
		return s;
	}
	static int n;
public:
	static sjtu::vector<std::string>logs;
	Log() {
		n = 0;
	}
	void AddBook(const TicketInfo &info){
	    ++n;
	    std::string s;
	    s = "bought";
	    s += info.trainNumber + info.start + info.end + Date::GetDate(info.date) + Time::GetTime(info.time) +  GetCHN(info.type) + GetInt(info.price);
	    logs.push_back(s);
	}
	void AddReturn(const TicketInfo &info){
		++n;
	    std::string s;
	    s = "refunded";
	    s += info.trainNumber + info.start + info.end + Date::GetDate(info.date) + Time::GetTime(info.time) +  GetCHN(info.type) + GetInt(info.price);
	    logs.push_back(s);
	}
    friend binofstream& operator << (binofstream &fout, const Log &log)
    {
    	fout<<n<<'\n';
    	for (int i = 1;i <= n;++i) fout<<logs[i]<<'\n';
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
    		logs.push_back(s);
    	}
    	return fin;
    }
	~Log(){
	}
};
#endif
			    
	
    
	
