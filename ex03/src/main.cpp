#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Fixed.hpp"
#include "Point.hpp"

void test(const std::string& info, const Point a, const Point b, const Point c,
          const Point p) {
  std::cout << std::fixed;
  std::cout  // std::setw(15)
      << info << " : " << p << " in " << a << b << c;
  std::cout.flush();
  std::cout << (bsp(a, b, c, p) ? "\ttrue " : "\tfalse ") << std::endl;
}

#define EPS 0.00390625f
int main(void) {
  {
    Fixed a;
    // setRawBits / getRawBits
    std::cout << "==================== raw bits  ===================="
              << std::endl;
    std::cout << "a.setRawBits(-1): " << std::endl;
    a.setRawBits(-1);
    std::cout << "a: " << a << std::endl;
    std::cout << "a.toInt(): " << a.toInt() << std::endl;
    std::cout << "a.toFloat(): " << a.toFloat() << std::endl;
    std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;
  }
  {
    Point p;

    std::cout << "==================== ZERO TEST ===================="
              << std::endl;
    test("...", Point(), Point(), Point(), p);
  }
  {
    Point p;

    std::cout << "==================== NORMAL TEST ===================="
              << std::endl;
    test("|._\\", Point(0, 1), Point(0, 0), Point(1, 0), p);
    test("/_._\\", Point(0, 1), Point(-1, 0), Point(1, 0), p);
    test(".\\|", Point(0, 1), Point(1, 1), Point(1, 0), p);
    test(".//", Point(-1, -1), Point(1, 1), Point(1, 0), p);

    test("\\./", Point(1, 1), Point(0, -1), Point(-1, 1), p);
    test("<.|", Point(1, 1), Point(-1, 0), Point(1, -1), p);
    test("|.>", Point(-0.125f, -0.125f), Point(0.125f, -0.125f),
         Point(0, 0.125f), p);
    test("/./", Point(-4242, -1), Point(0, 1), Point(4242, 0), p);
  }
  {
    Point p;

    std::cout << "==================== EPSILON TEST ===================="
              << std::endl;
    test("|._\\", Point(0, EPS), Point(0, 0), Point(EPS, 0), p);
    test("/_._\\", Point(0, EPS), Point(-EPS, 0), Point(EPS, 0), p);
    test(".\\|", Point(0, EPS), Point(EPS, EPS), Point(EPS, 0), p);
    test(".//", Point(-EPS, -EPS), Point(EPS, EPS), Point(EPS, 0), p);

    test("\\./", Point(EPS, EPS), Point(0, -EPS), Point(-EPS, EPS), p);
    test("<.|", Point(EPS, EPS), Point(-EPS, 0), Point(EPS, -EPS), p);
    test("|.>", Point(-EPS, -EPS), Point(EPS, -EPS), Point(0, EPS), p);
    test("/./", Point(-4242, -EPS), Point(0, EPS), Point(4242, 0), p);
  }
  return 0;
}
