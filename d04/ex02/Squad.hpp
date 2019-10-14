#ifndef SQUAD_HPP
#define SQUAD_HPP
#include <string>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"


class Squad : public ISquad {
private:
	int				_count;
	int				_max_count;
	ISpaceMarine	*_marinePtr[32];
public:

	Squad();
	~Squad();
	Squad(Squad const&);
	Squad &operator=(Squad const&);

	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);
};


#endif
