#include<bits/stdc++.h>

using namespace std;

#define MTRS pow(10,6)

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
		float* arr=new float*[N];
		for(int i=0;i<N;i++){
			arr[i]=new float[N];
			memset(arr[i],0,N*sizeof(float));
		}
		typedef pair<float,float> pff;
		map<float,pff> vmap;
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
				c=pow((y_c-intercept),2)-pow(x_c,2)-pow(r,2);
				float d,x1,x2,y1,y2;
				d=sqrt((pow(b,2))-(8*c));
				x1=(((-1)*b)+d)/4;
				x2=(((-1)*b)-d)/4;
				y1=(-1)*x1+intercept;
				y2=(-1)*x2+intercept;
				one.first=(y1-view)/(x1-view);
				one.second=(y2-view)/(x2-view);
				map<float,pff>::iterator it=vmap.begin();
				it=vmap.find(one.first);
				if(it==vmap.end()){
					vmap[one.first]=one;
				}
			}
		}
		
		cout<<"Case #"<<iter+1<<": "<<vmap.size()<<endl;
	}
	return 0;
}