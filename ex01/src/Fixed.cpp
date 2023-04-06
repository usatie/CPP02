#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
#if DEBUG
  std::cout << "[ Default constructor called ]" << std::endl;
#endif
}

Fixed::Fixed(const Fixed& x) {
#if DEBUG
  std::cout << "[ Copy constructor called ]" << std::endl;
#endif
  operator=(x);
}

Fixed::Fixed(const int x) {
  value = x << numFractionalBits;
#if DEBUG
  std::cout << "[ Constructor from int called ]" << std::endl;
#endif
}

Fixed::Fixed(const float x) {
  value = roundf(x * (1 << numFractionalBits));
#if DEBUG
  std::cout << "[ Constructor from float called ]" << std::endl;
#endif
}

Fixed& Fixed::operator=(const Fixed& x) {
#if DEBUG
  std::cout << "[ Copy assignment operator called ]" << std::endl;
#endif
  if (this != &x) {
    this->value = x.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {
#if DEBUG
  std::cout << "[ Destructor is called ]" << std::endl;
#endif
}

int Fixed::getRawBits(void) const {
#if DEBUG
  std::cout << "[ getRawBits member function called ]" << std::endl;
#endif
  return value;
}

void Fixed::setRawBits(int const raw) {
#if DEBUG
  std::cout << "[ setRawBits member function called ]" << std::endl;
#endif
  this->value = raw;
}

// 'value >> numFractionalBits' doesn't work when value is small negative number
int Fixed::toInt(void) const { return value / (1 << numFractionalBits); }

float Fixed::toFloat(void) const {
  float result = (float)value / (1 << numFractionalBits);
  return result;
}

std::ostream& operator<<(std::ostream& o, const Fixed& x) {
  o << x.toFloat();
  return o;
}
