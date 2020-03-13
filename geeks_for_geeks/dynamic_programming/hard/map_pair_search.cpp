#include<bits/stdc++.h>

using namespace std;

int main()
{
	typedef pair<int, int> pii;
	map<pii, bool> work;
	for(int i = 0; i < 10; i++)
		work[make_pair(i, i + 1)] = true;
	if(work.find(make_pair(0, 1)) != work.end())
		cout << "Found\n";
	return 0;
}
