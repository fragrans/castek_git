#include <iostream>
#include <boost/format.hpp>
int main()
{
  char c='c';
  std::cout << boost::format("%|1$1| %|2$3x| %2$04x") % "Hello" % (long long)c << std::endl;
  return 0;
}
