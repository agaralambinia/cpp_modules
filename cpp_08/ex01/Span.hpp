#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
private:
	unsigned int		_N;
	std::vector<int>	_tab;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void	addNumber(long long n);
	long	shortestSpan();
	long	longestSpan();
	void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	class SizeMaxException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class SmallTabException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class MaxIntException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif
