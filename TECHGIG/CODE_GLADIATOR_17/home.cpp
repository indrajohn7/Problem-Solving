#include<bits/stdc++.h>



int homesteadThatDefinesANewLivingPlanet(int input1,int input2,int input3,int input4,vector < vector < int > > input5)
{
	//Write code here
	
	int col,row,N,K;
	col=input1;
	row=input2;
	N=input3;
	K=input4;
	
	
//	for(int i=0;i<input5.size();i++)
//	    cout<<input5[i][0]<<"\t"<<input5[i][1]<<endl;
	
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
	
//	for(int i=0;i<input5.size();i++)
//	    cout<<input5[i][0]<<"\t"<<input5[i][1]<<endl;
	
	for(int i=0;i<input5.size()/2-1;i++){
	    int start_x,start_y,end_x=input1,end_y=input2,count=1,idx=i,maxi=0;
	    int x_min,y_min,x_max,y_max;
	    x_min=x_max=start_x=input5[i][0];
	    y_min=y_max=start_y=input5[i][1];
	    while(count!=K && idx<input5.size()/2){
	        int area=2*((end_x-start_x+1)+(end_y-start_y+1));
	        for(int j=idx+1;j<input5.size();j++){
	            if(area>(2*((abs(input5[j][0]-start_x)+1)+(abs(input5[j][1]-start_y)+1)))){
	                idx=j;
	                cout<<"AREA::"<<area<<"\t"<<j<<endl;
	                x_min=min(x_min,input5[j][0]);
	                x_max=max(x_max,input5[j][0]);
	                y_min=min(y_min,input5[j][1]);
	                y_max=max(y_max,input5[j][1]);
	                area=2*((abs(input5[j][0]-start_x)+1)+(abs(input5[j][1]-start_y)+1));
	                cout<<"AREA::"<<area<<"\t"<<j<<endl;
	            }
	        }
	        count++;
	    }
	    cout<<"DEBUG:"<<endl;
	    cout << x_min<<"\t"<<y_min<<"\t"<<x_max<<"\t"<<y_max<<"\t"<<count<<endl;
	    if(count==K){
	       // max=(abs(start_x-input5[idx][0])+1)*(abs(start_y-input5[idx][1])+1);
	        maxi=2*((x_max-x_min+1)+(y_max-y_min+1));
	        count=1;
	      //  idx+=1;
	        x_min=x_max=start_x=input5[idx+1][0];
	        y_min=y_max=start_y=input5[idx+1][1];
	        while(count!=K && idx<input5.size()){
	         int area=2*((end_x-start_x+1)+(end_y-start_y+1));
	           for(int j=idx+1;j<input5.size();j++){
	             if(area>2*(((abs(input5[j][0]-start_x)+1)+(abs(input5[j][1]-start_y)+1)))){
	                x_min=min(x_min,input5[j][0]);
	                x_max=max(x_max,input5[j][0]);
	                y_min=min(y_min,input5[j][1]);
	                y_max=max(y_max,input5[j][1]);
	                idx=j;
	                cout<<"AREA::"<<area<<"\t"<<j<<endl;
	                area=2*((abs(input5[j][0]-start_x)+1)+(abs(input5[j][1]-start_y)+1));
	                cout<<"AREA::"<<area<<"\t"<<j<<endl;
	               }
	            }
	            count++;
	        }
	    }
	    
	    cout << x_min<<"\t"<<y_min<<"\t"<<x_max<<"\t"<<y_max<<"\t"<<count<<endl;
	    
	    if(count==K){
	        maxi+=2*((abs(x_min-x_max)+1)+(abs(y_min-y_max)+1));
	        if(maxi < res)
	            res=maxi;
	    }
	    
	   
	}
	
	if(res==pow(10,9)){
	    cout<<"0"<<endl;
	    return 0;
	}
	else{
	    cout<<res<<endl;
	    return res;
	}
	   
	    
}
	

