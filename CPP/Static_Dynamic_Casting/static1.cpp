#include<bits/stdc++.h>

using namespace std;


class B {};
class D : public B {};
class X {};

int main()
{
  D* d = new D;
  B* b = static_cast<B*>(d); // this works
  X* x = static_cast<X*>(d); // ERROR - Won't compile
  return 0;
}

