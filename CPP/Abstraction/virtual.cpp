#include<bits/stdc++.h>

using namespace std;


class base{
	protected:
		int a;
		char* name;
	public:
		base(int b, char* data)
		{
			a = b;
			name = data;
		}

		virtual void set_int()
		{
			a = -1;
		}

		virtual void set_string()
		{
			name = "base";
		}

		int get_int(){ return a; }
		char* get_string(){ return name; }
};

class derived : public base{
	private:
		int c;
	public:
		derived(int i,int j,char* data):base(i,data),c(j){
		/*	b = i;
			c = j;
			name = data;
		*/
		}
		
		void set_int()
		{
			cout<< "Setting derived int:\n";
			a = 0;
		}
		void set_string()
		{
			cout<< "Setting derived string:\n";
			name = "derived";
		}
		

		int get_int()
		{
			return a;
		}
		char* get_string()
		{
			return name;
		}

};

int main()
{

	base b(10,"indra");
	derived d(11,12,"jit");
	//b = d;
	cout<< b.get_int()<<endl<<b.get_string()<<endl;
	cout<<"SIZEOF BASE:"<<sizeof(b)<<endl;
	cout<<"SIZEOF DERIVED:"<<sizeof(d)<<endl;
	
	base *b1,*b2,*b3;
	derived *d1,*d2,*d3;
/*
	d1 = dynamic_cast<base*> (&d); //compilation error wrong conversion
	d1 = dynamic_cast<base*> (&b);// compilation error wrong conversion
	d1 = dynamic_cast<derived*> (&b); //NULLPTR
	d1 = dynamic_cast<derived*> (&d); //result OK
	d1->set_int();
	d1->set_string();
*/

	b1 = dynamic_cast<base*> (&b); //calls base class properties --> OK
	b1 = dynamic_cast<base*> (&d); //Calls derived class properties --> OK
	b1 = dynamic_cast<derived*> (&b); //NULLPTR
	b1 = dynamic_cast<derived*> (&d); //derived class properties --> OK
	
	b1->set_int();
	b1->set_string();

	cout<< b1->get_int() << endl << b1->get_string() << endl;
	
	
	return 0;
}
