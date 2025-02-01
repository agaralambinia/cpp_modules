#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>

#include "easyfind.hpp"

#define BLUE	"\033[34;1m"
#define RESET	"\033[0m"

int main() {
	std::cout << BLUE"Test 1: Vector"RESET << std::endl;
	{
		std::vector<int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.push_back(i);
		}
		std::cout << BLUE"Test 1.1: INT in VECTOR found"RESET << std::endl;
		try {
			std::vector<int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 1.2: INT in VECTOR not found"RESET << std::endl;
		try {
			std::vector<int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 1.3: INT in VECTOR EMPTY CONTAINER"RESET << std::endl;
		std::vector<int> ve;
		try {
			std::vector<int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 1.4: INT in VECTOR boundary cases"RESET << std::endl;
		try {
			std::vector<int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::vector<int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::vector<const int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.push_back(i);
		}
		std::cout << BLUE"Test 1.5: CONST INT in VECTOR found"RESET << std::endl;
		try {
			std::vector<const int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 1.6: CONST INT in VECTOR not found"RESET << std::endl;
		try {
			std::vector<const int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 1.7: CONST INT in VECTOR EMPTY CONTAINER"RESET << std::endl;
		std::vector<const int> ve;
		try {
			std::vector<const int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 1.8: CONST INT in VECTOR boundary cases"RESET << std::endl;
		try {
			std::vector<const int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::vector<const int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << BLUE"Test 2: list"RESET << std::endl;
	{
		std::list<int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.push_back(i);
		}
		std::cout << BLUE"Test 2.1: INT in LIST found"RESET << std::endl;
		try {
			std::list<int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 2.2: INT in LIST not found"RESET << std::endl;
		try {
			std::list<int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 2.3: INT in LIST EMPTY CONTAINER"RESET << std::endl;
		std::list<int> ve;
		try {
			std::list<int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 2.4: INT in LIST boundary cases"RESET << std::endl;
		try {
			std::list<int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::list<int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::list<const int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.push_back(i);
		}
		std::cout << BLUE"Test 2.5: CONST INT in LIST found"RESET << std::endl;
		try {
			std::list<const int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 2.6: CONST INT in LIST not found"RESET << std::endl;
		try {
			std::list<const int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 2.7: CONST INT in LIST EMPTY CONTAINER"RESET << std::endl;
		std::list<const int> ve;
		try {
			std::list<const int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 2.8: CONST INT in LIST boundary cases"RESET << std::endl;
		try {
			std::list<const int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::list<const int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << BLUE"Test 3: deque"RESET << std::endl;
	{
		std::deque<int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.push_back(i);
		}
		std::cout << BLUE"Test 3.1: INT in DEQUE found"RESET << std::endl;
		try {
			std::deque<int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 3.2: INT in DEQUE not found"RESET << std::endl;
		try {
			std::deque<int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 3.3: INT in DEQUE EMPTY CONTAINER"RESET << std::endl;
		std::deque<int> ve;
		try {
			std::deque<int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 3.4: INT in DEQUE boundary cases"RESET << std::endl;
		try {
			std::deque<int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::deque<int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::deque<const int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.push_back(i);
		}
		std::cout << BLUE"Test 3.5: CONST INT in DEQUE found"RESET << std::endl;
		try {
			std::deque<const int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 3.6: CONST INT in DEQUE not found"RESET << std::endl;
		try {
			std::deque<const int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 3.7: CONST INT in DEQUE EMPTY CONTAINER"RESET << std::endl;
		std::deque<const int> ve;
		try {
			std::deque<const int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 3.8: CONST INT in DEQUE boundary cases"RESET << std::endl;
		try {
			std::deque<const int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::deque<const int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << BLUE"Test 4: Set"RESET << std::endl;
	{
		std::set<int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.insert(i);
		}
		std::cout << BLUE"Test 4.1: INT in SET found"RESET << std::endl;
		try {
			std::set<int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 4.2: INT in SET not found"RESET << std::endl;
		try {
			std::set<int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 4.3: INT in SET EMPTY CONTAINER"RESET << std::endl;
		std::set<int> ve;
		try {
			std::set<int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 4.4: INT in SET boundary cases"RESET << std::endl;
		try {
			std::set<int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::set<int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::set<const int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.insert(i);
		}
		std::cout << BLUE"Test 4.5: CONST INT in SET found"RESET << std::endl;
		try {
			std::set<const int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 4.6: CONST INT in SET not found"RESET << std::endl;
		try {
			std::set<const int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 4.7: CONST INT in SET EMPTY CONTAINER"RESET << std::endl;
		std::set<const int> ve;
		try {
			std::set<const int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 4.8: CONST INT in SET boundary cases"RESET << std::endl;
		try {
			std::set<const int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::set<const int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << BLUE"Test 5: Multiset"RESET << std::endl;
	{
		std::multiset<int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.insert(i);
		}
		std::cout << BLUE"Test 5.1: INT in MULTISET found"RESET << std::endl;
		try {
			std::multiset<int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 5.2: INT in MULTISET not found"RESET << std::endl;
		try {
			std::multiset<int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 5.3: INT in MULTISET EMPTY CONTAINER"RESET << std::endl;
		std::multiset<int> ve;
		try {
			std::multiset<int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 5.4: INT in MULTISET boundary cases"RESET << std::endl;
		try {
			std::multiset<int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::multiset<int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::multiset<const int> v;
		for (int i = 0; i <= 10000; i++)
		{
			v.insert(i);
		}
		std::cout << BLUE"Test 5.5: CONST INT in MULTISET found"RESET << std::endl;
		try {
			std::multiset<const int>::iterator it = easyfind(v, 5555);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 5.6: CONST INT in MULTISET not found"RESET << std::endl;
		try {
			std::multiset<const int>::iterator it = easyfind(v, 10001);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 5.7: CONST INT in MULTISET EMPTY CONTAINER"RESET << std::endl;
		std::multiset<const int> ve;
		try {
			std::multiset<const int>::iterator it = easyfind(ve, 1);
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << BLUE"Test 5.8: CONST INT in MULTISET boundary cases"RESET << std::endl;
		try {
			std::multiset<const int>::iterator it = easyfind(v, 1);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		try {
			std::multiset<const int>::iterator it = easyfind(v, 10000);
			std::cout << "Found: " << *it << " at position " << std::distance(v.begin(), it) << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	// Also there are unordered_set, stack, queue
	return 0;
}
