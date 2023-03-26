#include "Fixed.hpp"
#include <iostream>

const int Fixed::numFractionalBits = 8 ;

Fixed::Fixed():value(0) {
	std::cout << "[ Fixed Default constructor called ]" << std::endl ;
}

Fixed::Fixed(const Fixed& x):value(x.value) {
	std::cout << "[ Fixed Copy constructor called ]" << std::endl ;
}

Fixed& Fixed::operator =(const Fixed& x) {
	std::cout << "[ Fixed Copy assignment operator called ]" << std::endl ;
	this->value = x.value ;
	return *this ;
}

Fixed::~Fixed() {
	std::cout << "[ Fixed destructor is called ]" << std::endl ;
}

int		Fixed::getRawBits(void) const {
	return value ;
}

void	Fixed::setRawBits( int const raw ) {
	this->value = raw ;
}
