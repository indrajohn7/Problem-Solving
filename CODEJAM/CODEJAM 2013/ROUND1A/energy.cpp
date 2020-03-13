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
		u[0]=E;
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
			 for ( i = 1; i < N; ++i) {
            u[i] = R;
            for (int j = i - 1; j >= 0; --j) {
                if (v[j] >= v[i])
                    break;
                if (u[j] + u[i] <= E) {
                    u[i] += u[j];
                    u[j] = 0;
                }else {
                    u[j] -= E - u[i];
                    u[i] = E;
                    break;
                }
            }
        }
			
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