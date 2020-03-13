#include<bits/stdc++.h>

using namespace std;

#define MTRS pow(10,6)
#define PI 3.14

int main()
{
	int iter,Num_test;
	ifstream fin;
	fin.open("gallery.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int N,R;
		fin>>N>>R;
		float view=(float)(MTRS/2);
		float** arr=new float*[N];
		for(int i=0;i<N;i++){
			arr[i]=new float[N];
		//	memset(arr[i],0,N*sizeof(float));
		}
		typedef pair<float,float> pff;
		map<float,pff> vmap;
		pff two;
		for(int i=1;i<N;i++){
			for(int j=1;j<N;j++){
				int intercept=(i*MTRS)+(j*MTRS)+(1*MTRS);
				float x_c,y_c;
				x_c=(j*MTRS)+view;
				y_c=(i*MTRS)+view;
				arr[i][j]=intercept;
				pair<float,float> one;
				float b,c;
				b=2*(y_c-x_c-intercept);
				c=pow((y_c-intercept),2)+pow(x_c,2)-pow(R,2);
				float d,x1,x2,y1,y2;
				d=sqrt((pow(b,2))-(8*c));
				x1=(((-1)*b)+d)/4;
				x2=(((-1)*b)-d)/4;
				y1=(-1)*x1+intercept;
				y2=(-1)*x2+intercept;
			//	one.first=(y1-view)/(x1-view);
			//	one.second=(y2-view)/(x2-view);
				one.first=atan2((y1-view),(x1-view))*180/PI;
				one.second=atan2((y2-view),(x2-view))*180/PI;
				if(one.first>one.second)
					swap(one.first,one.second);
				if(i==1 && j==1)
					two=one;
				else{
					map<float,pff>::iterator it=vmap.begin();
					it=vmap.find(one.first);
					if(it==vmap.end()){
						vmap[one.first]=one;
					}else{
						it=vmap.find(one.second);
						if(it==vmap.end())
							vmap[one.second]=one;
					}
				}
			}
		}
		vector<pff> vec;
		vec.push_back(make_pair(0,(asin(R/(pow(10,6)))*180/PI)));
		vec.push_back(two);
		vec.push_back(make_pair(90-(asin(R/(pow(10,6)))*180/PI),90));
		
		map<float,pff>::iterator it=vmap.begin();
		for(it=vmap.begin();it!=vmap.end();it++){
				int flag=0;
				for(int i=0;i<vec.size();i++){
					if((it->second.first > vec[i].first && it->second.second < vec[i].second)) /*&& 
						(it->second.second > vec[i].first && it->second.second < vec[i].second))*/{
							flag=1;
							break;
					}else if((it->second.first > vec[i].second && i!=vec.size()-1 && it->second.second > vec[i+1].first && !(vec[i].second<vec[i+1].first))){
						flag=1;
						break;
					}
				}
				if(flag==0)
					vec.push_back(it->second);
		}
		cout<<"Case #"<<iter+1<<": "<<vec.size()<<endl;
	}
	return 0;
}