#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
#define infi 9999

bool move_rat(char** arr,int R,int C,int* r,int* c,vector<pii> vec)
{
	int left=0,right=0,up=0,down=0,min_up=infi,min_down=infi,min_left=infi,min_right=infi,curr=0;
	if(arr[*r-1][*c]=='*'){
		for(int i=0;i<vec.size();i++){
			if(min_up>(abs(vec[i].first-*r+1)+abs(vec[i].second-*c))){
				min_up=abs(vec[i].first-*r+1)+abs(vec[i].second-*c);
				up=1;
			}
		}
	}
	else
		min_up=0;
	if(arr[*r+1][*c]=='*'){
		for(int i=0;i<vec.size();i++){
			if(min_down>(abs(vec[i].first-*r-1)+abs(vec[i].second-*c))){
				min_down=abs(vec[i].first-*r-1)+abs(vec[i].second-*c);
				down=1;
			}
		}
	}
	else
		min_down=0;
	if(arr[*r][*c-1]=='*'){
		for(int i=0;i<vec.size();i++){
			if(min_left>(abs(vec[i].first-*r)+abs(vec[i].second-*c+1))){
				min_left=abs(vec[i].first-*r)+abs(vec[i].second-*c+1);
				left=1;
			}
		}
	}
	else
		min_left=0;
	if(arr[*r][*c+1]=='*'){
		for(int i=0;i<vec.size();i++){
			if(min_right>(abs(vec[i].first-*r)+abs(vec[i].second-*c-1))){
				min_right=abs(vec[i].first-*r)+abs(vec[i].second-*c-1);
				right=1;
			}
		}
	}
	else
		min_right=0;
	int max1,max2,maxi;
	max1=max(min_left,min_right);
	max2=max(min_up,min_down);
	maxi=max(max1,max2);
	if(right==1 && maxi==min_right){
		arr[*r][*c+1]='R';
		arr[*r][*c]='*';
		*c=*c+1;
	}
	else if(left==1 && min_left==maxi){
		arr[*r][*c-1]='R';
		arr[*r][*c]='*';
		*c=*c-1;
	}
	else if(down==1 && maxi==min_down){
		arr[*r+1][*c]='R';
		arr[*r][*c]='*';
		*r=*r+1;
	}
	else if(up==1 && maxi==min_up){
		arr[*r-1][*c]='R';
		arr[*r][*c]='*';
		*r=*r-1;
	}
	if(maxi==0)
		return false;
	else
		return true;
}


int distance(int one,int two,int three,int four)
{
	return (abs(one-three)+abs(two-four));
}

int main()
{
	int R,C,i,j,k,cought=0,r,c,r_count=0,c_count=0,left=0,right=0,up=0,down=0;
	cout<<"ENTER ROW and COL::";
	cin>>R>>C;
	char** arr=new char*[R];
	for(i=0;i<R;i++)
		arr[i]=new char[C];
	vector<pii> vec;
	cout<<"ENTER THE "<<R<<"*"<<C<<"MATRIX::\n";
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='R'||arr[i][j]=='C'||arr[i][j]=='#'||arr[i][j]=='*'){
				if(arr[i][j]=='R'){
					r_count++;
					r=i;
					c=j;
				}
				else if(arr[i][j]=='C'){
					c_count++;
					pair<int,int> p=make_pair(i,j);
					vec.push_back(p);
				}
				if(r_count>1){
					cout<<"INVALID INPUT as rat position greater than 1::\n";
					return 0;
				}
			}
			else{
				cout<<"INVALID INPUT as the characters::\n";
				return 0;
			}
		}
	}
	if(r_count==0){
		cout<<"INVALID INPUT------> no rat ::\n";
		return 0;
	}
	else if(c_count==0)
		cout<<"Yes\n";
	else{
		while(r!=0 && r!=R-1 && c!=0 && c!=C-1 && cought!=1){
			left=right=up=down=0;
		for(i=0;i<vec.size();i++){
			for(j=0;j<vec.size()-1;j++){
				if((abs(vec[j].first-r)+abs(vec[j].second-c))>(abs(vec[j+1].first-r)+abs(vec[j+1].second-c))){
					pair<int,int> p;
					vec[j]=p;
					vec[j]=vec[j+1];
					vec[j+1]=p;
				}
			}
		}	
		if(move_rat(arr,R,C,&r,&c,vec)){
			for(i=0;i<vec.size();i++){
				int min=999;
				left=right=up=down=0;
				if(distance(vec[i].first-1,vec[i].second,r,c)<min && arr[vec[i].first-1][vec[i].second]!='#'){
					up=1;
					min=distance(vec[i].first-1,vec[i].second,r,c);
				}
				if(distance(vec[i].first+1,vec[i].second,r,c)<min && arr[vec[i].first+1][vec[i].second]!='#'){
					down=1;
					min=distance(vec[i].first-1,vec[i].second,r,c);
				}
				if(distance(vec[i].first,vec[i].second-1,r,c)<min && arr[vec[i].first][vec[i].second-1]!='#'){
					left=1;
					min=distance(vec[i].first-1,vec[i].second,r,c);
				}
				if (distance(vec[i].first,vec[i].second+1,r,c)<min && arr[vec[i].first][vec[i].second+1]!='#'){
					right=1;
					min=distance(vec[i].first-1,vec[i].second,r,c);
				}
				if(right==1){
					if(arr[vec[i].first][vec[i].second+1]=='R'){
						cought=1;
						break;
					}
					arr[vec[i].first][vec[i].second]='*';
					arr[vec[i].first][vec[i].second+1]='C';
					vec[i].second=vec[i].second+1;
				}
				else if(left==1){
					if(arr[vec[i].first][vec[i].second-1]=='R'){
						cought=1;
						break;
					}
					arr[vec[i].first][vec[i].second]='*';
					arr[vec[i].first][vec[i].second-1]='C';
					vec[i].second=vec[i].second-1;
				}
				else if(down==1){
					if(arr[vec[i].first+1][vec[i].second]=='R'){
						cought=1;
						break;
					}
					arr[vec[i].first][vec[i].second]='*';
					arr[vec[i].first+1][vec[i].second]='C';
					vec[i].first=vec[i].first+1;
				}
				else if(up==1){
					if(arr[vec[i].first-1][vec[i].second]=='R'){
						cought=1;
						break;
					}
					arr[vec[i].first][vec[i].second]='*';
					arr[vec[i].first-1][vec[i].second]='C';
					vec[i].first=vec[i].first-1;
				}
			}
		}
		else
			break;
	}
	}
	if(r==0||r==R-1||c==0||c==C-1)
		cout<<"Yes\n";
	else if(cought==1)
		cout<<"No\n";
	return 0;
}