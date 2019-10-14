#include "Human.hpp"

void
Human::meleeAttack(std::string const &target) {
	std::cout << "Human make melee attack " << target << std::endl;
}

void
Human::rangedAttack(std::string const &target) {
	std::cout << "Human make range attack " << target << std::endl;
}

void
Human::intimidatingShout(std::string const &target) {
	std::cout << "Human make intimidating shout " << target << std::endl;
}

void
Human::action(std::string const &action_name, std::string const &target) {
	void(Human::*job[])(std::string const &target) = {
			&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout
	};
	std::string attacks[] = { "meleeAttack", "rangedAttack", "intimidatingShout" };
	for (size_t i = 0; i < 3; ++i) {
		if (action_name == attacks[i])
			(this->*job[i])(target);
	}
}
