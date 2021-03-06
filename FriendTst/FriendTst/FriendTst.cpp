// 171215
// c++ friend 키워드 공부
// 참고자료 : https://msdn.microsoft.com/ko-kr/library/465sdshe.aspx
//			: http://blog.eairship.kr/172
//			: http://genesis8.tistory.com/98

#include "stdafx.h"
#include <iostream>


class A;

class B;

class A
{
public:
	//friend B;
	A()	{}
	A(int _data) : data(_data) {}

private:
	friend B;
	int data;

	void AccessB_data(B b);
};

class B
{
public:
	B() {}
	B(int _data) : data(_data) {}

private:
	//friend A;
	int data;

	void AccessA_data(A a);
};

int main()
{
	auto ca = A(5);
	auto cb = B(2);

    return 0;
}

void A::AccessB_data(B b)
{
	//std::cout << AccessB_data << b.data << std::endl;
}

void B::AccessA_data(A a)
{
	std::cout << "AccessA_data" << a.data << std::endl;
}
