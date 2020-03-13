#include<bits/stdc++.h>

using namespace std;


void run(int m, int n)
{
	static int a = 0;
	while(a != n) {
		a++;
		cout << "Hello Akamai!\n";
		return run(m, n);
	}
	if (a == n) {
		a = 0;
		m++;
	}
	if (m == n)
		return ;
	else
		run(m, n);
}

int main()
{
	int n;
	cout << "Provide N:";
	cin >> n;
	run(0, n);
	return 0;
}
