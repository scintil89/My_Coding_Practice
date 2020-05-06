#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42579
vector<int> solution(vector<string> genres, vector<int> plays)
{
	int length = (int)genres.size();

	multimap<string, pair<int, int>> genPlay;

	for (int i = 0; i < length; ++i)
	{
		genPlay.emplace(genres[i], make_pair(plays[i], i));
	}

	map<string, int> mapGenPlay;

	for (auto& i : genPlay)
	{
		if (mapGenPlay.find(i.first) == mapGenPlay.end())
		{
			mapGenPlay.emplace(i.first, 0);
		}

		mapGenPlay[i.first] += i.second.first;
	}

	vector<pair<string, int>> vecGenPlay;
	for (auto& i : mapGenPlay)
	{
		vecGenPlay.emplace_back(i);
	}

	std::sort(vecGenPlay.begin(), vecGenPlay.end(), [](pair<string, int> a, pair<string, int> b) { return a.second > b.second; });

	vector<int> answer;

	for (auto& v : vecGenPlay)
	{
		auto finder = genPlay.equal_range(v.first);

		vector<pair<int, int>> vecP;

		for (auto i = finder.first; i != finder.second; ++i)
		{
			vecP.emplace_back(i->second);
		}

		std::sort(vecP.begin(), vecP.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });

		int count = 0;
		for (auto& vv : vecP)
		{
			if (count >= 2)
			{
				break;
			}

			answer.emplace_back(vv.second);
			count++;
		}
	}

	return answer;
}