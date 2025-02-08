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
	std::vector<int> _vec;
	std::list<int> _lst;

	bool isValidNumber(const char* str);
	void mergeVector(std::vector<int>& arr, size_t left, size_t mid, size_t right);
	void mergeSortVector(std::vector<int>& arr, size_t left, size_t right);
	std::list<int> mergeList(std::list<int>& left, std::list<int>& right);
	std::list<int> mergeSortList(std::list<int>& lst);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void sort(int argc, char** argv);
};

#endif
