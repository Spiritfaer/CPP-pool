// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 23:29:29 by istalevs          #+#    #+#             //
//   Updated: 2018/10/13 23:29:31 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <stack>
#include <vector>
#include <list>

template<typename T>
class MutantStack : public std::stack<T> {

private:
	std::vector<T> 		 _vector;

public:

	MutantStack() {};
	MutantStack(MutantStack const& ref) { *this = ref; };
	MutantStack& operator=(MutantStack const& ref) { this->_vector = ref._vector; return *this; };
	~MutantStack() {};

	typedef typename std::vector<T>::iterator it;
	it begin() { return _vector.begin(); }
	it end(){	return _vector.end(); }

	void	push(T x) {	this->_vector.push_back(x); }
	void	pop() { _vector.pop_back(); }
	T		top() { return *(_vector.end() - 1); }
};

#endif
