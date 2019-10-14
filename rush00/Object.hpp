#ifndef OBJECT_HPP
# define OBJECT_HPP

# include "Vec2D.hpp"
# include <ncurses.h>

class Object
{
public:
	Object();
	Object(int, int, char);
	Object(Object const &);
	Object&	operator=(Object const &);
	virtual ~Object();

	Vec2D const&	getPos() const;
	bool			mvTo(int x, int y);
	bool			mvToOneStep(int y, int x);

	void			draw(WINDOW *win) const;

protected:
	Vec2D			_pos;
	char			_body;
};

#endif
