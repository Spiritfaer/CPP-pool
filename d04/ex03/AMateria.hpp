#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
	std::string				_type;
	unsigned int			xp_;

public:
	AMateria(std::string const &type);
	virtual ~AMateria(void);
	AMateria(AMateria const &src);

	AMateria			&operator=(AMateria const &rhs);

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter const &target);

	std::string const	&getType() const;
	unsigned int		getXP() const;
};

#endif
