#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _lst(other._lst), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
   if (this != &other) {
       this->_lst = other._lst;
	   this->_deq = other._deq;
   }
   return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printFirstElementsLst(std::list<int>& lst, int n) {
   std::list<int>::iterator it = lst.begin();
   int count = 0;

   while (it != lst.end() && count < n) {
       std::cout << *it << " ";
       ++it;
       ++count;
   }

   if (lst.size() > 4) std::cout << "[...]";
   std::cout << std::endl;
}

void PmergeMe::printFirstElementsDeq(std::deque<int>& deq, int n) {
    size_t count = 0;
    size_t size_n = static_cast<size_t>(n);

    for (std::deque<int>::iterator it = deq.begin(); 
         it != deq.end() && count < size_n; ++it, ++count) {
        std::cout << *it << " ";
    }
    if (deq.size() > size_n)
        std::cout << "[...]";
    std::cout << std::endl;
}

bool PmergeMe::isValidNumber(const char* str) {
   if (!str || !*str) return false;

   for (const char* ptr = str; *ptr; ++ptr) {
       if (!std::isdigit(*ptr)) return false;
   }
   return true;
}

std::list<std::list<int> >& PmergeMe::binaryInsertValList(std::list<std::list<int> >& result, std::list<std::list<int> >::iterator l) {
    if (result.empty()) {
        result.push_back(*l);
        return result;
    }

    std::list<std::list<int> >::iterator it = result.begin();
    while (it != result.end() && it->front() < l->front()) {
        ++it;
    }
    result.insert(it, *l);
    return result;
}

std::list<std::list<int> >& PmergeMe::insertJacobSeqLst(std::list<std::list<int> >& result, std::list<std::list<int> >& winners, std::list<std::list<int> >& losers, size_t jacob, size_t beginIter) {
   std::list<std::list<int> >::iterator it = winners.begin();
   std::advance(it, std::min(beginIter - jacob, winners.size()));

   while (it != winners.end() && std::distance(winners.begin(), it) <= static_cast<long>(beginIter)) {
       std::list<int> temp;
       temp.push_back(it->front());
       temp.push_back(0);
       temp.push_back(it->back());
       result.push_back(temp);
       ++it;
   }

   std::list<std::list<int> >::iterator r = result.end();
   while (r != result.begin()) {
       --r;
       if (r->size() == 3) {
           int j = r->back();
           std::list<std::list<int> >::iterator l = losers.begin();
           std::advance(l, j - 1);
           result = binaryInsertValList(result, l);
           r->pop_back();
           r->pop_back();
           r->push_back(l->back());
       }
   }
   return result;
}

std::list<std::list<int> >& PmergeMe::binaryInsertionLst(std::list<std::list<int> >& winners, std::list<std::list<int> >& losers) {
    for (std::list<std::list<int> >::iterator it = losers.begin(); it != losers.end(); ++it) {
        int value = it->front();

        std::list<std::list<int> >::iterator left = winners.begin();
        std::list<std::list<int> >::iterator right = winners.end();

        while (left != right) {
            size_t distance = std::distance(left, right);
            std::list<std::list<int> >::iterator mid = left;
            std::advance(mid, distance / 2);

            if (mid != winners.end() && mid->front() < value) {
                left = ++mid;
            } else {
                right = mid;
            }
        }

        winners.insert(left, *it);
    }
    return winners;
}

std::list<std::list<int> >& PmergeMe::recursiveFordJohnsonLst(std::list<std::list<int> >& initList) {
    if (initList.size() <= 1) return initList;

    std::list<std::list<int> > winners;
    std::list<std::list<int> > losers;
    std::list<int> stray;

    if (initList.size() % 2 != 0) {
        stray = initList.back();
        initList.pop_back();
    }

    std::list<std::list<int> >::iterator it = initList.begin();
    while (it != initList.end()) {
        std::list<int> first = *it++;
        std::list<int> second = *it++;
        
        if (first.front() <= second.front()) {
            winners.push_back(first);
            losers.push_back(second);
        } else {
            winners.push_back(second);
            losers.push_back(first);
        }
    }

    winners = recursiveFordJohnsonLst(winners);

    if (!stray.empty()) {
        std::list<std::list<int> >::iterator pos = winners.begin();
        while (pos != winners.end() && pos->front() < stray.front()) {
            ++pos;
        }
        winners.insert(pos, stray);
    }

    return binaryInsertionLst(winners, losers);
}

std::list<int>& PmergeMe::sortList(std::list<int>& lst) {
    if (lst.size() <= 1) return lst;

    std::list<std::pair<int, int> > pairs;
    std::list<int> remaining;

    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        int first = *it++;
        if (it != lst.end()) {
            int second = *it++;
            if (first > second)
                std::swap(first, second);
            pairs.push_back(std::make_pair(first, second));
        } else {
            remaining.push_back(first);
        }
    }

    std::list<std::pair<int, int> > sortedPairs;
    for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit) {
        std::list<std::pair<int, int> >::iterator insertPos = sortedPairs.begin();
        while (insertPos != sortedPairs.end() && insertPos->first < pit->first) {
            ++insertPos;
        }
        sortedPairs.insert(insertPos, *pit);
    }

    std::list<int> mainChain;
    std::list<int> pendList;

    for (std::list<std::pair<int, int> >::iterator it = sortedPairs.begin(); 
         it != sortedPairs.end(); ++it) {
        mainChain.push_back(it->first);
        pendList.push_back(it->second);
    }

    std::list<size_t> jacobsthalSeq;
    generateJacobsthalSequenceLst(jacobsthalSeq, pendList.size());

    std::list<bool> inserted(pendList.size(), false);
    std::list<int>::iterator pendIt = pendList.begin();
    
    if (!pendList.empty()) {
        std::list<int>::iterator insertPos = mainChain.begin();
        while (insertPos != mainChain.end() && *insertPos < *pendIt) {
            ++insertPos;
        }
        mainChain.insert(insertPos, *pendIt);
        *inserted.begin() = true;
    }

    for (std::list<size_t>::iterator jacIt = jacobsthalSeq.begin(); 
         jacIt != jacobsthalSeq.end(); ++jacIt) {
        size_t idx = *jacIt;
        if (idx >= pendList.size()) continue;

        std::list<int>::iterator pendIt = pendList.begin();
        std::list<bool>::iterator insertedIt = inserted.begin();
        std::advance(pendIt, idx);
        std::advance(insertedIt, idx);

        if (!*insertedIt) {
            std::list<int>::iterator insertPos = mainChain.begin();
            while (insertPos != mainChain.end() && *insertPos < *pendIt) {
                ++insertPos;
            }
            mainChain.insert(insertPos, *pendIt);
            *insertedIt = true;
        }

        size_t curr = idx - 1;
        while (curr > 0) {
            std::list<int>::iterator currPendIt = pendList.begin();
            std::list<bool>::iterator currInsertedIt = inserted.begin();
            std::advance(currPendIt, curr);
            std::advance(currInsertedIt, curr);

            if (!*currInsertedIt) {
                std::list<int>::iterator insertPos = mainChain.begin();
                while (insertPos != mainChain.end() && *insertPos < *currPendIt) {
                    ++insertPos;
                }
                mainChain.insert(insertPos, *currPendIt);
                *currInsertedIt = true;
            }
            --curr;
        }
    }

    if (!remaining.empty()) {
        std::list<int>::iterator insertPos = mainChain.begin();
        while (insertPos != mainChain.end() && *insertPos < remaining.front()) {
            ++insertPos;
        }
	mainChain.insert(insertPos, remaining.front());
    }

    lst = mainChain;
    return lst;
}

void PmergeMe::generateJacobsthalSequenceLst(std::list<size_t>& result, size_t number) {
    result.clear();
    if (number <= 1) return;

    size_t prev2 = 0;
    size_t prev1 = 1;

    result.push_back(1);

    while (true) {
        size_t next = prev2 + 2 * prev1;
        if (next >= number) break;
        
        result.push_back(next);
        prev2 = prev1;
        prev1 = next;
    }
}

std::deque<int>& PmergeMe::sortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return deq;

    std::deque<std::pair<int, int> > pairs;
    bool hasExtra = (deq.size() % 2 != 0);
    int extraValue = 0;

    for (size_t i = 0; i < deq.size() - (hasExtra ? 1 : 0); i += 2) {
        int first = deq[i];
        int second = deq[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }

    if (hasExtra)
        extraValue = deq.back();

    std::deque<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::deque<std::pair<int, int> >::iterator pos = sortedPairs.begin();
        while (pos != sortedPairs.end() && pairs[i].first > (*pos).first)
            ++pos;
        sortedPairs.insert(pos, pairs[i]);
    }

    std::deque<int> mainChain;
    std::deque<int> pendChain;

    for (size_t i = 0; i < sortedPairs.size(); ++i) {
        mainChain.push_back(sortedPairs[i].first);
        pendChain.push_back(sortedPairs[i].second);
    }

    for (size_t i = 0; i < pendChain.size(); ++i) {
        std::deque<int>::iterator pos = mainChain.begin();
        while (pos != mainChain.end() && pendChain[i] > *pos)
            ++pos;
        mainChain.insert(pos, pendChain[i]);
    }

    if (hasExtra) {
        std::deque<int>::iterator pos = mainChain.begin();
        while (pos != mainChain.end() && extraValue > *pos)
            ++pos;
        mainChain.insert(pos, extraValue);
    }

    deq = mainChain;
    return deq;
}

void PmergeMe::sort(int argc, char** argv) {
    if (argc <= 1) {
		std::cerr << "Error: Not enough arguments." << std::endl;
		return;
	}

    for (int i = 1; i < argc; ++i) {
        if (!isValidNumber(argv[i])) {
            std::cerr << "Error: Invalid input" << std::endl;
            return;
        }
		long num = std::atol(argv[i]);
        if (num > INT_MAX) {
            std::cerr << "Error: Number too large" << std::endl;
            return;
        }
        _lst.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
    }

    std::cout << "Before: ";
    printFirstElementsLst(_lst, 4);

    clock_t start = clock();
    _lst = sortList(_lst);
    clock_t end = clock();
	double time_lst = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

    start = clock();
    sortDeque(_deq);
    end = clock();
	double time_deq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "After:  ";
    printFirstElementsLst(_lst, 4);

    std::cout << "Time to process a range of " << _lst.size() 
              << " elements with std::list  : "
              << std::setprecision(5) << time_lst << " us" << std::endl;
    std::cout << "Time to process a range of " << _lst.size() 
              << " elements with std::deque : "
              << std::setprecision(5) << time_deq << " us" << std::endl;
}
