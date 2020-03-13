#include<bits/stdc++.h>

using namespace std;
typedef struct _pos{
	int bf;
	bool used;
}pos;

typedef std::pair<int,int> intpair;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("bff.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,conn;
		fin>>N;
		vector<pos> arr(N+1);
		for(int i=1;i<=N;i++){
			fin>>arr[i].bf;
			arr[i].used=false;
		}
		vector<intpair> c;
		for(int i=1;i<=N;i++){
			if(i==arr[arr[i].bf].bf)
				c.push_back(make_pair(i,arr[i].bf));
		}		
		int max=0;
		for(int i=1;i<=N;i++){
			int flag=0,open_f=i,open_r=i;
			arr[0].bf=-1;
			for(int j=1;j<=N;j++){
				if(arr[j].bf==i)
					flag=1;
				arr[j].used=false;  //reset used
			}
			if(flag==0)
				continue;
			vector<int> vec;
			vec.push_back(i);
		//	arr[i].used=true;
			while(arr[open_r].bf!=open_f){
				int rotate=0;
				if(arr[vec[vec.size()-1]].used==false){
				//	open_r=arr[i].bf;
				    arr[open_r].used=true;
					vec.push_back(arr[open_r].bf);
					open_r=vec[vec.size()-1];
				//	arr[open_r].used=true;
				    if(arr[arr[open_r].bf].used==true)
						arr[open_r].used=true;
					rotate=1;
				}
				else {
					int l;
					arr[open_r].used=true;
				    for(l=1;l<=N;l++){
						if(arr[l].bf==vec[vec.size()-1] && arr[l].used==false){
							vec.push_back(l);
							arr[l].used=true;
							open_r=l;
							rotate=1;
							break;
						}
					}
				}
				if(rotate==0){
					for(int l=0;l<c.size();l++){
						if(arr[c[l].first].used==false && arr[c[l].second].used==false){
							vec.push_back(arr[c[l].first].bf);
							vec.push_back(arr[c[l].second].bf);
							arr[c[l].first].used=true;
							arr[c[l].second].used=true;
						}
					}
					for(int l=1;l<=N;l++){
							if(arr[l].bf==vec[0] && arr[l].used==false){
								vec.push_back(l);
								open_r=l;
							}
						}
				}
			}
			if(vec.size()==2){
				for(int l=0;l<c.size();l++){
						if(arr[c[l].first].used==false && arr[c[l].second].used==false){
							vec.push_back(arr[c[l].first].bf);
							vec.push_back(arr[c[l].second].bf);
							arr[c[l].first].used=true;
							arr[c[l].second].used=true;
						}
					}
			}
			if(vec.size()>max)
				max=vec.size();
			if(max==N)
				break;
		}
		cout<<"CASE #"<<iter+1<<" :"<<max<<endl;
	}
	return 0;
}