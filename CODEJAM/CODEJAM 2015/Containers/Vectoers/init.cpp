#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int main ()
{
  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  vector<int> f(fifth);
  vector<int> f1(fifth.begin(),fifth.end());
  vector<int> f2(f1);
  std::cout << "The contents of f2 are:";
  for (std::vector<int>::reverse_iterator it2 = f2.rbegin(); it2 != f2.rend(); ++it2)
    std::cout << ' ' << *it2;
  std::cout << '\n';

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

