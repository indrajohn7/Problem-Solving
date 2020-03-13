#include<bits/stdc++.h>

using namespace std;

/* This function returns max number of ways we can define a sum N with 1-K number of integers.
 * But there are duplicated counts present in this calculation :
 * like:
 *
 * f(3) = 1 + f(2) | 2 + f(1) | f(3)
 * 1 + f(2) has the combination of (1,1,1) and (1,2)
 * 2 + f(1) has the same duplicated combination: (2,1)
 * */

int get_max_number_wands(int item, int value)
{
	int iter = 1;
	int* arr = new int[value];
	while(iter <= value){
		if (iter == 1){
			arr[iter-1] = 1;
			iter++;
			continue;
		}
		int sum = 0;
		for(int count = 1; count < (iter); count++){
			if(count > item)
				break;
			sum += arr[iter - count - 1];
			sum %= ((int)pow(10,9) + 7);
		}
		if(iter <= item)
			sum += 1;
		arr[iter-1] = sum;
		iter++;
	}

	return arr[value-1];
}


int main()
{
	ifstream fin;
	fin.open("wand.in");
	int Num_test;
	fin >> Num_test;
	for(int iter = 0; iter < Num_test; iter++){
		int item, value;
		fin >> value >> item;
		int res = get_max_number_wands(item,value);
		cout << res << endl;
	}
	return 0;
}
