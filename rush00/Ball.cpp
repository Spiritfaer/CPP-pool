#include "Ball.hpp"
#include "main.hpp"

Ball::Ball() : Object(1, 1, BALL_CHAR) {}
Ball::Ball(int y, int x) : Object(y, x, BALL_CHAR) {}
Ball::Ball(int y, int x, char c) : Object(y, x, c) {}
Ball::Ball(Ball const & src) { this->_pos = src._pos; this->_body = src._body; }
Ball::~Ball() {}
