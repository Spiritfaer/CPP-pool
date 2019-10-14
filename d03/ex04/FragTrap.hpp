// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 23:10:38 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 23:10:41 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:
	FragTrap(void);
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & ref);
	virtual ~FragTrap(void);

	FragTrap & operator=(FragTrap const & src);

	void vaulthunter_dot_exe(std::string const & target);

	void rangedAttack(std::string const & target);
};

#endif
