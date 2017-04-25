#ifndef DATE_HPP
#define DATE_HPP

#include<iostream>
#include<cstring>
#include<iomanip>
#include"binfstream.hpp"
// File Of Xiao Yunxuan 
using namespace std;

class Date{
	private:
		int year;
		int month;
		int day;
	public:
		Date(){year = 0;month = 0;day = 0;};
		Date(const string& str) {
			for(int i = 0;i < 4;i++)
				year = year * 10 + str[i] - '0';
				month = (str[5] - '0')*10 + str[6] - '0';
				day = (str[8] - '0')*10 + str[9] - '0';
		}
		void SetDate(const string &str){
			for(int i = 0;i < 4;i++)
				year = year * 10 + str[i] - '0';
				month = (str[5] - '0')*10 + str[6] - '0';
				day = (str[8] - '0')*10 + str[9] - '0';
		}
		string GetDate()const{
			string str;
			int y = year, m = month , d = day;
			for(int i = 3;i >= 0;i--,y/=10)
				str[i] = y % 10;
			for(int i = 6;i >= 5;i--,m/=10)
				str[i] = m % 10;
			for(int i = 9;i >= 8;i--,d/=10)
				str[i] = d % 10;	
				str[4] = str[7]  = '-';
			return str;	
		}
		friend binofstream& operator<<(binofstream &fout, const Date& date){   //友元函数无法加const？... 
			fout << date.year << '-' << setfill('0') << setw(2) << date.month << '-' <<date.day;
			return fout;
		}
		friend binifstream& operator>>(binifstream &fin, Date& date) {
			string str;
			fin >> str;
			date.SetDate(str);
			return fin;
		}
		
}; 


#endif

