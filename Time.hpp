/*Time.hpp
  ���죺Time(9,29),      ע������������ĳ����Ϊ��λ������Ҫ���� 
        Time("09:29");   ע����������Ǳ�׼��ʱ���ʽ�ַ�������λ�����㣩 
  �����fout << obj;
  ���룺fin >> obj;      ��Ϊ��׼��ʱ���ʽ 
  ע���ļ����������ʱ��ofstream �� ifstream ����ͬʱ����ͬһ���ļ�������ʹ�ñ����ͻ�������� 
*/

#include "binfstream.hpp"
using std::binifstream;
using std::binofstream;
using std::string;

class Time{
	private:
		int hour;
		int minute;
	public:
		Time(int _hour = 0, int _minute = 0):hour(_hour), minute(_minute){}
		Time(const string& s){
			hour = int(s[0] - '0') * 10 + int(s[1] - '0');
			minute = int(s[3] - '0') * 10 + int(s[4] - '0');
		}
			
	friend binofstream& operator<<(binofstream& fout, const Time& obj)
	{
		if (obj.hour < 10) fout << 0 << obj.hour;	
	    else fout << obj.hour;
	    fout << ":";
	    if (obj.minute < 10) fout << 0 << obj.minute;
	    else fout << obj.minute;
	    return fout;
	}
	friend binifstream& operator>>(binifstream& fin, Time& obj)
	{
		string str;
		fin >> str; 
		obj = Time(str);
		return fin;
	}
};

