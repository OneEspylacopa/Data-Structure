#include <cstdio>
#include <iostream>

template<typename T>
class CTest
{
public:
	CTest() {};
	void output(T x);
};


template<typename T>
void CTest<T>::output(T x)
{
	std::cout << x << std::endl;
}
