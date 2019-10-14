#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed {
public:

	Fixed();
	~Fixed();

	Fixed(Fixed const &);
	Fixed &operator=(Fixed const &);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	static int const	_bits;
	int					_integer;

};

#endif
