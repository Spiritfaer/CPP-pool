// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 23:31:28 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 23:31:29 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP


#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class NinjaTrap : virtual public ClapTrap {
public:
	NinjaTrap(void);
	NinjaTrap(std::string const & name);
	NinjaTrap(NinjaTrap const & ref);
	virtual ~NinjaTrap(void);

	NinjaTrap & operator=(NinjaTrap const & src);

	void	ninjaShoebox(NinjaTrap const &target) const;
	void	ninjaShoebox(FragTrap const &target) const;
	void	ninjaShoebox(ScavTrap const &target) const;

	void meleeAttack(std::string const & target);

};


#endif
