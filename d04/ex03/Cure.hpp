#ifndef CURE_HPP
#define CURE_HPP

# include <string>
# include "ICharacter.hpp"

class Cure: public AMateria
{
public:
	Cure(void);
	~Cure(void);
	Cure(Cure const &src);

	Cure				&operator=(Cure const &rhs);

	AMateria			*clone() const;
	void				use(ICharacter const &target);
};

#endif
