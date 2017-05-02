#ifndef LOG_HPP
#define LOG_HPP
#include "vector.hpp"
#include"binfstream.hpp"
#include<string>
#include"Date.hpp"
#include"Time.hpp"
class Log{
private:
	int n;
	sjtu::vector<std::string> name;
	sjtu::vector<std::string> userID;
	sjtu::vector<std::string> change;
	sjtu::vector<int> number;
	sjtu::vector<std::string> tickettype;
	sjtu::vector<std::string> trainID;
	sjtu::vector<std::string> start;
	sjtu::vector<std::string> end;
    sjtu::vector<Date> day;
    sjtu::vector<Time> onesecondmore;
public:
	Log() {
		n = 0;
	}
	void AddBook(const std::string a,const std::string b,const int c,const std::string d,const std::string e,const std::string f,const std::string g,const Date h,const Time i){
	    ++n;
	    name.push_back(a);
	    userID.push_back(b);
	    change.push_back("bought");
	    number.push_back(c);
	    tickettype.push_back(d);
	    trainID.push_back(e);
	    start.push_back(f);
	    end.push_back(g);
	    day.push_back(h);
	    onesecondmore.push_back(i);
	}
	void AddReturn(const std::string a,const std::string b,const int c,const std::string d,const std::string e,const std::string f,const std::string g,const Date h,const Time i){
		++n;
		name.push_back(a);
	    userID.push_back(b);
	    change.push_back("refunded");
	    number.push_back(c);
	    tickettype.push_back(d);
	    trainID.push_back(e);
	    start.push_back(f);
	    end.push_back(g);
	    day.push_back(h);
	    onesecondmore.push_back(i);
	}
	void Print(){
		binofstream f1("D:\\Log.txt");
		for (int i = 1;i <= n;i++){
		    f1<<name[i]<<' '<<userID[i]<<' '<<change[i]<<' '<<number[i]<<' '<<tickettype[i]<<" tickets of "
			    trainID[i]<<" from "<<start[i]<<" to "<<end[i]<<" in "<<day[i]<<" at "<<onsecondmore[i]<<'\n';
		    
		}
		f1.close();
	}
	~Log(){
	}
};
#endif
			    
	
    
	
