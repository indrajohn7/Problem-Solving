#include<bits/stdc++.h>

using namespace std;

typedef struct _pos{
	int ID;
	int row;
	int column;
}pos;

typedef struct _image{
	int r;
	int c;
	int** v;
}image;

void flush(int** res)
{
	static int count_col=0,count_row=0;
	for(int i=0;i<10;i++){
		int count=0;
		for(int j=0;j<10;j++){
			if(res[i][j]==1)
				count++;
			else
				break;
		}
		if(count==10){
			count_row++;
			cout<<i<<"th ROW is flushed out for "<<count_row<<" times::\n";
			for(int j=0;j<10;j++)
				res[i][j]=0;
		}
	}
	for(int j=0;j<10;j++){
		int count=0;
		for(int i=0;i<10;i++){
			if(res[i][j]==1)
				count++;
			else 
				break;
		}
		if(count==10){
			count_col++;
			cout<<j<<"th COLUMN is flushed out for "<<count_col<<" times::\n";
			for(int i=0;i<10;i++)
				res[i][j]=0;
		}
	}
}

int main()
{
	ifstream fin;
	freopen("chef.in","r",stdin);
	fin.open("chef_image.in");
	freopen("chef.txt","w",stdout);
	vector<image> vec;
	int Num_Image,fig1,fig2,fig3;
	fin>>Num_Image;
	for(int iter=0;iter<Num_Image;iter++){
		int R,C;
		fin>>R>>C;
		image m;
		m.r=R;
		m.c=C;
		m.v=new int*[R];
		for(int i=0;i<R;i++)
			m.v[i]=new int[C];
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				fin>>m.v[i][j];
		}
		vec.push_back(m);
	}
	vector<int*> commands;
	while(cin>>fig1){
		if(fig1==-1)
			break;		
		int* a=new int[3];
		a[0]=fig1;
		cin>>a[1]>>a[2];
		commands.push_back(a);
	}
	int** res=new int*[10];
	for(int i=0;i<10;i++)
		res[i]=new int[10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			res[i][j]=0;
	}
	vector<pos> ans;
	for(int i=0;i<commands.size();i++){		
		for(int j=0;j<3;j++){	
			pos po;		
			po.ID=j+1;
			po.row=-1;
			po.column=-1;
			int flag=0;
			for(int p=0;p<10;p++){
				for(int q=0;q<10;q++){
					if(res[p][q]==0){
						int count=0;
						flag=0;
						for(int l=p;l<p+vec[commands[i][j]].r && l<10;l++){
							for(int m=q;m<q+vec[commands[i][j]].c && m<10;m++){
								if((vec[commands[i][j]].v[l-p][m-q]==1 && res[l][m]==0) || (vec[commands[i][j]].v[l-p][m-q]==0))
									count++;
							}
							po.row=p+vec[commands[i][j]].r+1;
							po.column=q+1;
							if(count==vec[commands[i][j]].r*vec[commands[i][j]].c){
								for(int l=p;l<p+vec[commands[i][j]].r && l<10;l++){
									for(int m=q;m<q+vec[commands[i][j]].c && m<10;m++){
										if(vec[commands[i][j]].v[l-p][m-q]==1)
											res[l][m]=1;
									}
								}
								flag=1;
									break;
							}
						}
						if(flag==1)
							break;
					}
				}
				if(flag==1)
					break;
			}
			flush(res);
			ans.push_back(po);
		}		
	}
	for(int i=0;i<ans.size();i++){
	//	for(int j=0;j<3;j++){
			cout<<ans[i].ID<<"\t"<<ans[i].row<<"\t"<<ans[i].column<<"\t";
	//	}
		cout<<endl;
	}
	return 0;
}