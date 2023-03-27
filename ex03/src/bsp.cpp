#include "Point.hpp"
#include <iostream>
#define FIXED_EPSILON 0.00390625f

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	// Inside if point is (a | b | c)
	if ( a == point || b == point || c == point )
		return true ;

	// Get x,y boundaries
	Fixed min_x = Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX()) ;
	Fixed max_x = Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX()) ;
	Fixed min_y = Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY()) ;
	Fixed max_y = Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY()) ;

	// Out of boundaries
	if ( min_x > point.getX()
		|| max_x < point.getX()
		|| min_y > point.getY()
		|| max_y < point.getY() )
		return false ;

	// Within small boundaries, but not (a | b | c)
	// Case like this
	// a.-.b
	//  |/  
	// c. .p
	if ( (max_x - min_x) <= FIXED_EPSILON && (max_y - min_y) <= FIXED_EPSILON )
		return false ;

	// Paritioning the space
	Point center = (a + b + c) / 3 ;

	// Avoid infinite loop by comparing w/ center
	if ( c != center && bsp(a, b, center, point) )
		return true ;
	if ( b != center && bsp(a, center, c, point) )
		return true ;
	if ( a != center && bsp(center, b, c, point) )
		return true ;
	return false ;
}
