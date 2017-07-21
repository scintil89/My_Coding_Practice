#include <iostream>
#include <memory>

class MyClass
{
public:

	MyClass() {};
	MyClass(int n) : m_ID(n) {};
	~MyClass() {};

	int m_ID;
};

int main(void)
{
	// 1. 

	std::shared_ptr<int> s_ptr1(new int(53));
	
	std::cout << "s_ptr1 : " << *s_ptr1 << " use count : " << s_ptr1.use_count() << std::endl;

	std::shared_ptr<int> s_ptr2 = s_ptr1;

	
	std::cout << "\n=====s_ptr2 after=====\n" << std::endl;
	std::cout << "s_ptr1 : " << *s_ptr1 << " use count : " << s_ptr1.use_count() << std::endl;

	s_ptr1.reset();

	std::cout << "\n=====s_ptr1 reset after=====\n" << std::endl;
	std::cout << " s_ptr1 use count : " << s_ptr1.use_count() << std::endl;

	std::cout << "s_ptr2 : " << *s_ptr2 << " s_ptr2 use count : " << s_ptr2.use_count() << std::endl;
		
	s_ptr2.reset();
	std::cout << "\n=====s_ptr2 reset after=====\n" << std::endl;
	std::cout << " s_ptr2 use count : " << s_ptr2.use_count() << std::endl;


	std::cout << "\n=====================\n" << std::endl;

	
	//2. use auto
	auto myc_sptr = std::make_shared<MyClass>(10);

	std::cout << "myc_sptr : "<< myc_sptr->m_ID << std::endl;

	//s_ptr.reset();


	//3. scope test
	{
		auto myc_sptr2 = myc_sptr;

		std::cout << "myc_sptr use count : " << myc_sptr.use_count() << std::endl;
	}

	std::cout << "myc_sptr use count : " << myc_sptr.use_count() << std::endl;

	myc_sptr.reset();


	std::cout << "\n=====================\n" << std::endl;


	//4. array
	{
		std::shared_ptr<MyClass> MycPtr(new MyClass[3], std::default_delete<MyClass[]>());

		MycPtr.get()[0].m_ID = 100;
		MycPtr.get()[1].m_ID = 101;
		MycPtr.get()[2].m_ID = 102;

		std::cout << MycPtr.get()[0].m_ID << "   " << MycPtr.get()[1].m_ID << std::endl;
	}

	getchar();

	return 0;

}