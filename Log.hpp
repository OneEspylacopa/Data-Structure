#include"binfstream.hpp"
#include<string>
#include"Date.hpp"
#include"Time.hpp"
using namespace std;
class Log{
private:
	string *name;
	string *userID;
	string *change;
	int *number;
	string *tickettype;
	string *trainID;
	string *start;
	string *end;
    Date *day;
    Time *onesecondmore;
    int n;
    int n0;
    void doublespace(){ 
        n0 *= 2;
        
    	string *tmp1 = name;
    	name = new string[n0];
    	for (int i = 1;i <= n;i++) name[i] = tmp1[i];
    	delete []tmp1;
    	
    	string *tmp2 = userID;
    	userID = new string[n0];
    	for (int i = 1;i <= n;i++) userID[i] = tmp2[i];
    	delete []tmp2;
    	
    	string *tmp3 = change;
    	change = new string[n0];
    	for (int i = 1;i <= n;i++) change[i] = tmp3[i];
    	delete []tmp3;
    	
    	int *tmp4 = number;
    	number = new string[n0];
    	for (int i = 1;i <= n;i++) number[i] = tmp4[i];
    	delete []tmp4;
    	
    	string *tmp5 = tickettype;
    	tickettype = new string[n0];
    	for (int i = 1;i <= n;i++) tickettype[i] = tmp5[i];
    	delete []tmp5;
    	
    	string *tmp6 = trainID;
    	trainID = new string[n0];
    	for (int i = 1;i <= n;i++) trainID[i] = tmp6[i];
    	delete []tmp6;
    	
    	string *tmp7 = start;
    	start = new string[n0];
    	for (int i = 1;i <= n;i++) start[i] = tmp7[i];
    	delete []tmp7;
    	
    	string *tmp8 = end;
    	end = new string[n0];
    	for (int i = 1;i <= n;i++) end[i] = tmp8[i];
    	delete []tmp8;
    	
    	Date *tmp9 = day;
    	day = new Date[n0];
    	for (int i = 1;i <= n;i++) day[i] = tmp9[i];
    	delete []tmp9;
    	
    	Time *tmp10 = onesecondmore;
    	onesecondmore = new Time[n0];
    	for (int i = 1;i <= n;i++) onesecondmore[i] = tmp10[i];
    	delete []tmp10;
    }
public:
	Log() {
	    n = 0;
	    n0 = 16;
	    name = new string[n0];
	    userID = new string[n0];
	    change = new string[n0];
	    number = new int [n0];
	    tickettype = new string[n0];
	    trainID = new string[n0];
	    start = new string[n0];
	    end = new string[n0];
	    day = new Date[n0];
	    onesecondmore = new Time[n0];
	}
	void AddBook(const string a,const string b,const int c,const string d,const string e,const string f,const string g,const Date h,const Time i){
	    ++n;
	    if (n >= n0 - 1) doublespace();
	    name[n] = a;
	    userID[n] = b;
	    change[n] = "bought";
	    number[n] = c;
	    tickettype[n] = d;
	    trainID[n] = e;
	    start[n] = f;
	    end[n] = g;
	    day[n] = h;
	    onesecondmore[n] = i;
	}
	void AddReturn(const string a,const string b,const int c,const string d,const string e,const string f,const string g,const Date h,const Time i){
		++n;
	    if (n >= n0 - 1) doublespace();
	    name[n] = a;
	    userID[n] = b;
	    change[n] = "refunded";
	    number[n] = c;
	    tickettype[n] = d;
	    trainID[n] = e;
	    start[n] = f;
	    end[n] = g;
	    day[n] = h;
	    onesecondmore[n] = i;
	}
	void Print(){
		for (int i = 1;i <= n;i++){
			binofstream f1("D:\\Log.txt");
			if (!f1) return;
		    f1<<name[i]<<' '<<userID[i]<<' '<<change[i]<<' '<<number[i]<<' '<<tickettype[i]<<" tickets of "
			    trainID[i]<<" from "<<start[i]<<" to "<<end[i]<<" in "<<day[i]<<" at "<<onsecondmore[i]<<'\n';
		    f1.close();
		}
	}
	~Log(){
		delete []name;
		delete []userID;
		delete []change;
		delete []number;
		delete []tickettype;
		delete []trainID;
		delete []start;
		delete []end;
		delete []day;
		delete []onesecondmore;
	}
};
			    
	
    
	
