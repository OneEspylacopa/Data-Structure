/*Time.hpp
���죺Time(9,29),      ע������������ĳ����Ϊ��λ������Ҫ����
Time("09:29");   ע����������Ǳ�׼��ʱ���ʽ�ַ�������λ�����㣩
�����fout << obj;
���룺fin >> obj;      ��Ϊ��׼��ʱ���ʽ
ע���ļ����������ʱ��ofstream �� ifstream ����ͬʱ����ͬһ���ļ�������ʹ�ñ����ͻ��������
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


