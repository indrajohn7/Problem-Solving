/*	Adding a virtual function to the base class B makes it working.
*/
// CPP program to illustrate 
// Run Time Type Identification 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class B { virtual void fun() {} };

class D: public B { };
 
int main()
{
    B *b = new D;
    D *d = dynamic_cast<D*>(b);
    if(d != NULL)
        cout << "works\n";
    else
        cout << "cannot cast B* to D*";
    //getchar();
    return 0;
}

