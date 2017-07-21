#include <iostream>
#include <string>

int MyAtoi(const char* str)
{
	int ret = 0;
	int sign = 1;
	int i = 0;
	
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
		

	for (i ; str[i] != '\0'; i++)
	{
		ret = ret * 10 + str[i] - '0';
	}

	return ret;
}

int main(void)
{

	int num = MyAtoi("-12345");

	std::cout << num << std::endl;


	getchar();

	return 0;
}