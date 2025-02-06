#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
private:
	std::stack<long> _stack;
	void stackClear(std::stack<long> *_stack);
	bool isOperator(char c);
	long parseNumber(const std::string& expr, long& pos);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

	long Calculate(long argc, char** argv);
};

#endif
