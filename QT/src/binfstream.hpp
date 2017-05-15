#ifndef BINFSTREAM_HPP
#define BINFSTREAM_HPP

#include <fstream>
#include <cstring>

using std::string;

class binfstream {
protected:
	FILE *fp;
	
	void open(const char *filename, const char *mode) {
		fp = fopen(filename, mode);
	}
	
public:
	binfstream() {}
	
	void close() {
		fclose(fp);
	}
	
	bool is_open() {
		return fp != NULL;
	}
};

class binifstream : public binfstream {
public:
	binifstream() {}
	
	void open(const char *filename) {
		binfstream::open(filename, "rb");
	}
	
	binifstream& operator>>(char *s) {
		int len;
		fread(&len, sizeof(int), 1, fp);
		fread(s, sizeof(char), sizeof(char) * len, fp);
		s[len] = '\0';
		return *this;
	}
	
	binifstream& operator>>(string &s) {
		int len;
		fread(&len, sizeof(int), 1, fp);
		char *tmp = new char[len + 1];
		fread(tmp, sizeof(char), sizeof(char) * len, fp);
		tmp[len] = '\0';
		s = tmp;
		delete []tmp;
		return *this;
	}
	
	template<class T>
	binifstream& operator>>(T &x) {
		fread(&x, sizeof(T), 1, fp);
		return *this;
	}
};

class binofstream : public binfstream {
public:
	binofstream() {}
	
	void open(const char *filename) {
		binfstream::open(filename, "wb");
	}
	
	void flush() {
		fflush(fp);
	}
	
	binofstream& operator<<(const char *s) {
		int len = strlen(s);
		fwrite(&len, sizeof(int), 1, fp);
		fwrite(s, sizeof(char), sizeof(char) * len, fp);
		return *this;
	}
	
	binofstream& operator<<(const string &s) {
		int len = s.size();
		fwrite(&len, sizeof(int), 1, fp);
		fwrite(s.c_str(), sizeof(char), sizeof(char) * len, fp);
		return *this;
	}
	
	binofstream& operator<<(const bool &x) {
		fwrite(&x, sizeof(bool), 1, fp);
		return *this;
	}
	
	binofstream& operator<<(const int &x) {
		fwrite(&x, sizeof(int), 1, fp);
		return *this;
	}
	
	binofstream& operator<<(const unsigned int &x) {
		fwrite(&x, sizeof(unsigned int), 1, fp);
		return *this;
	}
	
	binofstream& operator<<(const unsigned long long &x) {
		fwrite(&x, sizeof(unsigned long long), 1, fp);
		return *this;
	}
	
	binofstream& operator<<(const double &x) {
		fwrite(&x, sizeof(double), 1, fp);
		return *this;
	}
};


#endif
