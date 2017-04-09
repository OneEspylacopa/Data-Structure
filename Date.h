#include<iostream>
#include<cstring>
// File Of Xiao Yunxuan 
using namespace std;

class Date{
	private:
		int year[4];
		int month[2];
		int day[2];
	public:
		Date(){};
		Date(int y, int m, int d){
			for(int i = 3;i >= 0;i--){year[i] = y % 10; y /= 10;}
			for(int i = 1;i >= 0;i--){month[i] = m % 10; m /= 10;}
			for(int i = 1;i >= 0;i--){day[i] = d % 10; d /= 10;}
		}
		Date(const string &str){
			for(int i = 0;i < 4;i++) year[i] = str[i] - '0';
			month[0] = str[5] - '0';
			month[1] = str[6] - '0';
			day[0] = str[8] - '0';
			day[1] = str[9] - '0';
		}
		void Print(){
			for(int i = 0;i < 4;i++) cout<<year[i];
			cout<<'-';
			for(int i = 0;i < 2;i++) cout<<month[i];
			cout<<'-';
			for(int i = 0;i < 2;i++) cout<<day[i];
		}
}; 

