#include <iostream>
class Base
{
public:
    virtual ~Base()=0; // Pure virtual destructor
};

Base::~Base()
{
	std::cout<<"Inside pure virtual destructor:\n";
}

class Derived : public Base
{
public:
    ~Derived()
    {
        std::cout << "~Derived() is executed";
    }
};
 
int main()
{
    Base *b=new Derived();
    delete b;
    return 0;
}

