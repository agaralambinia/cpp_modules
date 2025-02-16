#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>
#include <iterator>

class PmergeMe {
private:
	std::list<int> _lst;
	std::deque<int> _deq;

	bool isValidNumber(const char* str);

	void printFirstElementsLst(std::list<int>& lst, int n);
	void printFirstElementsDeq(std::deque<int>& deq, int n);
	void generateJacobsthalSequenceLst(std::list<size_t>& result, size_t number);
	std::list<std::list<int> >& binaryInsertValList(std::list<std::list<int> >& result, std::list<std::list<int> >::iterator l);
	std::list<std::list<int> >& insertJacobSeqLst(std::list<std::list<int> >& result, std::list<std::list<int> >& winners, std::list<std::list<int> >& losers, size_t jacob, size_t beginIter);
	std::list<std::list<int> >& binaryInsertionLst(std::list<std::list<int> >& winners, std::list<std::list<int> >& losers);
	std::list<std::list<int> >& recursiveFordJohnsonLst(std::list<std::list<int> >& initList);
	std::list<int>& sortList(std::list<int>& lst);
	std::deque<std::deque<int> >& binaryInsertValDeque(std::deque<std::deque<int> >& result, std::deque<std::deque<int> >::iterator d);
	std::deque<std::deque<int> >& insertJacobSeqDeq(std::deque<std::deque<int> >& result, std::deque<std::deque<int> >& winners, std::deque<std::deque<int> >& losers, size_t jacob, size_t beginIter);
	std::deque<std::deque<int> >& binaryInsertionDeq(std::deque<std::deque<int> >& winners, std::deque<std::deque<int> >& losers);
	std::deque<std::deque<int> >& recursiveFordJohnsonDeq(std::deque<std::deque<int> >& initDeque);
	std::deque<int>& sortDeque(std::deque<int>& deq);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void sort(int argc, char** argv);
};

#endif
