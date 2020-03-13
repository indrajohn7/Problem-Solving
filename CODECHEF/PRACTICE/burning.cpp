#include<bits/stdc++.h>

using namespace std;

bool update_blast(char** city,bool blast,int x,int y,int N)
{
	if(blast==true){
		city[x][y]='w';
		return true;
	}
	return false;
}

void update_fire(char** city,int i,int N)
{
	if(i!=1 && i%2!=0){
		for(int p=0;p<N;p++){
			for(int q=0;q<N;q++){
				if(city[p][q]=='f'){
					if((p-1)>=0 && city[p-1][q]!='w')
						city[p-1][q]='f';
					if((p+1)<=N-1 && city[p+1][q]!='w')
						city[p+1][q]='f';
					if((q-1)>=0 && city[p][q-1]!='w')
						city[p][q-1]='f';
					if((q+1)<=N-1 && city[p][q+1]!='w')
						city[p][q+1]='f';
				}
			}
		}
	}
}
char movement(char** city,int x,int y,int N,int charge,int time)
{
	int min,x_id,y_id,prev=N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(city[i][j]=='f'){
				x_id=abs(x-i);
				y_id=abs(y-j);
				min=min(x_id,y_id);
				if(min<prev){
					x_id=i;
					y_id=j;
					prev=min;
				}
			}
		}
	}
	if(){
		
	}
}

int main()
{
	int iter,Num_Test;
	freopen("burning.in","r",stdin);
	cin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,C,H,Sx,Sy;
		cin>>N>>C>>H>>Sx>>Sy;
		char** city=new char*[N];
		for(int i=0;i<N;i++)
			city[i]=new char[N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cin>>city[i][j];
		}
		int x,y,time=0;
		x=Sx-1;
		y=Sy-1;
		bool blast=false;
		vector<char> stream;
		for(int i=1;i<=H;i++){
		/*	present_city();
			time=fire_dis();
			if(H>time)
				blast;
			else
				leave;
				find_nearest_dir();
			Update the stream
			*/
			if(time>=C)
				blast=true;
			if(update_blast(city,blast,x,y,N)){
				blast=false;
				time=0;
			}
			update_fire(city,i,N);
			time++;
			stream.push_back(movement(city,x,y,N,C,time));
		}
	}
	return 0;
}