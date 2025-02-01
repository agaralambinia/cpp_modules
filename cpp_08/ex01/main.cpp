#include "Span.hpp"

#define BLUE	"\033[34;1m"
#define RESET	"\033[0m"

int main()
{
	std::cout << BLUE"SIMPLE TESTS"RESET << std::endl;
	try {
		Span s = Span(4);
		s.addNumber(1);
		s.addNumber(100);
		std::cout << BLUE"span (1, 100)"RESET << std::endl;
		std::cout << "LongestSpan: " << s.longestSpan() << std::endl;
		std::cout << "ShortestSpan: " << s.shortestSpan() << std::endl;
		s.addNumber(30);
		std::cout << BLUE"added 30"RESET << std::endl;
		std::cout << "LongestSpan: " << s.longestSpan() << std::endl;
		std::cout << "ShortestSpan: " << s.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE"CATCHING OVERFLOWS"RESET << std::endl;
	try {
		Span s = Span(4);
		s.addNumber(1);
		s.addNumber(100);
		s.addNumber(30);
		s.addNumber(1);
		s.addNumber(0);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Span s = Span(4);
		s.addNumber(2147483648);
		s.addNumber(-2147483649);
		std::cout << "LongestSpan: " << s.longestSpan() << std::endl;
		std::cout << "ShortestSpan: " << s.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE"CATCHING BORDER CASES"RESET << std::endl;
	try {
		Span s = Span(4);
		s.addNumber(2147483647);
		s.addNumber(-2147483648);
		std::cout << "LongestSpan: " << s.longestSpan() << std::endl;
		std::cout << "ShortestSpan: " << s.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE"CATCHING 1 ELEMENT EXCEPTION"RESET << std::endl;
	try {
		Span s = Span(4);
		s.addNumber(2147483647);
		std::cout << "ShortestSpan: " << s.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << s.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << BLUE"STRESS TESTING"RESET << std::endl;
	try
	{
		Span s = Span(100000);
		std::vector<int> v;
		for (int i = 100000; i > 1; i--)
		{
			v.push_back(i);
		}
		s.addNumber(v.begin(), v.end());
		std::cout << "ShortestSpan: " << s.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << s.longestSpan() << std::endl;
		}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Span s = Span(100000);
		std::vector<int> v;
		for (int i = 200000; i > 1; i--)
		{
			v.push_back(i);
		}
		s.addNumber(v.begin(), v.end());
		std::cout << "ShortestSpan: " << s.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << s.longestSpan() << std::endl;
		}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}