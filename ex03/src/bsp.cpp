#include <iostream>

#include "Point.hpp"

//     b
//    /
//   /
//  O--------> a
Fixed cross(Point const a, Point const b) {
  Fixed f = (a.getX() * b.getY() - a.getY() * b.getX());
  return (a.getX() * b.getY() - a.getY() * b.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  // 1. pre-validation test with bounding box
  // Get x,y boundaries
  // a-------
  // |......c
  // |......|
  // |......|
  // |_b____|
  Fixed min_x = Fixed::min(Fixed::min(a.getX(), b.getX()), c.getX());
  Fixed max_x = Fixed::max(Fixed::max(a.getX(), b.getX()), c.getX());
  Fixed min_y = Fixed::min(Fixed::min(a.getY(), b.getY()), c.getY());
  Fixed max_y = Fixed::max(Fixed::max(a.getY(), b.getY()), c.getY());

  // On edge is outside
  // Vertex is outside
  if (min_x >= point.getX() || max_x <= point.getX() || min_y >= point.getY() ||
      max_y <= point.getY())
    return false;

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
  Fixed cross_ab_ap = cross(b - a, point - a);
  Fixed cross_bc_bp = cross(c - b, point - b);
  Fixed cross_ca_cp = cross(a - c, point - c);

  if (cross_ab_ap == 0 || cross_bc_bp == 0 || cross_ca_cp == 0) return false;

  bool s1 = cross_ab_ap > 0;
  bool s2 = cross_bc_bp > 0;
  bool s3 = cross_ca_cp > 0;
  return (s1 && s2 && s3) || (!s1 && !s2 && !s3);
}
