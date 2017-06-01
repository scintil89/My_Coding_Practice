#include <iostream>

// Fibonacci
// 1 1 2 3 5 8 13 21 ...


int Fibo(int num)
{
	if (num == 0)
		return 0;

	if (num == 1 | num == 2)
		return 1;

	return Fibo(num - 2) + Fibo(num - 1);
}


int main(void)
{
	std::cout << Fibo(8) << std::endl;

	getchar();
}