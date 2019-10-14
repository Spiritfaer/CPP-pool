// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2019/10/04 17:01:19 by istalevs          #+#    #+#             //
//   Updated: 2019/10/04 17:01:19 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP


#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
private:
	SuperTrap(SuperTrap const & ref);
	SuperTrap & operator=(SuperTrap const & src);

public:
	SuperTrap(void);
	SuperTrap(std::string const & name);
	~SuperTrap(void);

};


#endif
