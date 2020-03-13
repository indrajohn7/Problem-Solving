#include<bits/stdc++.h>

using namespace std;

class shape{
	int side;
	public:
		virtual void rotate(int){cout<<"shape:rotate\n";}
		virtual void draw(){cout<<"shape:draw\n";}
};

class point:public shape
{
	//
};


class circle:public shape
{
	int side,radius;
	point center;
	public:
		virtual void rotate(int);
		inline void init(){cout<<"INIT from circle:\n";}
	//	void draw();
};

class triangle:public shape
{
	int side,length;
	point center;
	public:
		virtual void rotate(int);
		inline void init(){cout<<"INIT from triangle:\n";}
	//	void draw();
};

class box:public circle,public triangle
{
	int side;
	public:
		void rotate(int);	
};

void box::rotate(int a)
{
	cout<<"box can't rotate\n";
}


void circle::rotate(int deg)
{
	cout<<"circle rotated\n";
}


void triangle::rotate(int deg)
{
	cout<<"triangle rotated\n";
}

int main()
{
	shape s;
	circle c;
	triangle t;
	box b;
	shape *s1,*s2;
	triangle* t1,t2;
	circle *c1,*c2;
	s1=&t;
	s1->rotate(1);
	s1=dynamic_cast<shape*>(&c);
	s2=dynamic_cast<circle*>(&c);
	s1->rotate(1);
	s2->rotate(1);
	
	c1=dynamic_cast<circle*>(&s);
	c1->init();
	//s2->init();
	c1=(circle*)dynamic_cast<circle*>(s1);
	c1->rotate(1); //Since c1 is a NULL pointer hence it will give a core dump
	b.rotate(1);
	s.rotate(1);
	c.rotate(2);
	t.rotate(3);
	return 0;
}
