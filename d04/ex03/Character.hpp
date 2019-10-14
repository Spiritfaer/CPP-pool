#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

class Character: public ICharacter
{
private:
	std::string			_name;
	AMateria			*_materias[4];

public:
	Character(std::string const &name);
	~Character(void);
	Character(Character const &src);

	Character			&operator=(Character const &rhs);

	void				equip(AMateria *materia);
	void				unequip(int idx);
	void				use(int idx, ICharacter const &target);

	std::string const	&getName(void) const;
};

#endif
