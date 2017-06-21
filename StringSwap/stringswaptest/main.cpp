#include <iostream>
#include <string>
#include <sstream>
#include <stack>

int main()
{
	std::string str = "I got you in my sight";
	//std::string res;
	std::string token;
	std::istringstream temp(str);
	std::stack<std::string> tokStack;

	while (getline(temp, token, ' '))
	{
		std::cout << token << " - ";
		tokStack.push(token);
	}

	std::cout << std::endl;

	while (tokStack.empty() == false)
	{
		std::cout << tokStack.top() << " - ";
		tokStack.pop();
	}

	getchar();

	return 0;
}


//int i = 0;
//
//while (str[i] != '\0')
//{
//	std::cout << i << "¹øÂ° : " << str[i] << std::endl;
//	++i;
//}

//std::cout << str.size() << std::endl;