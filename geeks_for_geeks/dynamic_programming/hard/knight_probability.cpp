#include<bits/stdc++.h>

using namespace std;

#define CHESS_MAX 8

bool is_inside(int x, int y)
{
	if (x >= 0 && x < CHESS_MAX && y >= 0 && y < CHESS_MAX)
		return true;
	else
		return false;
}

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

typedef struct _node{
	int x, y;
	double prob;
}node;


double get_insider(int x, int y, int steps)
{
	int oper = 0;
	double res = 1, sum = 0;
	typedef pair<int, int> pii;
	typedef vector<node> vpi;
	vector<vpi> vec;
	node nd;
	nd.x = x;
	nd.y = y;
	nd.prob = 1;
	vpi temp;
	temp.push_back(nd);
	vec.push_back(temp);

	while(oper < steps){
		temp.clear();
		int idx = vec.size() - 1;
		for(int i = 0; i < vec[vec.size() - 1].size(); i++){

			double prob = 0;
			for(int j = 0; j < CHESS_MAX; j++){
				int nx = vec[idx][i].x + dx[j];
				int ny = vec[idx][i].y + dy[j];
				if(is_inside(nx, ny)){
					prob += vec[idx][i].prob / 8;
					node nd;
					nd.x = nx;
					nd.y = ny;
					nd.prob = 1;
					temp.push_back(nd);
				}
			}
			vec[idx][i].prob = prob;

		}
		vec.push_back(temp);
		oper++;
		sum = 0;
		for(int j = 0; j < vec[idx].size(); j++)
				sum += vec[idx][j].prob;
		sum = (sum / vec[idx].size());
		res *= sum;
	}

	return res;

}

int main()
{
	int num_test;
	ifstream fin;
	fin.open("knight.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		int x, y, steps;
		fin >> x >> y >> steps;
		double res = get_insider(x, y, steps);
		cout << "Case #" << iter + 1 << ": " << res << endl;
	}
	return 0;
}
