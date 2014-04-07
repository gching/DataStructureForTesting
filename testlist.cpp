// testlist.cpp
// Used to test list transversal with iterator.
// Gavin Ching
// April 6, 2014

#include <iostream>
#include <list>

int main ()
{
  int myints [] = {75,23,65,42,13};
  std :: list <int> mylist(myints, myints+5);

  std::cout << "mylist contains:";
  std::list<int>::iterator derp = mylist.begin();

  for (int p = 0; p<5; p++)
  	derp = ++derp;

  for (std::list<int>::iterator it=mylist.begin(); it != derp; ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}