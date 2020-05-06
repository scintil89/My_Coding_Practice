#include <string>
#include <vector>
#include <set>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42576

string solution(vector<string> participant, vector<string> completion)
{
	multiset<string> mset;

	for (auto& par : participant)
	{
		mset.emplace(par);
	}

	for (auto& com : completion)
	{
		auto finder = mset.find(com);
		mset.erase(finder);
	}

	string answer = "";
	if (mset.size() > 0)
	{
		answer = *mset.begin();
	}

	return answer;
}