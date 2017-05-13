#ifndef DATE_HPP
#define DATE_HPP

#include<cstring>
#include"binfstream.hpp" 
using std::string;
class Date{
	private:
		int year;
		int month;
		int day;
	public:
		Date(){
			year = 0;
			month = 0;
			day = 0;
		}
		Date(const string& str) {
			day = month = year = 0; 
			for(int i = 0;i < 4;i++){
				year = year * 10 + str[i] - '0';
			}
			month = (str[5] - '0')*10 + str[6] - '0';
			day = (str[8] - '0')*10 + str[9] - '0';
		}
		void SetDate(const string &str){
			for(int i = 0;i < 4;i++){
				year = year * 10 + str[i] - '0';
			}
			month = (str[5] - '0')*10 + str[6] - '0';
			day = (str[8] - '0')*10 + str[9] - '0';
		}
		string GetDate()const{
			char str[11];
			int y = year, m = month , d = day;
			for(int i = 3;i >= 0;i--,y/=10){
			//	std::cout<<y;
				str[i] = y % 10 + '0';
			}
			for(int i = 6;i >= 5;i--,m/=10){
				str[i] = m % 10 + '0';
			}
			for(int i = 9;i >= 8;i--,d/=10){
				str[i] = d % 10 + '0';
			}
			str[4] = str[7]  = '-';
			str[10] = '\0';
//			string ans = str;
			return str;	
		}
		bool operator<(const Date &date) const {          //?? ??? 
			if(year != date.year){
				return year < date.year;
			}
			else if(month != date.month){
				return month < date.month;
			}
			else return day < date.day;
		}
		bool operator!=(const Date &date) const {
			return year != date.year || month != date.month || day != date.day;
		}
		
		friend binofstream& operator<<(binofstream &fout, const Date& date) {
			fout << date.year << date.month << date.day;
			return fout;
		}
		friend binifstream& operator>>(binifstream &fin, Date& date) {
			fin >> date.year >> date.month >> date.day;
			return fin;
		}
}; 

#endif

