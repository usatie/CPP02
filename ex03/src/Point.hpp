#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
private:
	const Fixed x ;
	const Fixed y ;
public:
	Point() ;
	Point(const Fixed & x, const Fixed & y) ;
	Point(const float x, const float y) ;
	Point(const Point& p) ;
	Point& operator =(const Point& p) ;
	~Point() ;
	const Fixed & getX() const ;
	const Fixed & getY() const ;
	// Comparison Operator
	bool	operator ==(const Point& x) const ;
	bool	operator !=(const Point& x) const ;
	// Arithmetic Operator
	Point	operator +(const Point& p) const ;
	Point	operator -(const Point& p) const ;
	Point	operator *(const Fixed& f) const ;
	Point	operator /(const Fixed& f) const ;
} ;

std::ostream& operator <<(std::ostream &o, const Point &p) ;
bool	bsp( Point const a, Point const b, Point const c, Point const point ) ;
#endif
