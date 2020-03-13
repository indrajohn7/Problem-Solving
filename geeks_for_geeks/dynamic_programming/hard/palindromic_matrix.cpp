#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct node{
	char val;
	int x, y;
	node(char ch, int a, int b)
	{
		val = ch; //new char[strlen(ch)];
		//strncpy(val, ch, strlen(ch));
		x = a;
		y = b;
	}
};

void get_all_paths(char** arr, int R, int C)
{
	
	//typedef vector<node*> arr;
//	typedef node* anode[R + C - 1];
	int steps = (R + C -1);
	typedef vector<node*> anode;
	typedef vector<anode>	var;
	vector<var> vec;
	var temp;


	anode nd(steps);
	nd[0] = new node(arr[0][0], 0, 0);
	nd[steps - 1] = new node(arr[R - 1][C - 1], R - 1, C - 1);
	int layer = 1;
	temp.push_back(nd);
	vec.push_back(temp);
	while(layer < ((steps/2) + 1)){
		temp.clear();
		int last = vec[vec.size() - 1].size();
		for(int i = 0; i < last; i++){
			int x1, x2, y1, y2;
			char val1, val2;
			x1 = vec[vec.size() - 1][i][layer - 1]->x;
			x2 = vec[vec.size() - 1][i][steps - layer]->x;
			y1 = vec[vec.size() - 1][i][layer - 1]->y;
			y2 = vec[vec.size() - 1][i][steps - layer]->y;
			val1 = vec[vec.size() - 1][i][layer - 1]->val;
			val2 = vec[vec.size() - 1][i][steps - layer]->val;

			if(x1 >= x2 || y1 >= y2)
				continue;

			if((((x1 + 1) == x2) && ((y1 == y2))) || (((y1 + 1) == y2) && (x1 == x2))){
				//temp.push_back(vec[vec.size() - 1][i]);
				continue;
			}

			if(arr[x1 + 1][y1] == arr[x2 - 1][y2]){
				anode nd(steps);
				for(int j = 0; j < steps; j++){

					if( vec[vec.size() - 1][i][j]){
						nd[j] = new node(0, 0, 0);
						memcpy(nd[j], vec[vec.size() - 1][i][j], sizeof(node));
					}
				}
				nd[layer] = new node(arr[x1 + 1][y1], (x1 + 1), y1);
				nd[steps-layer-1] = new node(arr[x2 - 1][y2], (x2 - 1), y2);
				temp.push_back(nd);
			}

			if(arr[x1 + 1][y1] == arr[x2][y2 - 1]){
				anode nd(steps);
				for(int j = 0; j < steps; j++){
				
					if( vec[vec.size() - 1][i][j]){
						nd[j] = new node(0, 0, 0);
						memcpy(nd[j], vec[vec.size() - 1][i][j], sizeof(node));
					}
				}
				nd[layer] = new node(arr[x1 + 1][y1], (x1 + 1), y1);
				nd[steps-layer-1] = new node(arr[x2][y2 - 1], (x2), y2 - 1);
				temp.push_back(nd);
			}

			if(arr[x1][y1 + 1] == arr[x2 - 1][y2]){
				anode nd(steps);
				for(int j = 0; j < steps; j++){
					if( vec[vec.size() - 1][i][j]){
						nd[j] = new node(0, 0, 0);
						memcpy(nd[j], vec[vec.size() - 1][i][j], sizeof(node));
					}
				}
				nd[layer] = new node(arr[x1][y1 + 1], (x1), y1 + 1);
				nd[steps-layer-1] = new node(arr[x2 - 1][y2], (x2 - 1), y2);
				temp.push_back(nd);
			}

			if(arr[x1][y1 + 1] == arr[x2][y2 - 1]){
				anode nd(steps);
				for(int j = 0; j < steps; j++){
					if( vec[vec.size() - 1][i][j]){
						nd[j] = new node(0, 0, 0);
						memcpy(nd[j], vec[vec.size() - 1][i][j], sizeof(node));
					}
				}
				nd[layer] = new node(arr[x1][y1 + 1], (x1), y1 + 1);
				nd[steps-layer-1] = new node(arr[x2][y2 - 1], (x2), y2 - 1);
				temp.push_back(nd);
			}

		}
		if (temp.size())
			vec.push_back(temp);
		layer++;
	}

	int last = vec[vec.size() - 1].size();
	for(int i = 0; i < last; i++){
		cout << "ITERATION #" << i + 1 << ":\n";
		for(int j = 0; j < steps; j++){
			cout << "<" << vec[vec.size() - 1][i][j]->val << ", <" << vec[vec.size() - 1][i][j]->x << "," << vec[vec.size() - 1][i][j]->y << ">>\n";
		}
	}

}


int main()
{
	int num_test;
	ifstream fin;
	fin.open("palin.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		int R, C;
		fin >> R >> C;
		char** arr = new char*[R];
		for(int i = 0; i < R; i++){
			arr[i] = new char[C];
			for(int j = 0; j < C; j++)
				fin >> arr[i][j];
		}

		cout << "Case #" << iter + 1 << ":\n";
		get_all_paths(arr, R, C);
		
	}

	return 0;
}
