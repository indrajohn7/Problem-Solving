#include<bits/stdc++.h>

using namespace std;

typedef struct _node {
	int start_x, start_y, end_x, end_y;
	int num;
	char res[10];
	
}node;

typedef pair<int, int> pii;
typedef vector<pii> vpi;

void analyze_all_the_combinations(int** arr, int R, int C, map<pii, vpi> work, node& nd)
{

	int max = 0;

	for(map<pii, vpi>::iterator it = work.begin(); it != work.end(); it++){
		int start_x, start_y, end_x, end_y;
		start_x = it->first.first;
		start_y = it->first.second;
		for(int i = 0; i < it->second.size(); i++){
			end_x = it->second[i].first;
			end_y = it->second[i].second;
			int row_count, col_count, elem;
			elem = (end_x - start_x + 1) * (end_y - start_y + 1);
			row_count = col_count = 0;
			for(int p = 0; p < R; p++){
				if(!(p >= start_x && p <= end_x)){
					int count = 0;
					for(int q = start_y; q <= end_y; q++){
						if (arr[p][q] == 1)
							count++;
						else
							break;
					}
					if(count == (end_y - start_y + 1))
						row_count++;
					
				}
			}
			for(int p = 0; p < C; p++){
				if(!(p >= start_y && p <= end_y)){
					int count = 0;
					for(int q = start_x; q <= end_x; q++){
						if (arr[q][p] == 1)
							count++;
						else
							break;
					}
					if(count == (end_y - start_y + 1))
						col_count++;
					
				}
			}
			int elem_row = elem + (row_count * (end_y - start_y + 1));
			int elem_col = elem + (col_count * (end_x - start_x + 1));
			
			if(elem_row > max || elem_col > max){
				nd.start_x = start_x;
				nd.start_y = start_y;
				nd.end_x = end_x;
				nd.end_y = end_y;
				memset(nd.res, '\0', sizeof(nd.res));
				if(elem_row > elem_col){
					nd.num = elem_row;
					strncpy(nd.res, "Row", strlen("Row"));
				} else {
					nd.num = elem_col;
					strncpy(nd.res, "Col", strlen("Row"));
				}

			}
		}
	}
}

node matrix_swap(int** arr, int R, int C)
{
	vpi dp[R + 1][C + 1];
	for(int i = 0; i <= C; i++)
		dp[0][i].push_back(make_pair(0, 0));
	for(int i = 0; i <= R; i++)
		dp[i][0].push_back(make_pair(0, 0));

	node nd;
	memset(&nd, 0, sizeof(node));
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			int r, c;
			if(arr[i - 1][j - 1] == 1){
				if(dp[i - 1][j][0].first == dp[i][j - 1][0].second == 0)
					dp[i][j].push_back(make_pair(1, 1));
				else {
					//put all the ele in dp table
					map<pii, bool> gmap;
					for(int k = 0; k < dp[i - 1][j].size(); k++){
						for(int l = 0; l < dp[i][j - 1].size(); l++){
							int r1, c1, r2, c2;
							r1 = dp[i - 1][j][k].first;
							c1 = dp[i - 1][j][k].second;
							r2 = dp[i][j - 1][k].first;
							c2 = dp[i][j - 1][k].second;
							if (r1 + 1 == r2 && c1 == c2 + 1){
								if(gmap.find(make_pair(r2, c1)) == gmap.end()){
									dp[i][j].push_back(make_pair(r2, c1));
									gmap[make_pair(r2, c1)] = true;
								}
							} else {
								if(gmap.find(make_pair(r1+ 1, c1)) == gmap.end()){
									dp[i][j].push_back(make_pair(r1 + 1, c1));
									gmap[make_pair(r1 + 1, c1)] = true;
								} if (gmap.find(make_pair(r2, c2 + 1)) == gmap.end()){
									dp[i][j].push_back(make_pair(r2, c2 + 1));
									gmap[make_pair(r2, c2 + 1)] = true;
								}
							}
						}
					}
					gmap.clear();
				}

			} else {
				dp[i][j].push_back(make_pair(0, 0));
			}
		}
	}
	
	map <pii, vpi> work;
	for(int i = R; i >= 0; i--){
		for(int j = C; j>=0; j--){
			for(int k = 0; k < dp[i][j].size(); k++){
				int start_x, start_y, end_x, end_y;
				end_x = i - 1; //dp[i][j][k].first;
				end_y = j - 1; //dp[i][j][k].second;
				start_x = end_x - dp[i][j][k].first + 1;
				start_y = end_y - dp[i][j][k].first + 1;

				work[make_pair(start_x, start_y)].push_back(make_pair(end_x, end_y));
			}
		}
	}

	analyze_all_the_combinations(arr, R, C, work, nd);

	return nd;

}

int main()
{
	int num_test;
	ifstream fin;
	fin.open("swap.in");
	fin >> num_test;
	cout << "Case NO.   " << "Start_x\t" << "Start_y\t" << "End_x\t" << "End_y\t" <<"Num\t" << "Res\n";
	for(int iter = 0; iter < num_test; iter++){
		int R, C;
		fin >> R >> C;
		int** arr = new int*[R];
		for(int i = 0; i < R; i++)
			arr[i] = new int[C];
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				fin >> arr[i][j];

		node nd = matrix_swap(arr, R, C);
		cout << "Case #" << iter + 1 << ": " << nd.start_x << "\t\t" << nd.start_y << "\t\t" << nd.end_x << "\t\t" << nd.end_y << "\t\t" << nd.num << "\t\t" << nd.res << endl;
	}

	return 0;
}
