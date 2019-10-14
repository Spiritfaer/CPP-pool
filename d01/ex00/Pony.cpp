#include "Pony.hpp"

Pony::Pony() : name_("NoNamePony") {
	sayHello();
}

Pony::Pony(std::string const &name) : name_(name) {
	sayHello();
}

Pony::~Pony() {
	std::cout << "Good bye!" << std::endl;
}

void
Pony::setName(std::string const &name) {
	name_ = name;
}

std::string const& Pony::getName() const { return name_; }

void
Pony::sayHello() const {
	std::cout << "Hello! I'm pony! And I'm " << name_ << std::endl;
}

void
Pony::getPain() const {
	std::cout << "You next job been FRONT END!" << std::endl;
}
