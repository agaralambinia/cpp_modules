#include "MutantStack.hpp"

#define BLUE	"\033[34;1m"
#define RESET	"\033[0m"

#include <deque>
#include <stack>

int main()
{
	std::cout << BLUE"TESTS FROM SUBJECT"RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << BLUE"MORE TESTS"RESET << std::endl;
	std::cout << BLUE"Constructors test"RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		MutantStack<int> mstack2(mstack);
		MutantStack<int> *mstack3 = new MutantStack<int>;
		*mstack3 = mstack2;
		std::cout << mstack.top() << std::endl;
		std::cout << mstack2.top() << std::endl;
		std::cout << mstack3->top() << std::endl;
		delete mstack3;
	}

	std::cout << BLUE"Tests for common stack methods"RESET << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("Test");
		mstack.push("Test2");
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.top() << std::endl;
		std::cout << mstack.empty() << std::endl;
		std::cout << mstack.size() << std::endl;
	}

	std::cout << BLUE"Tests for iterators"RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);

		std::cout << "Test of iterator" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "Test of reverse iterator" << std::endl;
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}

		std::cout << "Test of const iterator" << std::endl;
		MutantStack<int>::const_iterator cit = mstack.begin();
		MutantStack<int>::const_iterator cite = mstack.end();
		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}

		std::cout << "Test of const reverse iterator" << std::endl;
		MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator crite = mstack.rend();
		while (crit != crite)
		{
			std::cout << *crit << std::endl;
			++crit;
		}
	}
	return 0;
}
