#include "RealType.hpp"

int main(void)
{
	srand(time(NULL));
	Base *p = generator();
	// Base *p = nullptr;
	identify(p);
	identify(*p);
	delete p;
	return 0;
}