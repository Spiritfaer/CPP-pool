#include "Squad.hpp"

Squad::Squad() {
	_count = 0;
	_max_count = 32;
}
Squad::~Squad() {
	for (int i = 0; i < _max_count; ++i) {
		delete _marinePtr[i];
	}
}
Squad& Squad::operator=(Squad const &other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < _max_count; ++i) {
		delete _marinePtr[i];
		_marinePtr[i] = other.getUnit(i)->clone();
	}
	_count = other._count;
	_max_count = other._max_count;
	return *this;
}

Squad::Squad(Squad const &other) {
	*this = other;
}

int Squad::getCount() const { return this->_count; }

ISpaceMarine* Squad::getUnit(int index) const {
	if (index >= 0 && index < _max_count)
		return _marinePtr[index];
	return nullptr;
}

int Squad::push(ISpaceMarine *marine) {
	if (!marine || _count == _max_count)
		return _count;
	for (int i = 0; i < _count; ++i) {
		if (_marinePtr[i] == marine)
			return _count;
	}
	_marinePtr[_count++] = marine;
	return _count;
}
