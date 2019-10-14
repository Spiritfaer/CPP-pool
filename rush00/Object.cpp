#include "Object.hpp"
#include "main.hpp"

Object::Object() {
	_pos = Vec2D(0, 0);
	_body = ' ';
}

Object::Object(int y, int x, char c) {
	_pos = Vec2D(x, y);
	_body = c;
}

Object::Object(Object const &other) { *this = other; }
Object &	Object::operator=(Object const & other)
{
	if (this == &other)
		return *this;
	_pos = other._pos;
	_body = other._body;
	return *this;
}

Object::~Object() {}

Vec2D const &	Object::getPos() const { return _pos; }

void			Object::draw(WINDOW *win) const {
	mvwprintw(win, _pos._y, _pos._x, "%c", _body);
}

bool			Object::mvToOneStep(int y, int x)
{
	if (y > 0) {
		if (_pos._y == (PLAY_WINDOW_H - 2))
			return false;
		else
			_pos++;
	}
	if (y < 0) {
		if (_pos._y == 1)
			return false;
		else
			_pos--;
	}
	if (x > 0) {
		if (_pos._x == (PLAY_WINDOW_W - 2))
			return false;
		else
			++_pos;
	}
	if (x < 0) {
		if (_pos._x == 1)
			return false;
		else
			--_pos;
	}
	return true;
}

bool			Object::mvTo(int y, int x)
{
	if (x < 1 || y < 1 || x > PLAY_WINDOW_W - 2 ||  y > PLAY_WINDOW_H - 2)
		return false;
	_pos._y = y;
	_pos._x = x;
	return true;
}
