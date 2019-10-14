// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 23:11:17 by istalevs          #+#    #+#             //
//   Updated: 2018/10/13 23:11:18 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Span.hpp"

int	main() {

	Span demo(10);

	demo.addNumber(1);
	demo.addNumber(2);
	demo.addNumber(3);
	demo.addNumber(4);
	demo.addNumber(5);
	demo.addNumber(6);
	demo.addNumber(7);
	demo.addNumber(8);
	demo.addNumber(9);
	demo.addNumber(10);

	std::cout << "Longest Span: " << demo.longestSpan() << std::endl;
	std::cout << "Shortest Span: " << demo.shortestSpan() << std::endl;


	Span demo_2(51);
	try {
		for (int i = 0; i < 1000; i++) {
			demo_2.addNumber(i);
			std::cout << "adding to demo_2: " << i << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
