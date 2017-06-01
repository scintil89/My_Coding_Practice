#include <stack>
#include <iostream>

class stack2Q
{
public:
	std::stack<int> s1;
	std::stack<int> s2;

public:
	void Push(int num)
	{
		s1.push(num);
	}
	
	void Pop()
	{
		std::cout << s2.top() << std::endl;
		
		s2.pop();
	}

	void QueueProcess()
	{
		while (s1.empty() == false)
		{
			s2.push( s1.top() );

			s1.pop();
		}
	}

};

int main(void)
{
	stack2Q* que = new stack2Q();

	que->Push(3);
	que->Push(5);
	que->Push(7);
	que->Push(9);
	que->Push(11);
	
	que->QueueProcess();

	que->Pop();
	que->Pop();
	que->Pop();
	que->Pop();

	getchar();

	return 0;
}