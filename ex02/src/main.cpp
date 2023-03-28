#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int main( void ) {
	// Tests from subject's pdf
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << a / Fixed(0.5f) << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	// My tests
	std::cout << "-------------------------- My tests --------------------------" << std::endl ;
	{
		Fixed a;
		Fixed b( 1 ) ;
		const Fixed c( 0.1f ) ;
		const Fixed d( 0.01f ) ;
		std::cout << "a: " << a << std::endl ;
		std::cout << "b: " << b << std::endl ;
		std::cout << "c: " << c << std::endl ;
		std::cout << "d: " << d << std::endl ;
		// Comparison Operator
		std::cout << "==================== Comparison Operator ====================" << std::endl ;
		std::cout << "a < b" << std::endl ;
		std::cout << std::boolalpha << (a < b) << std::endl;
		std::cout << "a > b" << std::endl ;
		std::cout << std::boolalpha << (a > b) << std::endl;
		std::cout << "a <= b" << std::endl ;
		std::cout << std::boolalpha << (a <= b) << std::endl;
		std::cout << "a >= b" << std::endl ;
		std::cout << std::boolalpha << (a >= b) << std::endl;
		std::cout << "a == b" << std::endl ;
		std::cout << std::boolalpha << (a == b) << std::endl;
		std::cout << "a != b" << std::endl ;
		std::cout << std::boolalpha << (a != b) << std::endl;
		std::cout << "c < d" << std::endl ;
		std::cout << std::boolalpha << (c < d) << std::endl;
		std::cout << "c > d" << std::endl ;
		std::cout << std::boolalpha << (c > d) << std::endl;
		std::cout << "c <= d" << std::endl ;
		std::cout << std::boolalpha << (c <= d) << std::endl;
		std::cout << "c >= d" << std::endl ;
		std::cout << std::boolalpha << (c >= d) << std::endl;
		std::cout << "c == d" << std::endl ;
		std::cout << std::boolalpha << (c == d) << std::endl;
		std::cout << "c != d" << std::endl ;
		std::cout << std::boolalpha << (c != d) << std::endl;
		// Arithmetic Operation
		std::cout << "==================== Arithmetic Operator ====================" << std::endl ;
		std::cout << "a + b" << std::endl ;
		std::cout << a + b << std::endl;
		std::cout << "a - b" << std::endl ;
		std::cout << a - b << std::endl;
		std::cout << "a * b" << std::endl ;
		std::cout << a * b << std::endl;
		std::cout << "a / b" << std::endl ;
		std::cout << a / b << std::endl;
		std::cout << "c + d" << std::endl ;
		std::cout << c + d << std::endl;
		std::cout << "c - d" << std::endl ;
		std::cout << c - d << std::endl;
		std::cout << "c * d" << std::endl ;
		std::cout << c * d << std::endl;
		std::cout << "c / d" << std::endl ;
		std::cout << c / d << std::endl;
		// Increment / Decrement
		std::cout << "==================== Increment / Decrement ====================" << std::endl ;
		std::cout << "++a" << std::endl ;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << "a++" << std::endl ;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << "--a" << std::endl ;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << "a--" << std::endl ;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		// Overloaded member function
		std::cout << "==================== Overloaded member function ====================" << std::endl ;
		std::cout << "max( a, b )" << std::endl ;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << "min( a, b )" << std::endl ;
		std::cout << Fixed::min( a, b ) << std::endl;
		std::cout << "max( c, d )" << std::endl ;
		std::cout << Fixed::max( c, d ) << std::endl;
		std::cout << "min( c, d )" << std::endl ;
		std::cout << Fixed::min( c, d ) << std::endl;
	}
	{
		Fixed EPSILON ;
		EPSILON.setRawBits(1) ;
		std::cout << "==================== Epsilon ====================" << std::endl ;
		std::cout << "EPSILON * EPSILON" << std::endl;
		std::cout << EPSILON * EPSILON << std::endl;
		std::cout << "EPSILON * -EPSILON" << std::endl;
		std::cout << EPSILON * -EPSILON << std::endl;
		std::cout << "-EPSILON * EPSILON" << std::endl;
		std::cout << -EPSILON * EPSILON << std::endl;
		std::cout << "-EPSILON * -EPSILON" << std::endl;
		std::cout << -EPSILON * -EPSILON << std::endl;
	}
	return 0;
}
/*
void test(std::string info, const Fixed a) {
  std::cout << std::fixed;
  std::cout << std::setw(15) << info << " : " << a << std::endl;
}

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  Fixed const c(2);
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;

  std::cout << std::endl;
  test("2 / 3", Fixed(2) / Fixed(3));
  test("2 / 0", Fixed(2) / Fixed(0));
  test("3 / 2", Fixed(3) / Fixed(2));
  test("2 / 0.5", Fixed(2) / Fixed(0.5f));
  test("3 / 0.1", Fixed(3) / Fixed(0.1f));
  test("2 / 0.5", Fixed(2) / Fixed(0.5f));
  test("-1 / 2", Fixed(-1) / Fixed(2));
  test("1.1 / -0.3", Fixed(1.1f) / Fixed(-0.3f));
  test("-1 * 2", Fixed(-1) * Fixed(2));
  test("-1.5 * 2", Fixed(-1.5f) * Fixed(2));
  test("-7 * 13", Fixed(-7) * Fixed(13));
  test("7 * -13", Fixed(7) * Fixed(-13));
  test("-3 * 13", Fixed(-3) * Fixed(13));
  test("1.1 * -0.3", Fixed(1.1f) * Fixed(-0.3f));
  test("1.1 * 0.3", Fixed(1.1f) * Fixed(0.3f));
  test("1.004 * 1,004", Fixed(1.004f) * Fixed(1.004f));
  test("2.5 * 1.25", Fixed(2.5f) * Fixed(1.25f));
  test("2.5 * 0.125", Fixed(2.5f) * Fixed(1.25f));
  test("1.25 * 2.5", Fixed(1.25f) * Fixed(2.5f));
  test("0.125 * 2.5", Fixed(0.125f) * Fixed(2.5f));
  test("0.004", Fixed(0.004f));
  test("10.004 * 1", Fixed(10.004f) * Fixed(1));
  test("10.004 / 1", Fixed(10.004f) / Fixed(1));
  test("10.004 * 2", Fixed(10.004f) * Fixed(2));
  test("10.004 / 2", Fixed(10.004f) / Fixed(2));
  test("10.004 * 0.8", Fixed(10.004f) * Fixed(0.8f));
  test("10.004 * -1", Fixed(10.004f) * Fixed(-1));
  test("10.004 / -1", Fixed(10.004f) / Fixed(-1));
  test("10.004 * -1", Fixed(10.004f) * Fixed(-2));
  test("10.004 / -2", Fixed(10.004f) / Fixed(-2));
  test("10.004 * -0.8", Fixed(10.004f) * Fixed(-0.8f));
  test("-10.004 * 1", Fixed(-10.004f) * Fixed(1));
  test("-10.004 / 1", Fixed(-10.004f) / Fixed(1));
  test("-10.004 * 1", Fixed(-10.004f) * Fixed(2));
  test("-10.004 / 2", Fixed(-10.004f) / Fixed(2));
  test("-10.004 * 0.8", Fixed(-10.004f) * Fixed(0.8f));
  test("1.1 * -0.3", Fixed(1.1f) * Fixed(-0.3f));
  test("1.1 * 0.3", Fixed(1.1f) * Fixed(0.3f));
  test("1.1 * -0.3", Fixed(-0.3f) * Fixed(1.1f));
  test("1.1 + 0.3", Fixed(0.3f) + Fixed(1.1f));
  test("0.1 + 1.3", Fixed(0.1f) + Fixed(1.3f));
  test("0.1 + -1.3", Fixed(0.1f) + Fixed(-1.3f));
  test("0.1 - 1.3", Fixed(0.1f) - Fixed(1.3f));
  test("0.1 - -1.3", Fixed(0.1f) - Fixed(-1.3f));
  test("10 - 5.33", Fixed(10) - Fixed(5.33f));
  test("10 + 5.33", Fixed(10) + Fixed(5.33f));
  test("0x400001 * 1.33", Fixed(0x400001) * Fixed(1.33f));
  test("0x200001 * 2.33", Fixed(0x200001) * Fixed(2.33f));
  test("0x100001 * 4.004", Fixed(0x100001) * Fixed(4.004f));
  test("not ovf", Fixed(1 << 22) * Fixed(1.99f));
  test("ovf", Fixed(1 << 22) * Fixed(2));

  Fixed n;
  int i = 1073741825;

  n.setRawBits(i);
  if (i == (n / 1).getRawBits()) {
    std::cout << "binary check : OK" << std::endl;
  }
  return 0;
}
*/
