#ifndef ICE_HPP
#define ICE_HPP

class Ice: public AMateria
{
public:
	Ice(void);
	~Ice(void);
	Ice(Ice const &src);

	Ice					&operator=(Ice const &rhs);

	AMateria			*clone() const;
	void				use(ICharacter const &target);
};


#endif
