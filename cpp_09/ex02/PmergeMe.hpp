#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>

class PmergeMe {
private:
	std::list<int> _lst;

	bool			isValidNumber(const char* str);
	void printFirstElements(const std::list<int>& lst, int n);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void sort(int argc, char** argv);
};

#endif
