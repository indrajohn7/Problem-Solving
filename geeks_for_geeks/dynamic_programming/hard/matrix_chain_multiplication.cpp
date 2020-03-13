#include<bits/stdc++.h>

using namespace std;
#define INF 9999999

typedef pair<int, int> pii;

pii min_cost(vector<pii> vec)
{
	int len = vec.size();
	pii** arr = new pii*[len];
	for(int i = 0; i < len; i++)
		arr[i] = new pii[len];

	int iter = 0;
	while(iter < len){
		for(int i = 0; i < len; i++){
		//	for(int j = i + iter; j < len; j++){
				int j = i + iter;
				if (j >= len)
					break;
				if(j == i){
					arr[i][j] = make_pair(0, 0);
				} else {
					int min = INF, max = 0;
					min = (arr[i + 1][j].first + (vec[i].first * vec[i].second * vec[j].second));
					max = (arr[i + 1][j].second + (vec[i].first * vec[i].second * vec[j].second));
					int mini, maxi;
					for(int k = i + 1; k < j, (i - j) > 2; k++){

						int multi = (vec[i].first * vec[k].first * vec[j].second);
						mini = multi + (arr[i][k - 1].first + arr[k][j].first);
						maxi = multi + (arr[i][k - 1].first + arr[k][j].second);
						if (mini < min)
							min = mini;
						if (maxi > max)
							max = maxi;
					}
					mini = (arr[i][j - 1].first + (vec[i].first * vec[j - 1].second * vec[j].second));
					maxi = (arr[i][j - 1].second + (vec[i].first * vec[j - 1].second * vec[j].second));
						if (mini < min)
							min = mini;
						if (maxi > max)
							max = maxi;
					
					
					arr[i][j] = make_pair(min, max);
				}
			//}
		}
		iter++;
	}

	return arr[0][len - 1];
}

int main()
{
	int num_test;
	ifstream fin;
	fin.open("matrix.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		int N;
		vector<pii> vec;
		fin >> N;
		for(int i = 0; i < N; i++){
			int a, b;
			fin >> a >> b;
			vec.push_back(make_pair(a, b));
		}

		pii res = min_cost(vec);
		cout << "Case #" << iter + 1 << ": " << res.first << " :: " << res.second << endl;
	}

	return 0;
}
