#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {}

	virtual void				equip(AMateria *materia) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter const &target) = 0;

	virtual std::string const	&getName(void) const = 0;
};

#endif
