#pragma once
#ifndef REALTYPE_HPP
# define REALTYPE_HPP

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
	std::cout << "Identify by Pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
    std::cout << "Identify by Reference: ";
    
    if (A *a = dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (B *b = dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (C *c = dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

#endif
