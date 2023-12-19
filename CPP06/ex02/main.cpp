#include <iostream>
#include <string>
#include <ctime>

class Base {public: virtual ~Base() {}};
class A: public Base {};
class B: public Base {};
class C: public Base {};

Base *generator(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p)
{
	try
	{
		// std::cout << "Identify by Pointer: ";
		if (dynamic_cast<A*>(p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(p))
			std::cout << "C" << std::endl;
		else
			std::cout << "Unknown" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void identify(Base &p)
{
    
    try
	{
    	// std::cout << "Identify by Reference: ";
		if (A *a = dynamic_cast<A*>(&p))
			std::cout << "A" << std::endl;
		else if (B *b = dynamic_cast<B*>(&p))
			std::cout << "B" << std::endl;
		else if (C *c = dynamic_cast<C*>(&p))
			std::cout << "C" << std::endl;
		else
			std::cout << "Unknown" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
int main(void)
{
	srand(time(NULL));
	Base *p = generator();
	Base *a = new A;
	Base *b = new B;
	Base *c = new C;
	Base *null = nullptr;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "The A: " << std::endl;
	identify(a);
	identify(*a);
	std::cout << "The B: " << std::endl;
	identify(b);
	identify(*b);
	std::cout << "The C: " << std::endl;
	identify(c);
	identify(*c);
	std::cout << "---------------------------------" << std::endl;
	std::cout << "The null: " << std::endl;
	identify(null);
	identify(*null);
	std::cout << "---------------------------------" << std::endl;
	std::cout << "The random: " << std::endl;
	identify(p);
	identify(*p);
	delete a;
	delete b;
	delete c;
	delete p;
	return 0;
}