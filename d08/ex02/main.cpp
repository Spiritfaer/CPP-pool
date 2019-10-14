// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 03:22:40 by istalevs          #+#    #+#             //
//   Updated: 2018/10/13 03:22:40 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <stack>
#include <vector>
#include "mutantstack.hpp"

int main() {

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::it it = mstack.begin();
	MutantStack<int>::it ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << "Iter: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
