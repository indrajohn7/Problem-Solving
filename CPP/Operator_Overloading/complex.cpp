#include<bits/stdc++.h>

#define PI 3.14159265
#define SIN(X) sin(X*PI/180)
#define COS(X) cos(X*PI/180)
#define COMPLEX_MOD(A,B) sqrt(pow(A,2)+pow(B,2))
#define COMPLEX_ARG(A,B)  (atan(B/A))*180/PI



using namespace std;


namespace A{
	class comp{
		private:
			float real;
			float imag;
		public:
			comp(float a,float b)
			{
				real=a;
				imag=b;
			}
			comp(comp& c)
			{
				real=c.real;
				imag=c.imag;
			}
			comp()
			{
				real=imag=0;
			}
			comp& operator+(const comp&);
			comp& operator-(const comp&);
			comp& operator*(const comp&);
			comp& operator/(const comp&);
			comp& operator=(const comp&);
			bool operator==(const comp&);
			//ostream& operator<<(ostream&, const comp);
			//istream& operator>>(istream&, const comp&);
			void print_complex();
	};

	comp& comp::operator+(const comp& C1)
	{
		comp c;
		c.real=this->real+C1.real;
		c.imag=this->imag+C1.imag;
		return (c);
	}


	comp& comp::operator-(const comp& C1)
	{
		comp c;
		c.real=this->real-C1.real;
		c.imag=this->imag-C1.imag;
		return (c);
	}


	comp& comp::operator*(const comp& C1)
	{
		comp c;
		c.real=this->real*C1.real;
		c.imag=(-1)*(C1.imag*this->imag);
		return (c);
	}


	comp& comp::operator/(const comp& C1)
	{
		comp c;
		float num=COMPLEX_MOD(this->real,this->imag);
		float deno=COMPLEX_MOD(C1.real,C1.imag);
		float angle_num,angle_deno;
		angle_num=COMPLEX_ARG(this->real,this->imag);
		angle_deno=COMPLEX_ARG(C1.real,C1.imag);
		c.real=(num/deno)*(COS(angle_num-angle_deno));
		c.imag=(num/deno)*(SIN(angle_num-angle_deno));
		return (c);
	}


	comp& comp::operator=(const comp& C1)
	{
		comp c;
		this->real=C1.real;
		this->imag=C1.imag;
		return (*this);
	}


	bool comp::operator==(const comp& C1)
	{
		bool ret = ((C1.real==this->real)&&(C1.imag==this->imag))?true:false;
		return ret;
	}
/*
	comp& comp::operator~(const comp& c1)
	{
		comp c;
		c.real=c1.real;
		c.imag=(-1)*(c1.imag);
		return (c);
	}
*/
/*	ostream& comp::operator<<(const comp& c)
	{
		cout<<c.real<<"+i*("<<c.imag<<")";
	}
*/
	void comp::print_complex()
	{
		cout<<real<<"+i*("<<imag<<")"<<endl;
	}

}



int main()
{
	A::comp c1(12,-21);
	A::comp c2=c1;
	A::comp c3(c1);
	A::comp c4;
	c4=c1+c2;
//	c4=~c1;
	A::comp c5=c4*c1;
	A::comp c6=c5*c4-c2+c3;
//	cout<<c6<<endl;
	c1.print_complex();	
	c2.print_complex();	
	c4.print_complex();	
	c5.print_complex();	
	c6.print_complex();	
	return 0;
}
