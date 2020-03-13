#include<iostream>
using namespace std;
 
class Derived;
 
class Base {
private:
    virtual void fun() { cout << "Base Fun\n"; }
friend int main();
};
 
class Derived: public Base {
public:
    void fun() { cout << "Derived Fun\n"; }
};
 
int main()
{
   Base *ptr = new Derived;
   ptr->fun();
   return 0;
}

