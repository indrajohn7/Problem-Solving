#include <iostream>
#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;

template <class T1,class T2>
class Calculator
{
private:
	T1 num1, num2;
	T2 name;

public:
	Calculator(T1 n1, T1 n2,T2 nam)
	{
		num1 = n1;
		num2 = n2;
		name=nam;
	}
	
	void displayResult()
	{
		cout << "Numbers are: " << num1 << " and " << num2 << "." << endl;
		cout << "Addition is: " << add() << endl;
		cout << "Name is: " << show_name() << endl;
	
	}
	
	T1 add()  {	return num1 + num2; }
	
	T2 show_name() { return name; }

	type_info& get_type(){return typeof(num1);}
};

int main()
{
	Calculator<int,string> intCalc(2, 1,"INDRA");
	Calculator<float,char*> floatCalc(2.4, 1.2,"NATASHA");
	Calculator<double,int> doubleCalc(2.4, 1.2,3);
	Calculator<string,string> stringCalc("2.4", "1.2","HI");
	Calculator<char*,char*> charpCalc("2.4", "1.2","HI");

	cout<<"char* typeinfo:"<<typeid(charpCalc).name()<<endl;
	if(charpCalc.get_type()==typeof(char*))
		cout<<"bingo\n";
	cout << "Int results:" << endl;
	intCalc.displayResult();
	
	cout << endl << "Float results:" << endl;
	floatCalc.displayResult();
	
	cout << endl << "Double results:" << endl;
	doubleCalc.displayResult();
	
	cout << endl << "String results:" << endl;
	stringCalc.displayResult();
	return 0;
}

