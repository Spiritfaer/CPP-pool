// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/05 23:10:52 by istalevs          #+#    #+#             //
//   Updated: 2018/10/05 23:10:53 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int 	main(void)
{
	FragTrap bot_1 = FragTrap("Jack");
	ScavTrap bot_2 = ScavTrap("Golum");
	NinjaTrap bot_3 = NinjaTrap();

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
	std::cout << "-------------------------------" << std::endl;
	bot_2.challengeNewcomer("Jack");
	bot_2.challengeNewcomer("Jack");
	bot_2.challengeNewcomer("Jack");
	bot_2.challengeNewcomer("Jack");
	bot_2.rangedAttack("Dude");
	bot_2.meleeAttack("Duck");
	bot_2.takeDamage(29);
	bot_2.takeDamage(29);
	bot_2.takeDamage(29);
	bot_2.takeDamage(29);
	bot_2.beRepaired(50);
	bot_2.beRepaired(50);
	bot_2.beRepaired(100);
	bot_2.beWait();
	bot_2.beWait();
	std::cout << "-------------------------------" << std::endl;
	bot_3.ninjaShoebox(bot_1);
	bot_3.ninjaShoebox(bot_2);

	return 0;
}
