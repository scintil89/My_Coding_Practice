// ClassStructTst.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
		std::cout << "����������" << std::endl;
		a = 10;
		std::cout << "test int : " << a << std::endl;
	}

	static int a;

private:

};

MyClass::MyClass()
{
	std::cout << "������" << std::endl;
}

MyClass::~MyClass()
{
	std::cout << "�Ҹ���" << std::endl;
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

