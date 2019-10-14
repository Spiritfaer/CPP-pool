#ifndef BULLET_HPP
#define BULLET_HPP

#include "Object.hpp"

class Ball : public Object
{
public:
	Ball();
	Ball(int y, int x);
	Ball(int y, int x, char c);
	Ball(Ball const & src);
	virtual ~Ball();
private:
	Ball&	operator=(Ball const & src);
};

#endif
