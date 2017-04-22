#include<iostream>
#include<cstring>
#include<fstream>
// File Of Xiao Yunxuan 
using namespace std;

class Date{
	private:
		int year;
		int month[2];
		int day[2];
	public:
		Date(){};
		Date(int y, int m, int d) {
			year = y;
			for(int i = 1;i >= 0;i--) {
				month[i] = m % 10;
				m /= 10;
			}
			for(int i = 1;i >= 0;i--) {
				day[i] = d % 10;
				d /= 10;
			}
		}
		friend ifstream& operator>>(const ifstream &fin) {
			char *str = new char[10];
			fin.getline(str,10); 
			for(int i = 0;i < 4;i++) 
				year = year*10 + str[i] - '0';
			month[0] = str[5] - '0';
			month[1] = str[6] - '0';
			day[0] = str[8] - '0';
			day[1] = str[9] - '0';
			delete [] str;
			return fin;
		}
		friend ofstream& operator<<(const ofstream &fout)const {
			fout<<year<<'-';
			for(int i = 0;i < 2;i++) 
				fout<<month[i];
			fout<<'-';
			for(int i = 0;i < 2;i++) 
				fout<<day[i];
			return fout;
		}
}; 




