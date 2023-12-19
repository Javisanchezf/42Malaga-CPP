#include "RealType.hpp"

int main(void)
{
	srand(time(NULL));
	Base *p = generator();
	Base *a = new A;
	Base *b = new B;
	Base *c = new C;
	Base *null = nullptr;
	std::cout << "---------------------------------" << std::endl;
	identify(a);
	identify(*a);
	identify(b);
	identify(*b);
	identify(c);
	identify(*c);
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Now the null: " << std::endl;
	identify(null);
	identify(*null);
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Now the random: " << std::endl;
	identify(p);
	identify(*p);
	delete a;
	delete b;
	delete c;
	delete p;
	// Base *p = nullptr;
	return 0;
}