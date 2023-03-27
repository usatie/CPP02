#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed {
private:
	int value ;
	static const int numFractionalBits = 8 ;
public:
	Fixed() ;
	Fixed(const Fixed& x) ;
	Fixed(const int x) ;
	Fixed(const float x) ;
	Fixed& operator =(const Fixed& x) ;
	~Fixed() ;
	int		getRawBits(void) const ;
	void	setRawBits( int const raw ) ;
	float	toFloat( void ) const ;
	int		toInt( void ) const ;
} ;
std::ostream& operator <<(std::ostream &o, const Fixed &x) ;
#endif
