#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename  T::iterator easyfind(T &container, int to_find) {
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw std::runtime_error("Integer not found!");
	return (it);
}

template <typename T>
typename  T::const_iterator easyfind(const T &container, int to_find) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw std::runtime_error("Integer not found!");
	return (it);
}

#endif
