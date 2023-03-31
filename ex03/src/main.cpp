#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Fixed.hpp"
#include "Point.hpp"

// print title in green color surrounded by '='
void printTitle(std::string const &title) {
  // set color to green
  std::cout << "\033[1;32m";
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // print title at the center
  std::cout << std::setfill(' ') << std::setw(40 - title.length() / 2) << ""
            << title << std::endl;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << "\033[0m" << std::setfill(' ') << std::setw(0);
}

// Print triangle with points A, B, C, and P.
// This function is written with the help of Copilot.
// https://copilot.github.com/
void printTriangle(const Point a, const Point b, const Point c, const Point p) {
  // get min and max of x and y
  long minX = std::min(std::min(a.getX(), b.getX()), c.getX()).getRawBits() ;
  long maxX = std::max(std::max(a.getX(), b.getX()), c.getX()).getRawBits() ;
  long minY = std::min(std::min(a.getY(), b.getY()), c.getY()).getRawBits() ;
  long maxY = std::max(std::max(a.getY(), b.getY()), c.getY()).getRawBits() ;
  
  // get size of the triangle
  long width = maxX - minX;
  long height = maxY - minY;
  long size = std::max(width, height);

  // convert to 10x10 grid
  int ax = (a.getX().getRawBits() - minX) * 10 / size ;
  int ay = (a.getY().getRawBits() - minY) * 10 / size ;
  int bx = (b.getX().getRawBits() - minX) * 10 / size ;
  int by = (b.getY().getRawBits() - minY) * 10 / size ;
  int cx = (c.getX().getRawBits() - minX) * 10 / size ;
  int cy = (c.getY().getRawBits() - minY) * 10 / size ;
  int px = (p.getX().getRawBits() - minX) * 10 / size ;
  int py = (p.getY().getRawBits() - minY) * 10 / size ;

  // print triangle
  for (int y = 10; y >= 0; y--) {
    for (int x = 0; x <= 10; x++) {
      if (x == ax && y == ay) {
        std::cout << " A";
      } else if (x == bx && y == by) {
        std::cout << " B";
      } else if (x == cx && y == cy) {
        std::cout << " C";
      } else if (x == px && y == py) {
        std::cout << " P";
      // if point is on the edge of the triangle
      } else if (((y - ay) * (bx - ax) == (by - ay) * (x - ax)) && x >= std::min(ax, bx) &&
                 x <= std::max(ax, bx) && y >= std::min(ay, by) && y <= std::max(ay, by)) {
        std::cout << " .";
      } else if (((y - by) * (cx - bx) == (cy - by) * (x - bx)) && x >= std::min(bx, cx) &&
                 x <= std::max(bx, cx) && y >= std::min(by, cy) && y <= std::max(by, cy)) {
        std::cout << " .";
      } else if (((y - cy) * (ax - cx) == (ay - cy) * (x - cx)) && x >= std::min(cx, ax) &&
                 x <= std::max(cx, ax) && y >= std::min(cy, ay) && y <= std::max(cy, ay)) {
        std::cout << " .";
      } else {
        std::cout << "  ";
      }
    }
    std::cout << std::endl;
  }
}

void test(const std::string& info, const Point a, const Point b, const Point c,
          const Point p) {
  printTriangle(a, b, c, p);
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
    printTitle("setRawBits / getRawBits"); 
    std::cout << "a.setRawBits(-1): " << std::endl;
    a.setRawBits(-1);
    std::cout << "a: " << a << std::endl;
    std::cout << "a.toInt(): " << a.toInt() << std::endl;
    std::cout << "a.toFloat(): " << a.toFloat() << std::endl;
    std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;
  }
  {
    Point p;

    printTitle("ZERO TEST");
    test("...", Point(), Point(), Point(), p);
  }
  {
    Point p;

    printTitle("NORMAL TEST");
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

    printTitle("EPSILON TEST");
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
