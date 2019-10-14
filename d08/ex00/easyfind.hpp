#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
void easyfind(T &src, int integer) {
	if (src.empty())
		throw std::logic_error("Container is empty!");

	for (typename T::const_iterator itr = src.begin(); itr != src.end(); ++itr) {
		if (*itr == integer) {
			std::cout << "Element was found! data[" << itr - src.begin() << "]" << std::endl;
			return;
		}
	}
	throw std::logic_error("Element not found");
}

#endif
