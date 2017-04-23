#ifndef BINFSTREAM_HPP
#define BINFSTREAM_HPP

#include <fstream>
#include <cstring>

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
	
	binofstream& operator<<(const char *s) {
		int len = strlen(s);
		fwrite(&len, sizeof(int), 1, fp);
		fwrite(s, sizeof(char), sizeof(char) * len, fp);
		return *this;
	}
	
	template<class T>
	binofstream& operator<<(T x) {
		fwrite(&x, sizeof(T), 1, fp);
		return *this;
	}
};


#endif
