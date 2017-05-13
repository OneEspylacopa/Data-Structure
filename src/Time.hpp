#ifndef TIME_HPP
#define TIME_HPP

#include <cstring>
#include "binfstream.hpp"
using std::string;

class Time {
private:
	int hour;
	int minute;
public:
	Time() {
		hour = 0;
		minute = 0;
	};

	Time(const string& s) {
		hour = int(s[0] - '0') * 10 + int(s[1] - '0');
		minute = int(s[3] - '0') * 10 + int(s[4] - '0');
	}

	void SetTime(const string& s) {
		hour = int(s[0] - '0') * 10 + int(s[1] - '0');
		minute = int(s[3] - '0') * 10 + int(s[4] - '0');
	}

	string GetTime() const {
		char a[6];
		a[0] = char(hour / 10 + '0');
		a[1] = char(hour % 10 + '0');
		a[2] = ':';
		a[3] = char(minute / 10 + '0');
		a[4] = char(minute % 10 + '0');
		a[5] = '\0';
		string str = a;
		return str;
	}

	bool operator<(const Time &obj) const {
		if(hour != obj.hour) {
			return hour < obj.hour;
		} else {
			return minute < obj.minute;
		}
	}
	bool operator!=(const Time &obj) const {
		return hour != obj.hour || minute != obj.minute;
	}
	
	friend binofstream& operator<<(binofstream& fout, const Time& obj) {
		fout << obj.hour << obj.minute;
		return fout;
	}
	friend binifstream& operator >> (binifstream& fin, Time& obj) {
		fin >> obj.hour >> obj.minute;
		return fin;
	}
};
#endif

