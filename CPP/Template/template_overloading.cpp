#include<bits/stdc++.h>

using namespace std;

template<class T> class policy{
	T n1,n2;
	public:
		policy(T a,T b)
		{
			n1=a;
			n2=b;
		}
		T add(){return n1+n2;};
		T add(T a){return a+n2;};
		double add(double a,double b){return a+b;};
};

int main()
{
	policy<int> p(12,21);
	cout<<p.add()<<endl;
	cout<<p.add(32)<<endl;
	cout<<p.add(1,2)<<endl;
	return 0;
}
