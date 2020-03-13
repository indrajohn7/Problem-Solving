/*	In C++, RTTI (Run-time type information) is a mechanism that exposes information about an object’s data type at 
 *	runtime and is available only for the classes which have at least one virtual function. It allows the type of 
 *	an object to be determined during program execution
 *
 *	For example, dynamic_cast uses RTTI and following program fails with error “cannot dynamic_cast `b’ (of type `class B*’) 
 *	to type `class D*’ (source type is not polymorphic) ” because there is no virtual function in the base class B.
 * */


#include<iostream>
using namespace std;
class B { };
class D: public B {};
 
int main()
{
    B *b = new D;
    D *d = dynamic_cast<D*>(b);
    if(d != NULL)
        cout<<"works";
    else
        cout<<"cannot cast B* to D*";
    getchar();
    return 0;
}

