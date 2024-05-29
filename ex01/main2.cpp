#include "iter.hpp"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >

void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

template< typename T >

void increment(T& x)
{
    x++;
}

int main() {
  int   tab[] = { 0, 1, 2, 3, 4 };
  char  str[] = { 'c', 'i', 'a', 'o'};
  bool  bol[] = { true, false, true, false};
  Awesome tab2[5];
  int *null = NULL;
  void (*pt)(int &) = NULL;

  iter( tab, 5, print<const int> );
  std::cout << std::endl;
  iter( tab2, 5, print<Awesome> );
  std::cout << std::endl;
  iter( tab, 5, increment<int> );
  iter( tab, 5, print<int> );
  std::cout << std::endl;
  iter( str, 4, print<char> );
  std::cout << std::endl;
  iter( bol, 4, print<bool> );

  iter(null, 5, print<int>);
  iter(tab, 5, pt);

  return 0;
}