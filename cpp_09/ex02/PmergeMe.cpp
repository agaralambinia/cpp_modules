#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _lst(other._lst) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vec = other._vec;
        _lst = other._lst;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const char* str) {
    if (!str || !*str) return false;

    for (const char* ptr = str; *ptr; ++ptr) {
        if (!std::isdigit(*ptr)) return false;
    }
    return true;
}

void PmergeMe::mergeVector(std::vector<int>& arr, size_t left, size_t mid, size_t right) {
    std::vector<int> temp(right - left + 1);
    size_t i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void PmergeMe::mergeSortVector(std::vector<int>& arr, size_t left, size_t right) {
    if (left >= right) {
        return;
    }

    size_t mid = left + ((right - left) / 2);
    mergeSortVector(arr, left, mid);
    mergeSortVector(arr, mid + 1, right);
    mergeVector(arr, left, mid, right);
}

std::list<int> PmergeMe::mergeList(std::list<int>& left, std::list<int>& right) {
    std::list<int> result;

    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
        }
    }

    result.splice(result.end(), left);
    result.splice(result.end(), right);

    return result;
}

std::list<int> PmergeMe::mergeSortList(std::list<int>& lst) {
    if (_lst.size() <= 1) {
        return lst;
    }

    std::list<int> left, right;
    size_t mid = _lst.size() / 2;

    for (size_t i = 0; i < mid; ++i) {
        left.push_back(_lst.front());
        _lst.pop_front();
    }
    right.splice(right.begin(), lst);

    left = mergeSortList(left);
    right = mergeSortList(right);

    return mergeList(left, right);
}

void PmergeMe::sort(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: Wrong amount of args. Give exactly 1 expression." << std::endl;
        return;
    }

    _vec.clear();
    _lst.clear();

    for (int i = 1; i < argc; ++i) {
        if (!isValidNumber(argv[i])) {
            std::cerr << "Error: Invalid input '" << argv[i] << "'. Only positive integers are allowed." << std::endl;
    		_vec.clear();
    		_lst.clear();
            return;
        }

        long num = std::atol(argv[i]);
        if (num <= 0 || num > INT_MAX) {
            std::cerr << "Error: Number '" << argv[i] << "' is out of range. Must be positive and not greater than INT_MAX." << std::endl;
    		_vec.clear();
    		_lst.clear();
            return;
        }

        _vec.push_back(static_cast<int>(num));
        _lst.push_back(static_cast<int>(num));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size() && i < 4; ++i) {
        std::cout << _vec[i] << " ";
    }
    if (_vec.size() > 4) std::cout << "[...]";
    std::cout << std::endl;

    clock_t start = clock();
    if (!_vec.empty()) {
        mergeSortVector(_vec, 0, _vec.size() - 1);
    }
    clock_t end = clock();
    double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    if (!_lst.empty()) {
        _lst = mergeSortList(_lst);
    }
    end = clock();
    double list_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size() && i < 4; ++i) {
        std::cout << _vec[i] << " ";
    }
    if (_vec.size() > 4) std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << std::fixed 
              << std::setprecision(5) << vector_time << " us" << std::endl;
    std::cout << "Time to process a range of " << _lst.size() 
              << " elements with std::list   : " << std::fixed 
              << std::setprecision(5) << list_time << " us" << std::endl;
	_vec.clear();
    _lst.clear();
}
