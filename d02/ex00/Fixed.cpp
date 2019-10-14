#include <iostream>
#include "Fixed.hpp"

int const Fixed::_bits = 8;

int
Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _integer;
}

void
Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_integer = raw;
}

Fixed::Fixed() : _integer(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
	else
		_integer = 0;
}

Fixed &
Fixed::operator=(Fixed const &other) {
	std::cout << "Assignation operator called" << std::endl;
	_integer = other.getRawBits();
	return *this;
}
