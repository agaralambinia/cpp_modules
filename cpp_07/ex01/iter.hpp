#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printValue(const T& value) {
    std::cout << value << " ";
}

template<typename T>
void iter(const T *arr, size_t len, void(*func)(const T&))
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

#endif
