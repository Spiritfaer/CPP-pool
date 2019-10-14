#include <iostream>
#include <math.h>
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

Fixed::Fixed(const int other) {
	std::cout << "Int constructor called" << std::endl;
	_integer = other << _bits;
}

Fixed::Fixed(const float other) {
	std::cout << "Float constructor called" << std::endl;
	_integer = (int)roundf(other * (1 << _bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &
Fixed::operator=(Fixed const &other) {
	std::cout << "Assignation operator called" << std::endl;
	_integer = other._integer;
	return *this;
}

float
Fixed::toFloat() const {
	return ((float)_integer) / (1u << _bits);
}

int
Fixed::toInt() const {
	return _integer >> _bits;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed) {
	os << fixed.toFloat();
	return os;
}
