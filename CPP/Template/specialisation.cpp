#include<bits/stdc++.h>

using namespace std;

template<class T> class special{
	vector<T> vec;
	public:
		special(vector<T> v)
		{
			for(int i=0;i<v.size();i++)
				vec.push_back(v[i]);
		}
		void sorti();
		void is_less(T a,T b){return a<b;}
		void display();
};

template<class T> void special<T>::sorti()
{
	sort(vec.begin(),vec.end());
}

template<class T> void special<T>::display()
{
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<"\t";
	cout<<endl;
}


int main()
{
	vector<int> v;
	for(int i=0;i<10;i++)
		v.push_back((int)rand());
	special<int> int_obj(v);
	int_obj.sorti();
	int_obj.display();
	vector<string> v1;
	for(int i=0;i<10;i++){
		char buff[20];
		memset(buff,'\0',sizeof(buff));
		snprintf(buff,sizeof(buff),"%d",rand());
		string s1(buff);
		v1.push_back(s1);
	}
	special<string> str_obj(v1);
	str_obj.sorti();
	str_obj.display();
	return 0;
}
