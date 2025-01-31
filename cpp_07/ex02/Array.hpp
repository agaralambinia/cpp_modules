#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &a);
		Array &operator=(const Array &a);
		~Array();

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		unsigned int size() const;

	private:
		T *_arr;
		unsigned int _arrSize;
};

#include "Array.tpp"

#endif
