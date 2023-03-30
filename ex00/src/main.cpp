#include <iostream>

#include "Fixed.hpp"

// print title in green and highlighted
void printTitle(const std::string& title) {
  std::cout << "\033[1;32m" << title << "\033[0m" << std::endl;
}

int main(void) {
  // tests from subject pdf
  {
    printTitle("Tests from subject pdf");
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
  }
  // tests setRawBits
  {
    printTitle("Tests setRawBits");
    Fixed a;

    a.setRawBits(1);
    std::cout << a.getRawBits() << std::endl;
    a.setRawBits(-1);
    std::cout << a.getRawBits() << std::endl;
  }
  return 0;
}
