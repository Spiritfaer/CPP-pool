#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	int					_materia_count;
	AMateria			*_materias[4];

public:
	MateriaSource(void);
	~MateriaSource(void);
	MateriaSource(MateriaSource const &src);

	MateriaSource		&operator=(MateriaSource const &rhs);

	void				learnMateria(AMateria *materia);
	AMateria			*createMateria(std::string const &type);
};

#endif
