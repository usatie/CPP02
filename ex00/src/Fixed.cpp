#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : value(0) {
  std::cout << "[ Default constructor called ]" << std::endl;
}

Fixed::Fixed(const Fixed& x) {
  std::cout << "[ Copy constructor called ]" << std::endl;
  operator=(x);
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
