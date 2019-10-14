// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 23:11:05 by istalevs          #+#    #+#             //
//   Updated: 2018/10/13 23:11:06 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPAN_HPP
#define SPAN_HPP

#include <limits>
#include <iostream>
#include <vector>
#include <stdexcept>

class Span {

private:

	unsigned int     _size;
	std::vector<int> _arr;

public:

	Span();
	Span(unsigned int size);
	Span(Span const& ref);
	Span& operator=(Span const& ref);
	~Span();

	void 		 addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif
