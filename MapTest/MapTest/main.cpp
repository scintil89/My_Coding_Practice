#include <iostream>
#include <map>


int main(void)
{
	std::map<int, char> map1;

	map1.insert(std::make_pair(1, 'a'));
	map1.insert(std::make_pair(1, 'a'));
	map1.insert(std::make_pair(1, 'a'));
	map1.insert(std::make_pair(3, 'd'));
	map1.insert(std::make_pair(4, 'f'));
	map1.insert(std::make_pair(7, 'e'));


	std::multimap<int, float> map2;
	
}