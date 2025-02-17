#include "PmergeMe.hpp"

/*
suggested tests
error checks:
	- empty
	- 2 4 f
	- 2 3 5f
	- 3 2147483648 3
	- --5 43 2
good:
	- 1 2 3 4 5
	- 9 4 5
	- 5
*/

int main(int argc, char** argv) {
	PmergeMe sorter;
	sorter.sort(argc, argv);
	return 0;
}
