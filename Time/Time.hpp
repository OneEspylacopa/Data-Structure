/*Time.hpp
构造：Time(9,29),      注意这里若存在某个量为个位数则不需要补零
Time("09:29");   注意这里必须是标准的时间格式字符串（个位数补零）
输出：fout << obj;
输入：fin >> obj;      均为标准的时间格式
注意文件的输入输出时，ofstream 和 ifstream 不能同时关联同一个文件，否则使用本类型会出现乱码
*/

#include "binfstream.hpp"
#include <cstring>
using std::string;

class Time {
private:
	int hour;
	int minute;
public:
	Time() {};
	//Time(int _hour = 0, int _minute = 0):hour(_hour), minute(_minute){}

	Time(const string& s) {
		hour = int(s[0] - '0') * 10 + int(s[1] - '0');
		minute = int(s[3] - '0') * 10 + int(s[4] - '0');
	}

	void setTime(const string& s) {
		hour = int(s[0] - '0') * 10 + int(s[1] - '0');
		minute = int(s[3] - '0') * 10 + int(s[4] - '0');
	}

	string getTime() const {
		char a[6];
		a[0] = char(hour % 10 + '0');
		a[1] = char(hour / 10 + '0');
		a[2] = ':';
		a[3] = char(minute % 10 + '0');
		a[4] = char(minute / 10 + '0');
		a[5] = '\0';
		string str = a;
		return str;
	}

	friend binofstream& operator<<(binofstream& fout, const Time& obj) {
		char a[6];
		a[0] = char(hour % 10 + '0');
		a[1] = char(hour / 10 + '0');
		a[2] = ':';
		a[3] = char(minute % 10 + '0');
		a[4] = char(minute / 10 + '0');
		a[5] = '\0';
		string str = a;
		fout << str;
		return fout;
	}
	friend binifstream& operator >> (binifstream& fin, Time& obj) {
		string str;
		fin >> str;
		obj = Time(str);
		return fin;
	}
};


