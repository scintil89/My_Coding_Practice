#include <iostream>
#include <set>

int main(void)
{
	//set 중복 허용 테스트
	std::set<int> set1;

	set1.insert(5);
	set1.insert(5);
	set1.insert(5);
	set1.insert(5);
	set1.insert(3);
	
	for (auto& i : set1)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;

	//multiset 중복 허용 테스트

	std::multiset<int> set2;

	set2.insert(5);
	set2.insert(4);
	set2.insert(5);
	set2.insert(5);
	set2.insert(3);
	set2.insert(4);
	set2.insert(3);

	for (auto& i : set2)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	getchar();

	return 0;

}