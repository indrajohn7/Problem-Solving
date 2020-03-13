/*
Find minimum possible size of array with given rules for removing elements
4.3
Given an array of numbers and a constant k, minimize size of array with following rules for removing elements.

Exactly three elements can be removed at one go.
The removed three elements must be adjacent in array, i.e., arr[i], arr[i+1], arr[i+2]. And the second element must be k greater than first and third element must be k greater than second, i.e., arr[i+1] – arr[i] = k and arr[i+2]-arr[i+1] = k.
Example:

Input: arr[] = {2, 3, 4, 5, 6, 4}, k = 1
Output: 0
We can actually remove all elements. 
First remove 4, 5, 6 => We get {2, 3, 4}
Now remove 2, 3, 4   => We get empty array {}

Input:  arr[] = {2, 3, 4, 7, 6, 4}, k = 1
Output: 3
We can only remove 2 3 4

Input: arr[] = {1,2,3,4,5,6,4,2,3}; k = 1
output: 0
Remove:   step 1: 4,5,6 | 2,3,4 | 1,2,3 .
*/


#include<bits/stdc++.h>

using namespace std;

#define DIS(x,y) (y-x)

bool is_break_possible(vector<int> v, int K)
{
	for(int i=0;i<v.size()-2;i++){
		if((v[i+1] - v[i]) == K && (v[i+2] - v[i+1]) == K)
			return true;
	}
	return false;
}

int get_min_length(int arr[], int N, int K)
{
	vector<int> vec(arr,arr+N);
	int min = 9999;
	vector<int> temp = vec;
	for(int i=0, prev = 0; i < (temp.size() - 2); i++){
		int j=i;
		if(temp.size() == 0){
			min = 0;
			break;
		}
		if (min > temp.size())
			min = temp.size();
		
		if (i != 0) { // && !is_break_possible(temp, K))
			bool flag = false;
			for(int k = 0; k < temp.size()-2; k++){
				if((temp[k+1] - temp[k]) == K && (temp[k+2] - temp[k+1]) == K)
					flag  = true;
					break;
			}
			if(!flag)
				break;
		}

		while(j<temp.size()-2){
			if ((temp[j+1] - temp[j]) == K && (temp[j+2] - temp[j+1] == K)){
				vector<int>::iterator it = temp.begin();
				temp.erase(it+j,it+j+3);
				i = -1;
				break;
			}
			j++;
		}
		if(i != -1){
			temp = vec;
			i = prev;
			prev++;
		}
		if (min > temp.size())
			min = temp.size();

	}
	if (min > temp.size())
		min = temp.size();

	return min;
}

int main()
{
	ifstream fin;
	fin.open("array.in");
	int num_test;
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++) {
		
		int N, K;
		fin >> N >> K;
		int* arr = new int[N];
		for(int i=0;i<N;i++)
			fin>>arr[i];
		int res = get_min_length(arr,N,K);
		cout<<"Case #"<<iter+1<<": "<<res<<endl;
	}
	return 0;
}
