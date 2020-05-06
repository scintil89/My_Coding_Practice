#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42577
bool solution(vector<string> phone_book)
{
	std::sort(phone_book.begin(), phone_book.end(), std::greater<string>());

	std::set<string> strSet;


	for (auto& str : phone_book)
	{
		if (strSet.find(str) == strSet.end())
		{
			for (int i = 0; i < str.length(); ++i)
			{
				string subStr = str.substr(0, i);

				if (strSet.find(subStr) == strSet.end())
				{
					strSet.emplace(subStr);
				}
			}
		}
		else
		{
			return false;
		}
	}

	return true;
}