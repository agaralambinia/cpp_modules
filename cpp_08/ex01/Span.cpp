#include "Span.hpp"
#include <climits>
#include <iterator>
#include <vector>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) {
	if (N > INT_MAX)
		throw SizeMaxException();
	else
		this->_N = N;
}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->_N = other._N;
		this->_tab = other._tab;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(long long n)
{
	if (n < INT_MIN || n > INT_MAX)
		throw MaxIntException();
	if (_tab.size() >= _N)
		throw SizeMaxException();
	_tab.push_back(static_cast<int>(n));
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_N < _tab.size() + std::distance(begin, end))
		throw SizeMaxException();
	if (*std::max_element(begin, end) > INT_MAX)
		throw MaxIntException();
	if (*std::min_element(begin, end) < INT_MIN)
		throw MaxIntException();
	_tab.insert(_tab.end(), begin, end);
}

long	Span::shortestSpan()
{
	if (_tab.size() <= 1)
		throw SmallTabException();
	std::vector<int> tmp =_tab;
	std::sort(tmp.begin(), tmp.end());
	long min = static_cast<long>(tmp[1]) - static_cast<long>(tmp[0]);
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]) < min)
			min = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
	}
	return (min);
}

long	Span::longestSpan()
{
	if (_tab.size() <= 1)
		throw SmallTabException();
	std::vector<int> tmp =_tab;
	std::sort(tmp.begin(), tmp.end());
	return (static_cast<long>(tmp[tmp.size() - 1]) - static_cast<long>(tmp[0]));
}

const char *Span::SizeMaxException::what() const throw()
{
	return ("Container is full");
}

const char *Span::SmallTabException::what() const throw()
{
	return ("Not enough numbers in container");
}

const char *Span::MaxIntException::what() const throw()
{
	return ("Element Int overflow");
}
