#include "Vec2D.hpp"

Vec2D::Vec2D() : _x(0), _y(0) {}
Vec2D::Vec2D(int x, int y) : _x(x), _y(y) {}
Vec2D::Vec2D(Vec2D const & src) { *this = src; }

Vec2D &	Vec2D::operator=(Vec2D const & src)
{

	if (this == &src)
		return *this;
	_x = src._x;
	_y = src._y;
	return *this;
}

Vec2D::~Vec2D() {}
Vec2D &	Vec2D::operator++() { _x++;	return *this; }
Vec2D &	Vec2D::operator++(int) { _y++; return *this; }
Vec2D &	Vec2D::operator--() { _x--;	return *this; }
Vec2D &	Vec2D::operator--(int) { _y--; return *this; }
bool	Vec2D::operator==(Vec2D const & src) const { return _x == src._x && _y == src._y; }
bool	Vec2D::operator!=(Vec2D const & src) const { return !(*this == src); }
