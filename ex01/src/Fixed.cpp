#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
  std::cout << "[ Default constructor called ]" << std::endl;
}

Fixed::Fixed(const Fixed& x) {
  std::cout << "[ Copy constructor called ]" << std::endl;
  operator=(x);
}

Fixed::Fixed(const int x) {
  value = x << numFractionalBits;
  std::cout << "[ Constructor from int called ]" << std::endl;
}

Fixed::Fixed(const float x) {
  value = roundf(x * (1 << numFractionalBits));
  std::cout << "[ Constructor from float called ]" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& x) {
  std::cout << "[ Copy assignment operator called ]" << std::endl;
  if (this != &x) {
    this->value = x.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "[ Destructor is called ]" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "[ getRawBits member function called ]" << std::endl;
  return value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "[ setRawBits member function called ]" << std::endl;
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
