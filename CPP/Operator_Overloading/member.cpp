#include<bits/stdc++.h>

using namespace std;

class A{
	int a,b,c;
	static char d;
	public:
		A(int q,int w,int e)
		{
			a=w;
			b=q;
			c=e;
		}
		int set_num(int);
		int get_num(int) const;
		void set_char(char);
		char get_char()const;
		A& return_obj(A&);
};


char A::d='A';


int A::get_num(int i) const
{
	return a;
}

void A::set_char(char c)
{
	d=c;
}

char A::get_char() const
{
	return (d);
}

A& A::return_obj(A& obj1)
{
	this->a=obj1.a;
	this->b=obj1.b;
	return (*this);
}

int main()
{
	A obj(12,21,23);
	cout<<obj.get_num(2)<<endl;
	obj.set_char('a');
	cout<<obj.get_char()<<endl;
	cout<<sizeof(obj)<<endl;
	cout<<sizeof(A)<<endl;
	A obj2(1,2,3);
	obj2.return_obj(obj);
	cout<<obj2.get_num(1)<<endl;
	return 0;
}

class B:public A{
	
};
