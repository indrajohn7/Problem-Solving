#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("energy.in");
	ofstream fout;
	fout.open("energy.out");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int E,R,N,use,i;
		fin>>E>>R>>N;
		int v[N],u[N];
		//long long int max=0;
		for(i=0;i<N;i++){
			fin>>v[i];
		}
		use=E;
		//u[0]=E;
		long long int gain=0,sum=0,max=0;
	//	sort(v,v+N-1);
		if(E<=R){
			for(i=0;i<N;i++){
				sum+=v[i];
				u[i]=v[i];
			}
			gain=sum*E;
		}
		else{
			for ( i = 0; i < N; ++i) 
                u[i] = R;
            for ( i =0; i<N-1; i++) {
                if(v[i+1]>v[i]){
					if(use+R-E>0){
					u[i]=R;//-E+R;
					use=use-u[i]+R;
					}
					else{
						u[i]=0;
						use=use+R;
					}
				}
				else{
					if(u[i]+u[i+1]<=E){
						u[i]+=u[i+1];
						u[i+1]=0;
						use=E-u[i]+2*R;
						i++;
					}
					else{
						u[i]=E;
						use=R;
					}
				}
            }
			if(v[i]<v[i-1])
				u[i]=R;
			else
				u[i]=E;
			for(i=0;i<N;i++)
		    	gain+=v[i]*u[i];
		}
        for (int i = 0; i < N; ++i)
            cout << u[i] << " ";
        cout << endl;
        		
		fout<<"Case #"<<iter+1<<": "<<gain<<endl;
	}
	return 0;
}