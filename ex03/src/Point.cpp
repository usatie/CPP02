#include "Point.hpp"
#include <iostream>

Point::Point():x(0),y(0) {
	//std::cout << "[ Point Default constructor called ]" << std::endl ;
}

Point::Point(const Fixed & x, const Fixed & y):x(x),y(y) {
	//std::cout << "[ Point constructor called ]" << std::endl ;
}

Point::Point(const Point& p):x(p.x),y(p.y) {
	//std::cout << "[ Point Copy constructor called ]" << std::endl ;
}

Point& Point::operator =(const Point& p) {
	//std::cout << "[ Point Copy assignment operator called ]" << std::endl ;
	if ( this != &p ) {
		// How to modify const member?
		/*
		this->x = p.x ;
		this->y = p.y ;
		*/
	}
	return *this ;
}

Point::~Point() {
	//std::cout << "[ Point destructor is called ]" << std::endl ;
}

// Comparison Operator
bool	Point::operator ==(const Point& p) const {
	return x == p.x && y == p.y ;
}

bool	Point::operator !=(const Point& p) const {
	return !(*this == p) ;
}

// Arithmetic Operator
Point	Point::operator +(const Point& p) const {
	return Point(
			x + p.x,
			y + p.y
	) ;
}

Point	Point::operator -(const Point& p) const {
	return Point(
			x - p.x,
			y - p.y
	) ;
}

Point	Point::operator *(const Fixed& f) const {
	return Point(
			x * f,
			y * f
	) ;
}

Point	Point::operator /(const Fixed& f) const {
	return Point(
			x / f,
			y / f
	) ;
}

const Fixed & Point::getX() const {
	return x ;
}

const Fixed & Point::getY() const {
	return y ;
}

std::ostream& operator <<(std::ostream &o, const Point &p) {
	o << "(" << p.getX() << "," << p.getY() << ")" ;
	return o ;
}
