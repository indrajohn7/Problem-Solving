#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool checked[100][100];

struct N
{
  int x;
  int y;
  int cost;
};

bool connects(vector<pair<int,int> > &cl, int x, int y)
{
  for (int i = 0; i < cl.size(); ++i)
  {
    int x1 = cl[i].first, y1 = cl[i].second;
    if (((x1 == x) || (x1 == x - 1) || (x1 == x + 1)) &&
        ((y1 == y) || (y1 == y - 1) || (y1 == y + 1)))
      return true;
  }
  return false;
}

bool comp(N n1, N n2)
{
  return n1.cost < n2.cost;
}

void bfs(vector<vector<int> > &in, queue<pair<int,int> > &q, vector<pair<int,int> > &cl, int ROW, int COL)
{
  while (!q.empty())
  {
    pair<int,int> p = q.front(); q.pop();
    if (checked[p.first][p.second]) continue;
    checked[p.first][p.second] = true;
    cl.push_back(p);
    for (int i1 = p.first - 1; i1 < p.first + 2; ++i1)
      for (int j1 = p.second - 1; j1 < p.second + 2; ++j1)
        if (i1 >= 0 && j1 >= 0 && i1 < ROW && j1 < COL)
          if (in[i1][j1] == -1)
          {
            q.push(make_pair(i1,j1));
          }
  }
}

int minimum_possible_cost(char* input1)
{
  vector<vector<int> > in;
  vector<int> v;
  char *input2 = input1;
  while (*input2)
  {
    if (*input2 == '@')
    {
      int x;
      sscanf(input1, "%d", &x);
      v.push_back(x);
      input1 = input2 + 1;
    }
    else if (*input2 == '#')
    {
      int x;
      sscanf(input1, "%d", &x);
      v.push_back(x);
      in.push_back(v);
      v.clear();
      input1 = input2 + 1;
    }
    input2++;
  }
  
  vector<vector<pair<int,int> > > graph;
  int ROW = in.size(), COL = in[0].size();

 
  for (int i = 0; i < ROW; i++)
    for (int j = 0; j < COL; j++)
    {
      // Either RED or already checked
      if (in[i][j] != -1 || checked[i][j]) continue;
      
      queue<pair<int,int> > q;
      vector<pair<int, int> > cluster;
      q.push(make_pair(i,j));
      bfs(in, q, cluster, ROW, COL);
      graph.push_back(cluster);
    }


  int SIZE = graph.size();
  // Take care of simple cases
  if (SIZE < 2) return 0;
  return 2;
  //return 10;
}

