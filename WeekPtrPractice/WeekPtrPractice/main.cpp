#include <iostream>
#include <memory>
#include <assert.h>

int main(void)
{
	auto p = std::make_shared<int>(42);

	std::weak_ptr<int> wp = p;

	std::cout << wp.expired() << std::endl;

	auto q = wp.lock();

	std::cout << *q << std::endl;

	p.reset(); q.reset();

	std::cout << wp.expired() << std::endl;

	auto r = wp.lock();

	assert(r == 0);

	getchar();

	return 0;
}