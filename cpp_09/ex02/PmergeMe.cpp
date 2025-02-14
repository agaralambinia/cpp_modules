#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _lst(other._lst) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_lst = other._lst;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printFirstElements(const std::list<int>& lst, int n) {
    std::list<int>::const_iterator it = lst.begin();
    int count = 0;

    while (it != lst.end() && count < n) {
        std::cout << *it << " ";
        ++it;
        ++count;
    }

	if (lst.size() > 4) std::cout << "[...]";
	std::cout << std::endl;
}

std::list binaryJacobsthalInsertion(std::list<std::list>& lst) {
	//НАПИСАТЬ
}

std::list recursiveFordJohnsonLst(std::list<std::list>& initList) {
	std::list<std::list> winners;
	std::list<std::list> losers;
	int i = 0;

	while (!initList.empty()) {
		std::list<int> first;
		std::list<int> second;

		first.push_back(initList.front().front());
		first.push_back(initList.front().back());
		initList.pop_front();
		second.push_back(initList.front().front());
		second.push_back(initList.front().back());
		initList.pop_front();

		if (first.front() >= second.front()) {
			second.push_back(first.front().back());
			losers.push_back(second);
			first.pop_back();
			first.push_back(i);
			winners.push_back(first);
		}
		else {
			first.push_back(second.front().back());
			losers.push_back(first);
			second.pop_back();
			second.push_back(i);
			winners.push_back(second);
		}
		i++;
	}
	if (winners.size() == 1) {
		return binaryJacobsthalInsertion(winners, losers);
	}
	return binaryJacobsthalInsertion(recursiveFordJohnsonLst(winners, losers));
}

std::list PmergeMe::beginSortList(std::list<int>& lst) {
	std::list<std::list> initList;
	std::list<int> node;

	while (!lst.empty()) {
		node.push_back(lst.front());
		lst.pop_front();
		node.push_back(0);
		initList.push_back(node);
	}

	initList = recursiveFordJohnsonLst(initList);
	while (!initList.empty()) {
		lst.push_back(initList.front(front()));
		initList.pop_front();
	}
	return(lst);
}

void PmergeMe::sort(int argc, char** argv) {
	if (argc <= 2) {
		std::cerr << "Error: Wrong amount of args. Give at least 1 int." << std::endl;
		return;
	}

	_lst.clear();

	for (int i = 1; i < argc; ++i) {
		if (!isValidNumber(argv[i])) {
			std::cerr << "Error: Invalid input '" << argv[i] << "'. Only positive integers are allowed." << std::endl;
			_lst.clear();
			return;
		}

		long num = std::atol(argv[i]);
		if (num <= 0 || num > INT_MAX) {
			std::cerr << "Error: Number '" << argv[i] << "' is out of range. Must be positive and not greater than INT_MAX." << std::endl;
			_lst.clear();
			return;
		}

		_lst.push_back(static_cast<int>(num));
	}

	std::cout << "Before: ";
	printFirstElements(_lst, 4);

	clock_t start = clock();
	if (!_lst.empty() && !_lst.size == 1) {
		_lst = beginSortList(_lst);
	}
	clock_t end = clock();
	double list_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After:  ";
	printFirstElements(_lst, 4);

	std::cout << "Time to process a range of " << _lst.size() 
			  << " elements with std::list   : " << std::fixed 
			  << std::setprecision(5) << list_time << " us" << std::endl;
	_lst.clear();
}
