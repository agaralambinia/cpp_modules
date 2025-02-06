#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::stackClear(std::stack<long> *_stack) {
	while (!_stack->empty()) {
		_stack->pop();
	}
}

bool RPN::isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

long RPN::parseNumber(const std::string& expr, long& pos) {
	long num = 0;
	int sign = 1;

	if (expr[pos] == '-') {
		sign = -1;
		pos++;
	}

	while (pos < static_cast<long>(expr.length()) && std::isdigit(expr[pos])) {
		num = num * 10 + (expr[pos] - '0');
		pos++;
	}
	return num * sign;
}

long RPN::Calculate(long argc, char** argv) {
	stackClear(&_stack);

	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::string expr(argv[1]);
	long pos = -1;

	if (static_cast<long>(expr.length()) > std::numeric_limits<int>::max()) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	while (++pos < static_cast<long>(expr.length())) {
		if (!_stack.empty() && (_stack.top() > std::numeric_limits<int>::max() || _stack.top() < std::numeric_limits<int>::min())) {
			std::cerr << "Error" << std::endl;
			stackClear(&_stack);
			return 1;
		}
		if (std::isspace(expr[pos])) {
			continue;
		}

		if (std::isdigit(expr[pos]) || (static_cast<long>(expr.length()) - 1 > pos && expr[pos] == '-' && std::isdigit(expr[pos+1]))) {
			if (_stack.empty() || std::isspace(expr[pos - 1])) {
				long num = parseNumber(expr, pos); 
				_stack.push(num);
			}
			else {
				std::cerr << "Error" << std::endl;
				stackClear(&_stack);
				return 1;
			}
		}
		else if (isOperator(expr[pos])) {
			if (_stack.size() < 2 || !std::isspace(expr[pos - 1])) {
				std::cerr << "Error" << std::endl;
				stackClear(&_stack);
				return 1;
			}
			long b = _stack.top(); 
			_stack.pop();
			long a = _stack.top(); 
			_stack.pop();

			switch (expr[pos]) {
				case '+': _stack.push(a + b); break;
				case '-': _stack.push(a - b); break;
				case '*': _stack.push(a * b); break;
				case '/': 
					if (b == 0) {
						std::cerr << "Error" << std::endl;
						stackClear(&_stack);
						return 1;
					}
					_stack.push(a / b); break;
			}
		}
		else {
			std::cerr << "Error" << std::endl;
			stackClear(&_stack);
			return 1;
		}
	}
	if (_stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		stackClear(&_stack);
		return 1;
	}
	if (_stack.top() > std::numeric_limits<int>::max() || _stack.top() < std::numeric_limits<int>::min()) {
		std::cerr << "Error" << std::endl;
		stackClear(&_stack);
		return 1;
	}
	std::cout << _stack.top() << std::endl;
	stackClear(&_stack);
	return 0;
}
