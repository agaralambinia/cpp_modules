#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(NULL), _arrSize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arrSize(n)
{
	_arr = new T[n]();
	if (!this->_arr)
		std::cout << "Couldn't allocate memory" << std::endl;
	else
		_arrSize = n;
}

template <typename T>
Array<T>::Array(const Array &a) : _arrSize(a._arrSize)
{
	_arr = new T[_arrSize];
	if (!this->_arr)
		std::cout << "Couldn't allocate memory" << std::endl;
	else
	{
	for (unsigned int i = 0; i < _arrSize; i++)
		_arr[i] = a._arr[i];
		this->_arrSize = a._arrSize;
	}
};

template <typename T>
Array<T> &Array<T>::operator=(const Array &a)
{
	if (this != &a)
	{
		delete[] _arr;
		_arr = new T[_arrSize];
		if (!this->_arr)
			std::cout << "Couldn't allocate memory" << std::endl;
		_arrSize = a._arrSize;
		for (unsigned int i = 0; i < _arrSize; i++)
			_arr[i] = a._arr[i];
	}

	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _arrSize)
		throw std::out_of_range("Index out of bounds");
	return (_arr[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _arrSize)
		throw std::out_of_range("Index out of bounds");
	return (_arr[index]);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (_arrSize);
}
