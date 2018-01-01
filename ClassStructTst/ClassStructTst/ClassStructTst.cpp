// ClassStructTst.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

struct MyStruct
{

};

class MyClass
{
public:
	MyClass();
	~MyClass();

	static void Poo()
	{
		std::cout << "에베베베ㅔ" << std::endl;
		a = 10;
		std::cout << "test int : " << a << std::endl;
	}

	static int a;

private:

};

MyClass::MyClass()
{
	std::cout << "생성자" << std::endl;
}

MyClass::~MyClass()
{
	std::cout << "소멸자" << std::endl;
}

int main()
{
	//MyStruct mys;
	//MyClass myc;

	std::cout << sizeof(MyStruct) << "    " << sizeof(MyClass) << std::endl;

	MyClass::Poo();


	getchar(); 

    return 0;
}

