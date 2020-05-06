#include <string>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/43104

long long solution(int N)
{
	long long answer = 0;

	vector<long long> solVec;

	solVec.emplace_back(1);
	solVec.emplace_back(1);

	for (int i = 0; i < N; ++i)
	{
		solVec.emplace_back(solVec[i] + solVec[i + 1]);
	}

	if (N == 1)
	{
		return 4;
	}

	answer = 4 * solVec[N - 1] + 2 * solVec[N - 2];

	return answer;
}