#include <iostream>
#include <math.h>
#include "Fixed.hpp"

int const Fixed::_bits = 8;

int
Fixed::getRawBits() const {
	return _integer;
}

void
Fixed::setRawBits(int const raw) {
	_integer = raw;
}

Fixed::Fixed() : _integer(0){
}

Fixed::Fixed(const int other) {
	_integer = other << _bits;
}

Fixed::Fixed(const float other) {
	_integer = (int)roundf(other * (1u << _bits));
}

Fixed::~Fixed() {
}

Fixed::Fixed(Fixed const &other) {
	this->_integer = other._integer;
}

Fixed &
Fixed::operator=(Fixed const &other) {
	if (this != &other) {
		_integer = other._integer;
	}
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

bool
Fixed::operator>(Fixed const &other) const {
	return this->toFloat() > other.toFloat();
}

bool
Fixed::operator<(Fixed const &other) const {
	return !(*this > other);
}

bool
Fixed::operator>=(Fixed const &other) const {
	return !(*this < other);
}

bool
Fixed::operator<=(Fixed const &other) const {
	return !(*this > other);
}

bool
Fixed::operator==(Fixed const &other) const {
	return this->toFloat() == other.toFloat();
}

bool
Fixed::operator!=(Fixed const &other) const {
	return !(*this == other);
}

Fixed
Fixed::operator+(Fixed const &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed
Fixed::operator-(Fixed const &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed
Fixed::operator*(Fixed const &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed
Fixed::operator/(Fixed const &other) const {
	if (other.toFloat() == 0.0f)
		return Fixed(0.0f);
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed&
Fixed::operator++() {
	this->_integer += 1;
	return *this;
}

Fixed
Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_integer += 1;
	return tmp;
}

Fixed&
Fixed::operator--() {
	this->_integer -= 1;
	return *this;
}

Fixed
Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_integer -= 1;
	return tmp;
}

Fixed&
Fixed::max(Fixed &one, Fixed &two) {
	if (one > two)
		return one;
	return two;
}

Fixed&
Fixed::min(Fixed &one, Fixed &two) {
	if (one < two)
		return one;
	return two;
}

Fixed const&
Fixed::max(Fixed const &one, Fixed const &two) {
	if (one > two)
		return one;
	return two;
}

Fixed const&
Fixed::min(Fixed const &one, Fixed const &two) {
	if(one < two)
		return one;
	return two;
}
