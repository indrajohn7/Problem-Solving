#include<stdlib.h>

int arr[100][100]={0};
int arr2[100][100]={0};
int r,c,s1,s2,b1,b2,g;

int getLiving(int i, int j, int r2, int c2){
    int count=0;

    /*
    if(i>0 && arr[i-1][j]==1)
        count++;
    
    if(j>0 && arr[i][j-1]==1)
        count++;
        
    if(i>0 && j>0 && arr[i-1][j-1]==1)
        count++;
        
    if(i>0 && j<c2 && arr[i-1][j+1]==1)
        count++;
        
    if(j>0 && i<r2 && arr[i+1][j-1]==1)
        count++;
    
	*/
	
	for(int p=i-1;p<=i+1;p++){
		for(int q=j-1;q<=j+1;q++){
			if(p>=0 && p<r2 && q>=0 && q<c2 && arr[p][q]==1){
				count++;
			}
		}
	}

        
    return count;
}

void simulate(int n){
    int i,j;
   
    if(n==g)
    return;
    
    for(i=0; i<r;i++){
        for(j=0;j<c; j++){
            
            if(arr[i][j]==0){
               if(getLiving(i,j,r,c)<=b2 && getLiving(i,j,r,c)>=b1)
                arr2[i][j]=2;
            }
            
            if(arr[i][j]==1){
                if(getLiving(i,j,r,c)<s1 || getLiving(i,j,r,c)>s2)
                arr2[i][j]=3;
            }
        }
    }
    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            
            if(arr2[i][j]==2){
            arr[i][j]=1;
            arr2[i][j]=0;
                
            }
            
            if(arr2[i][j]==3){
                
            arr[i][j]=0;
            arr2[i][j]=0;
            }
        }
        
    }
    
    simulate(n+1);
}
 


    int* survivalcells(int input1_size, int* input1,int input2_size, int* input2,int* output_size)
{
   // static int output2[]={0,1,1,1,0,0,0,1,0,0,1,0};
                *output_size=input2_size;
                int i,j,temp;
                int *output1;
               
                r=input1[0];
                c=input1[1];
                s1=input1[2];
                s2=input1[3];
                b1=input1[4];
                b2=input1[5];
                g=input1[6];
                
                temp=r*c;
                output1=new int[temp];
                temp=0;
                for(i=0;i<r;i++){
                    for(j=0;j<c;j++)
                    arr[i][j]=input2[temp++];
                }
                
                simulate(0);
                
                temp=0;
                for(i=0;i<r;i++){
                    for(j=0;j<c;j++){
                        output1[temp++]=arr[i][j];
                    }
                }
                
                return output1;
               
               
}