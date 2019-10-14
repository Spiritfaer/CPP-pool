// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 23:10:57 by istalevs          #+#    #+#             //
//   Updated: 2018/10/13 23:10:58 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int size):
		_size(size) {
	_arr.reserve(size);
}

Span::Span(Span const& ref) {
	*this = ref;
}

Span& Span::operator=(Span const& ref) {
	_arr = ref._arr;
	return *this;
}

Span::~Span() {}

void 		 Span::addNumber(int n) {

	if (_arr.size() < _size) {
		_arr.push_back(n);
	} else {
		throw std::length_error("Error: containers ended");
	}

}

unsigned int Span::shortestSpan() {

	int min = INT_MAX;
	int diff;
	std::vector<int>		   tmp = _arr;
	std::vector<int>::iterator it =  tmp.begin();
	std::vector<int>::iterator it2 = it + 1;
	std::vector<int>::iterator end = tmp.end();

	if (tmp.size() > 1) {
		std::sort(tmp.begin(), tmp.end());
		for (; it2 != end; it++, it2++) {
			diff = abs(*it - *it2);
			if (diff > 0 && diff < min) {
				min = diff;
			}
		}
	} else {
		throw std::logic_error("Error: container is too small");
	}

	if (min == INT_MAX) {
		return 0;
	} else {
		return min;
	}
}

unsigned int Span::longestSpan() {

	int max;
	int min;

	if (_arr.size() > 1) {
		max = *std::max_element(_arr.begin(), _arr.end());
		min = *std::min_element(_arr.begin(), _arr.end());
	} else {
		throw std::logic_error("Error: container is too small");
	}
	return (max - min);
}
