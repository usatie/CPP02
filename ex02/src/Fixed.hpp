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
	Fixed&	operator =(const Fixed& x) ;
	~Fixed() ;
	int		getRawBits(void) const ;
	void	setRawBits( int const raw ) ;
	float	toFloat( void ) const ;
	int		toInt( void ) const ;
	// Comparison Operator
	bool	operator >(const Fixed& x) const ;
	bool	operator <(const Fixed& x) const ;
	bool	operator >=(const Fixed& x) const ;
	bool	operator <=(const Fixed& x) const ;
	bool	operator ==(const Fixed& x) const ;
	bool	operator !=(const Fixed& x) const ;
	// Arithmetic Operator
	Fixed	operator +(const Fixed& x) const ;
	Fixed	operator -(const Fixed& x) const ;
	Fixed	operator *(const Fixed& x) const ;
	Fixed	operator /(const Fixed& x) const ;
	// Increment/Decrement Operator
	Fixed&	operator ++() ;
	Fixed	operator ++(int) ;
	// Overloaded member function
	static Fixed &min(Fixed & a, Fixed & b) ;
	static const Fixed &min(const Fixed & a, const Fixed & b) ;
	static Fixed &max(Fixed & a, Fixed & b) ;
	static const Fixed &max(const Fixed & a, const Fixed & b) ;
} ;
std::ostream& operator <<(std::ostream &o, const Fixed &x) ;
#endif
