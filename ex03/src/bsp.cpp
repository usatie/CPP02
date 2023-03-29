#include "Point.hpp"
#include <iostream>

//     b
//    /
//   /
//  O--------> a
Fixed	cross( Point const a, Point const b ) {
	Fixed f = ( a.getX() * b.getY() - a.getY() * b.getX() );
	return ( a.getX() * b.getY() - a.getY() * b.getX() ) ;
}

//     point
//    /
//   /
//  p1-------->p2
bool	side( Point const p1, Point const p2, Point const point) {
	return cross( p2 - p1, point - p1 ) > 0 ;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {
	// 1. pre-validation test with bounding box
	// Get x,y boundaries
	// a-------
	// |......c
	// |......|
	// |......|
	// |_b____|
	Fixed min_x = Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX()) ;
	Fixed max_x = Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX()) ;
	Fixed min_y = Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY()) ;
	Fixed max_y = Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY()) ;

	// On edge is outside
	// Vertex is outside
	if ( min_x >= point.getX()
		|| max_x <= point.getX()
		|| min_y >= point.getY()
		|| max_y <= point.getY() )
		return false ;

	// 2. validation with cross product
	// a-------
	// |......c
	// |..p...|
	// |......|
	// |_b____|
	//
	// If p is inside of the triangle,
	// sign of cross(ab, ap), cross(bc, bp) and cross(ca, cp) must be the same.
	// s1, s2, s3 is the sign of the each cross product
	bool s1 = side(a, b, point) ;
	bool s2 = side(b, c, point) ;
	bool s3 = side(c, a, point) ;
	return (s1 && s2 && s3) || (!s1 && !s2 && !s3) ;
}
