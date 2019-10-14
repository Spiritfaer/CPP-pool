// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/04 23:01:40 by istalevs          #+#    #+#             //
//   Updated: 2018/10/04 23:01:41 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "FragTrap.hpp"

int 	main(void)
{
	FragTrap bot_1 = FragTrap("Jack");
	bot_1.rangedAttack("Dude");
	bot_1.meleeAttack("Duck");
	bot_1.takeDamage(29);
	bot_1.takeDamage(29);
	bot_1.takeDamage(29);
	bot_1.takeDamage(29);
	bot_1.beRepaired(50);
	bot_1.beRepaired(50);
	bot_1.beRepaired(100);
	bot_1.vaulthunter_dot_exe("Dron-1000-T");
	bot_1.vaulthunter_dot_exe("Dron-1000-T");
	bot_1.vaulthunter_dot_exe("Dron-1000-T");
	bot_1.vaulthunter_dot_exe("Dron-1000-T");
	bot_1.vaulthunter_dot_exe("Dron-1000-T");
	bot_1.beWait();
	bot_1.beWait();
	bot_1.vaulthunter_dot_exe("Dron-1000-T");
	bot_1.vaulthunter_dot_exe("Dron-1000-T");
	bot_1.vaulthunter_dot_exe("Dron-1000-T");
	return 0;
}
