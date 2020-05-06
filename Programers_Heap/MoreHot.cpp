#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42626

int solution(vector<int> scoville, int K)
{
	priority_queue<int, vector<int>, greater<int>> pQueue;

	for (auto& sco : scoville)
	{
		pQueue.push(sco);
	}

	int answer = 0;
	while (true)
	{
		if (pQueue.top() > K)
		{
			break;
		}

		if (pQueue.size() == 1)
		{
			return -1;
		}

		auto f1 = pQueue.top();
		pQueue.pop();

		auto f2 = pQueue.top();
		pQueue.pop();

		pQueue.emplace(f1 + f2 * 2);

		++answer;
	}

	return answer;
}