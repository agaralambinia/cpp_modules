#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

#define BLUE	"\033[34;1m"
#define RESET	"\033[0m"

Base *generate(void)
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
	std::cout << "actual type of the object pointed to by p: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	// try-catch to avoid std::bad_cast
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "actual type of the object pointed to by p: A" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "actual type of the object pointed to by p: B" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "actual type of the object pointed to by p: C" << std::endl;
	}
	catch (std::exception &e) {}
}

int main(void)
{
	std::srand(std::time(0));
	for(int i = 0; i < 7; i++)
	{
		std::cout << BLUE"** " << i << " TEST **"RESET << std::endl;
		Base *ptr = generate();
		Base &ref = *ptr;
		identify(ptr);
		identify(ref);
		delete ptr;
	}
	return 0;
}
