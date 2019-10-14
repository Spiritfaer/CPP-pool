#ifndef VEC2D_HPP
#define VEC2D_HPP

#include <iostream>

class Vec2D
{
public:
	Vec2D();
	Vec2D(int x, int y);
	Vec2D(Vec2D const & src);
	Vec2D &	operator=(Vec2D const & src);
	~Vec2D();

	Vec2D &	operator++();
	Vec2D &	operator++(int);
	Vec2D &	operator--();
	Vec2D &	operator--(int);

	bool	operator==(Vec2D const & src) const;
	bool	operator!=(Vec2D const & src) const;

	int		_x;
	int		_y;
};

#endif

