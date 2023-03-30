#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
  std::cout << "[ Fixed Default constructor called ]" << std::endl;
}

Fixed::Fixed(const Fixed& x) : value(x.value) {
  std::cout << "[ Fixed Copy constructor called ]" << std::endl;
}

Fixed::Fixed(const int x) {
  value = x << numFractionalBits;
  std::cout << "[ Fixed Copy constructor called ]" << std::endl;
}

Fixed::Fixed(const float x) {
  value = roundf(x * (1 << numFractionalBits));
  std::cout << "[ Fixed Copy constructor called ]" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& x) {
  std::cout << "[ Fixed Copy assignment operator called ]" << std::endl;
  if (this != &x) {
    this->value = x.value;
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "[ Fixed destructor is called ]" << std::endl; }

int Fixed::getRawBits(void) const { return value; }

void Fixed::setRawBits(int const raw) { this->value = raw; }

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
