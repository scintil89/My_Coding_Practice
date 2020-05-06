#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <set>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42628
vector<int> solution(vector<string> operations)
{
	priority_queue<int> asc;
	priority_queue<int, vector<int>, greater<int>> des;
	set<int> numbers;

	for (auto& op : operations)
	{
		if (op[0] == 'I')
		{
			string num = op.substr(2, op.size() - 1);

			int n = stoi(num);
			asc.emplace(n);
			des.emplace(n);
			numbers.emplace(n);
		}
		else if (op == "D 1")
		{
			if (numbers.size() == 0)
			{
				continue;
			}
			while (true)
			{
				auto del = asc.top();

				if (numbers.find(del) == numbers.end())
				{
					asc.pop();
					continue;
				}
				else
				{
					asc.pop();
					numbers.erase(del);
					break;
				}
			}
		}
		else
		{
			if (numbers.size() == 0)
			{
				continue;
			}
			while (true)
			{
				auto del = des.top();

				if (numbers.find(del) == numbers.end())
				{
					des.pop();
					continue;
				}
				else
				{
					des.pop();
					numbers.erase(del);
					break;
				}
			}
		}
	}

	if (numbers.size() == 0)
	{
		return { 0, 0 };
	}
	else
	{
		int min = 0;
		while (true)
		{
			min = des.top();

			if (numbers.find(min) == numbers.end())
			{
				des.pop();
				continue;
			}
			else
			{
				des.pop();
				numbers.erase(min);
				break;
			}
		}

		int max = 0;
		while (true)
		{
			max = asc.top();

			if (numbers.find(max) == numbers.end())
			{
				asc.pop();
				continue;
			}
			else
			{
				asc.pop();
				numbers.erase(max);
				break;
			}
		}

		return { max, min };
	}
}