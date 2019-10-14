#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed {
public:

	Fixed();
	Fixed(const int);
	Fixed(const float);
	~Fixed();

	Fixed(Fixed const &);
	Fixed &operator=(Fixed const &);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	bool	operator>(Fixed const &) const;
	bool	operator<(Fixed const &) const;
	bool	operator>=(Fixed const &) const;
	bool	operator<=(Fixed const &) const;
	bool	operator==(Fixed const &) const;
	bool	operator!=(Fixed const &) const;

	Fixed   operator+(Fixed const&) const;
	Fixed   operator-(Fixed const&) const;
	Fixed   operator*(Fixed const&) const;
	Fixed   operator/(Fixed const&) const;

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);


	static Fixed &max(Fixed &, Fixed &);
	static Fixed &min(Fixed &, Fixed &);
	static Fixed const &max(Fixed const &, Fixed const &);
	static Fixed const &min(Fixed const &, Fixed const &);

private:
	static int const	_bits;
	int					_integer;

};

std::ostream &operator<<(std::ostream &, Fixed const &);

#endif
