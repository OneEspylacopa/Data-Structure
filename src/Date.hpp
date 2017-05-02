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
				cout<<year<<" "<<month<<" "<<day<<endl;
		}
		string GetDate()const{
			char str[11];
			int y = year, m = month , d = day;
			for(int i = 3;i >= 0;i--,y/=10)
				str[i] = y % 10 + '0';
			for(int i = 6;i >= 5;i--,m/=10)
				str[i] = m % 10 + '0';
			for(int i = 9;i >= 8;i--,d/=10)
				str[i] = d % 10 + '0';	
				str[4] = str[7]  = '-';
				str[10] = '\0';
			string ans = str;
			return ans;	
		}
		bool operator<(const Date &date){          //小于 即早于 
			if(year != date.year) {
				return year < date.year;
			}
			if(month != date.month) {
				return month < date.month;
			}
			return
			if(year > date.year)return false;
			else if (year < date.year)return true;
			if(month > date.month)return false;
			else if (month < date.month)return true;
			if(day >= date.day)return false;
			else if (day < date.day)return true;
		}
		friend binofstream& operator<<(binofstream &fout, const Date& date){   //友元函数无法加const？... 
			string str = date.GetDate();
			fout << str;
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

