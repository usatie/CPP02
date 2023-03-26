#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
private:
	int value ;
	static const int numFractionalBits ;
public:
	Fixed() ;
	Fixed(const Fixed& x) ;
	Fixed& operator =(const Fixed& x) ;
	~Fixed() ;
	int		getRawBits(void) const ;
	void	setRawBits( int const raw ) ;
} ;
#endif
