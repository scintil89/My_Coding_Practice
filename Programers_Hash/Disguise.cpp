#include <string>
#include <vector>
#include <map>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42578
int solution(vector<vector<string>> clothes) {
	std::map<string, int> closet;

	for (auto& cloth : clothes)
	{
		if (closet.find(cloth[1]) == closet.end())
		{
			closet.emplace(cloth[1], 1);
		}

		++closet[cloth[1]];
	}

	int answer = 1;

	for (auto& clo : closet)
	{
		answer *= clo.second;
	}

	return answer - 1;
}