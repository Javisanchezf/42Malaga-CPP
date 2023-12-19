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