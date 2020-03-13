#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Num_test;
	freopen("meal.in","r",stdin);
	cin>>Num_test;
	for(int iter=0;iter<Num_test;iter++){
		int N,M;
		cin>>N>>M;
		int Cost[N],Meal_Set[M],Meals[M][M];
		for(int i=0;i<N;i++)
			cin>>Cost[i];
		for(int i=0;i<M;i++){
			memset(Meals[i],0,M);
			cin>>Meal_Set[i];
			int quan;
			cin>>quan;
			for(int j=0;j<quan;j++)
				cin>>Meals[i][j];
		}
		
	}
}