#include "Enemy.hpp"

Enemy::Enemy() {}
Enemy::~Enemy() {}

Enemy::Enemy(int hp, std::string const &type)
	: _hp(hp), _type(type) {}

std::string const& Enemy::getType() const { return this->_type; }
int Enemy::getHP() const { return this->_hp; }
void Enemy::takeDamage(int damage) {
	if (!getHP())
		return;
	if (getHP() > damage)
		_hp -= damage;
	else
		_hp = 0;
}

void Enemy::setHP(int hp) {
	_hp = hp;
}