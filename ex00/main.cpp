/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:30:07 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/29 14:42:07 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Templates.hpp"

class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main( void ) 
{
	int a = 2;
	int b = 3;
	
	std::cout << "\033[1;32mCLASSIC TYPES:\033[0m" << std::endl << std::endl;
	std::cout << "swap int a: " << a << " int b: " << b << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << " b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	bool	e = true;
	bool	f = false;
	std::cout << "swap bool e: " << e << " bool f: " << f << std::endl;
	::swap(c, d);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl << std::endl;
	
	std::cout << "\033[1;32mCOMPLEX TYPES:\033[0m" << std::endl << std::endl;
	Awesome g(2), h(4);
	std::cout << "swap Awesome g: " << g << " Awesome h: " << h << std::endl;
    swap(g, h);
    std::cout << "g = " << g << " h = " << h << std::endl;
    std::cout << "max( g, h) = " << max(g, h) << std::endl;
    std::cout << "min( g, h) = " << min(g, h) << std::endl << std::endl;
	std::cout << "swap string c: " << c << " string d: " << d << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}