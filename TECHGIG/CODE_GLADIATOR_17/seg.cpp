#include<bits/stdc++.h>

using namespace std;


void minimum(vector < vector < int > > arr, vector<int> vec, int* mini_x,int* maxi_x, int* mini_y,int* maxi_y)
{
	*mini_x=*maxi_x=arr[vec[0]][0];
	*mini_y=*maxi_y=arr[vec[0]][1];
	for(int i=0;i<vec.size();i++){
		*mini_y=min(*mini_y,arr[vec[i]][1]);
		*maxi_y=max(*maxi_y,arr[vec[i]][1]);
		*mini_x=min(*mini_x,arr[vec[i]][0]);
		*maxi_x=max(*maxi_x,arr[vec[i]][0]);
	}
}

bool in_first_section(pair<int,int> x_p, pair<int,int> y_p,vector < vector < int > > arr, int pos)
{
	if(arr[pos][0] >= x_p.first && arr[pos][0] <= x_p.second){
		if(arr[pos][1] >= y_p.first && arr[pos][1] <= y_p.second)
			return true;
		else
			return false;
	}
	
	return false;
}


int homesteadThatDefinesANewLivingPlanet(int input1,int input2,int input3,int input4,vector < vector < int > > input5)
{
	//Write code here
	
	int col,row,N,K;
	col=input1;
	row=input2;
	N=input3;
	K=input4;
	
	
	
	for(int i=0;i<input5.size();i++){
	    for(int j=0;j<input5.size()-1;j++){
	        if(input5[j][0]>input5[j+1][0]){
	           // int t1,t2;
	            vector<int> v;
	            v=input5[j];
	            input5[j]=input5[j+1];
	            input5[j+1]=v;
	            
	            
	        }else if(input5[j][0]==input5[j+1][0] && input5[j][1]>input5[j+1][1]){
	            vector<int> v;
	            v=input5[j];
	            input5[j]=input5[j+1];
	            input5[j+1]=v;
	        }
	    }
	}
	
	int res=pow(10,9);
	
	
	for(int i=0;i<input5.size()/2-1;i++){
	    int start_x,start_y,end_x=input1,end_y=input2,count=1,idx=i,maxi=0;
	    int x_min,y_min,x_max,y_max;
	    x_min=x_max=start_x=input5[i][0];
	    y_min=y_max=start_y=input5[i][1];
		vector<int> vec;
		vec.push_back(i);
		
		int* arr= new int[input5.size()];
		for(int p=0;p<input5.size();p++)
			arr[p]=0;
	    arr[i]=1;
		while(count!=K && idx<input5.size()/2){
	        int area=pow(10,9); //2*((end_x-start_x+1)+(end_y-start_y+1));
			int y_mn,y_mx,x_mn,x_mx;
			
			minimum(input5,vec,&x_mn,&x_mx,&y_mn,&y_mx);
			
	        for(int j=i+1;j<input5.size();j++){  //initially traversing from j=idx+1 --> changed to j=i+1..
				if(arr[j]==1)
					continue;
				int dummy_x_min,dummy_y_min,dummy_x_max,dummy_y_max;
				dummy_x_min=min(x_mn,input5[j][0]);
				dummy_y_min=min(y_mn,input5[j][1]);
				dummy_x_max=max(x_mx,input5[j][0]);
				dummy_y_max=max(y_mx,input5[j][1]);
				
	            if(area>(2*((dummy_x_max-dummy_x_min+1)+(dummy_y_max-dummy_y_min+1)))){  //check for dynamic area with x_min/max 
	                idx=j;
	                cout<<"AREA::"<<area<<"\t"<<j<<endl;
	                x_min=min(x_mn,input5[j][0]);
	                x_max=max(x_mx,input5[j][0]);            //calculate exact x_min/x_max/y_min/y_max
	                y_min=min(y_mn,input5[j][1]);
	                y_max=max(y_mx,input5[j][1]);
	                area=(2*((dummy_x_max-dummy_x_min+1)+(dummy_y_max-dummy_y_min+1)));
	                cout<<"AREA::"<<area<<"\t"<<j<<endl;
	            }
	        }
			vec.push_back(idx);
			arr[idx]=1;
	        count++;
	    }
		vec.clear();
	    cout<<"DEBUG:"<<endl;
	    cout << x_min<<"\t"<<y_min<<"\t"<<x_max<<"\t"<<y_max<<"\t"<<count<<endl;
		
		typedef pair<int,int> pii;
		pii x_p,y_p;
		x_p=make_pair(x_min,x_max);
		y_p=make_pair(y_min,y_max);
		
	    if(count==K && idx<input5.size()){   //check for segment boundary conditions
	       // max=(abs(start_x-input5[idx][0])+1)*(abs(start_y-input5[idx][1])+1);
	        maxi=2*((x_max-x_min+1)+(y_max-y_min+1));
	        count=1;
	        idx+=1;
	        x_min=x_max=start_x=input5[idx][0];
	        y_min=y_max=start_y=input5[idx][1];
			
			vec.push_back(idx);
			arr[idx]=1;
	        while(count!=K && idx<input5.size()){
	         int area=pow(10,9); //2*((end_x-start_x+1)+(end_y-start_y+1));
			 
			 int y_mn,y_mx,x_mn,x_mx;
			
			 minimum(input5,vec,&x_mn,&x_mx,&y_mn,&y_mx);
	           for(int j=i+1;j<input5.size();j++){
				   if(arr[j]==1 || in_first_section(x_p,y_p,input5,j))
					continue;
				int dummy_x_min,dummy_y_min,dummy_x_max,dummy_y_max;
				dummy_x_min=min(x_mn,input5[j][0]);
				dummy_y_min=min(y_mn,input5[j][1]);
				dummy_x_max=max(x_mx,input5[j][0]);
				dummy_y_max=max(y_mx,input5[j][1]);
				
	             if(area>(2*((dummy_x_max-dummy_x_min+1)+(dummy_y_max-dummy_y_min+1)))){
	                x_min=min(x_mn,input5[j][0]);
	                x_max=max(x_mx,input5[j][0]);            //calculate exact x_min/x_max/y_min/y_max
	                y_min=min(y_mn,input5[j][1]);
	                y_max=max(y_mx,input5[j][1]);
	                idx=j;
	                cout<<"AREA::"<<area<<"\t"<<j<<endl;
	                area=(2*((dummy_x_max-dummy_x_min+1)+(dummy_y_max-dummy_y_min+1)));
	                cout<<"AREA::"<<area<<"\t"<<j<<endl;
	               }
	            }
	            count++;
				vec.push_back(idx);
				arr[idx]=1;
	        }
	    }else if(count!=K){
			count=0;
		}
	    
		vec.clear();
	    cout << x_min<<"\t"<<y_min<<"\t"<<x_max<<"\t"<<y_max<<"\t"<<count<<endl;
	    
	    if(count==K){
	        maxi+=2*((abs(x_min-x_max)+1)+(abs(y_min-y_max)+1));
	        if(maxi < res)
	            res=maxi;
	    }
	}
	
	if(res==pow(10,9))
	    return 0;
	else
	   return res;
	    
	}

int main() {
    int output;
    int ip1;
	freopen("seg.in","r",stdin);
    cin >> ip1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip2;
    cin >> ip2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip3;
    cin >> ip3;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip4;
    cin >> ip4;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip5_rows = 0;
    int ip5_cols = 0;
    cin >> ip5_rows >> ip5_cols;
    vector< vector < int > > ip5(ip5_rows);
    for(int ip5_i=0; ip5_i<ip5_rows; ip5_i++) {
        for(int ip5_j=0; ip5_j<ip5_cols; ip5_j++) {
            int ip5_tmp;
            cin >> ip5_tmp;
            ip5[ip5_i].push_back(ip5_tmp);
        }
    }
    output = homesteadThatDefinesANewLivingPlanet(ip1,ip2,ip3,ip4,ip5);
    cout << output << endl;
    return 0;
}
