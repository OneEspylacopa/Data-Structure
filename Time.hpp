/*Time.hpp
  构造：Time(9,29),      注意这里若存在某个量为个位数则不需要补零 
        Time("09:29");   注意这里必须是标准的时间格式字符串（个位数补零） 
  输出：fout << obj;
  输入：fin >> obj;      均为标准的时间格式 
  注意文件的输入输出时，ofstream 和 ifstream 不能同时关联同一个文件，否则使用本类型会出现乱码 
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

