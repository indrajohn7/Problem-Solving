#include<bits/stdc++.h>
  
using namespace std; 
 
 typedef struct _out{
    int count;
    vector<int> v;
 }out;
  
  
  int calculate_max(vector<out> vout,vector<char> stream,char N/*(input1[j]-'a')*/,int j)
  {
	  int pos;
	  for(int i=0;i<stream.size();i++){
		  if(stream[i]==N){
			  pos=i;
			  break;
		  }
	  }
	  int count=0;
	  for(int i=pos;i<vout.size();i++){
		  for(int k=0;k<vout[i].v.size();k++){
			  if(vout[i].v[k]-j == 1){
				  j=vout[i].v[k];
				  count++;
			  }				  
		  }
		  
	  }
	  return count;
  }
  
  
    char* longestIncreasingSubsequence(char* input1)
    {
        //Write code here
        out arr[26];
        vector<out> vout;
		
		for(int i=0;i<26;i++){
			arr[i].count=0;
		}
		
        for(int i=0;i<strlen(input1);i++){
			input1[i]=tolower(input1[i]);
             int pos=tolower(input1[i])-'a';
            arr[pos].count++;
            arr[pos].v.push_back(i);
        }
        
        vector<char> stream;
        
        for(int i=0;i<26;i++){
            if(arr[i].count==0)
                continue;
            vout.push_back(arr[i]);
            stream.push_back('a'+i);
        }
        
        vector<char> vec;
		vector<int> fin;
		
        int max=0,idx;
        for(int i=0;i<vout.size();i++){
			
            int count=0;
            int pos=vout[i].v[0];
			
            for(int j=i;j<vout.size();j++){
              //  if(vout[j].v[0]>=pos){
                    for(int k=0;k<vout[j].v.size();k++){
                        if(vout[j].v[k]-pos==1){
							count+=1;
							pos=vout[j].v[k];
						}
                    }
               // }
            }
            if(count>max){
                idx=i;
				max=count;
            }
           
        }
        
        vec.push_back(stream[idx]);
        
      //  for(int i=0;i<)

        char* temp=strchr(input1,stream[idx]);
		int k=temp-input1;
		for(int i=k+1;i<strlen(input1);i++){
            char c=input1[i];
			int flag=0;
			if(input1[i]<vec[vec.size()-1])
				continue;
            for(int j=i+1;j<strlen(input1);j++){
                if(input1[j]<input1[i] && input1[j]>=vec[vec.size()-1]){
					if(j==i+1){
						vec.push_back(input1[j]);
						i=j;
						flag=1;
						break;
					}/*else if((j-i)<=(strlen(input1)-j)){ //check here
						vec.push_back(input1[j]);
						i=j;
						flag=1;
						break;
					}*/else{
						
						if(calculate_max(vout,stream,(input1[j]),j) >=
							calculate_max(vout,stream,(input1[i]),i)){
							
							vec.push_back(input1[j]);
							i=j;
							flag=1;
							break;
						}else{
							vec.push_back(input1[i]);
							//i=j;
							flag=1;
							break;
						}
					}
					//call an API which will calculate the max number and return the decide on that
				}
            }
			if(flag==0){
				vec.push_back(input1[i]);
			}
		}
		
		char* ip1;
		int i=0;
		ip1 = (char *)malloc(512000 * sizeof(char));
		memset(ip1,'\0',512000);
		for(i=0;i<vec.size();i++)
			ip1[i]=vec[i];
		ip1[i]='\0';
        
		return ip1;
    }
	
	
	int main() 
	{
    char* output;
    char* ip1;
    ip1 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip1);
    output = longestIncreasingSubsequence(ip1);
    printf("%s\n", output);
    return 0;
}