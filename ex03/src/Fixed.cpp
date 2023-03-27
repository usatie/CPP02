#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed():value(0) {
	//std::cout << "[ Fixed Default constructor called ]" << std::endl ;
}

Fixed::Fixed(const Fixed& x):value(x.value) {
	//std::cout << "[ Fixed Copy constructor called ]" << std::endl ;
}

Fixed::Fixed(const int x) {
	value = x << numFractionalBits ;
	//std::cout << "[ Fixed Copy constructor called ]" << std::endl ;
}

Fixed::Fixed(const float x) {
	value = roundf(x * (1 << numFractionalBits)) ;
	//std::cout << "[ Fixed Copy constructor called ]" << std::endl ;
}

Fixed& Fixed::operator =(const Fixed& x) {
	//std::cout << "[ Fixed Copy assignment operator called ]" << std::endl ;
	if ( this != &x ) {
		this->value = x.value ;
	}
	return *this ;
}

Fixed::~Fixed() {
	//std::cout << "[ Fixed destructor is called ]" << std::endl ;
}

int		Fixed::getRawBits(void) const {
	return value ;
}

void	Fixed::setRawBits( int const raw ) {
	this->value = raw ;
}

int	Fixed::toInt(void) const {
	return value >> numFractionalBits ;
}

float	Fixed::toFloat(void) const {
	float result = (float)value / (1 << numFractionalBits) ;
	return result ;
}

std::ostream& operator <<(std::ostream &o, const Fixed &x) {
	o << x.toFloat() ;
	return o ;
}

// Comparison Operator
bool	Fixed::operator >(const Fixed& x) const { return value > x.value ; }
bool	Fixed::operator <(const Fixed& x) const { return value < x.value ; }
bool	Fixed::operator >=(const Fixed& x) const { return value >= x.value ; }
bool	Fixed::operator <=(const Fixed& x) const { return value <= x.value ; }
bool	Fixed::operator ==(const Fixed& x) const { return value == x.value ; }
bool	Fixed::operator !=(const Fixed& x) const { return value != x.value ; }

// Arithmetic Operator
Fixed	Fixed::operator +(const Fixed& x) const {
	Fixed result ;
	result.value = this->value + x.value ;
	return result ;
}

Fixed	Fixed::operator -(const Fixed& x) const {
	Fixed result ;
	result.value = this->value - x.value ;
	return result ;
}

// Simplest form : 
// (x * y) >> numFractionalBits
Fixed	Fixed::operator *(const Fixed& x) const {
	Fixed result ;
	result.value = ((long long)value * (long long)x.value) >> numFractionalBits ;
	return result ;
}

// Simplest form : 
// (x / y) << numFractionalBits
Fixed	Fixed::operator /(const Fixed& x) const {
	Fixed result ;
	if ( 0 != (value << numFractionalBits) ) {
		result.value = ((value << numFractionalBits) / x.value) ;
	}
	else {
		result.value = (value / x.value) << numFractionalBits ;
	}
	return result ;
}

// Increment/Decrement Operator
Fixed&	Fixed::operator ++() {
	++value ;
	return *this ;
}

Fixed	Fixed::operator ++(int) {
	Fixed temp = *this ;
	++value ;
	return temp ;
}

// Overloaded
Fixed & Fixed::min(Fixed & a, Fixed & b) {
	if ( a < b )
		return a ;
	return b ;
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b) {
	if ( a < b )
		return a ;
	return b ;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
	if ( a > b )
		return a ;
	return b ;
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b) {
	if ( a > b )
		return a ;
	return b ;
}
