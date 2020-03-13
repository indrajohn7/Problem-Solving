#include<bits/stdc++.h>
    
	using namespace  std;

    int appearanceCount(int input1,int input2,char* input3,char* input4)
    {
        //Write code here
        int *arr =new int[52];
        int res;
		res=0;
        for(int i=0;i<52;i++)
            arr[i]=0;
        
        for(int i=0;i<input1;i++){
            if(isupper(input3[i]))
                arr[input3[i]-'A'+26]++;
            else
                arr[input3[i]-'a']++;
            
        }
        
		int* temp=new int[52];
	//	temp=arr;
		
		for(int i=0;i<input2-input1+1;i++){
			memcpy(temp,arr,52*sizeof(int));
			int count=0;
			if((isupper(input4[i]) && arr[input4[i]-'A'+26]!=0) || (islower(input4[i]) && arr[input4[i]-'a']!=0)){
				for(int j=i;j<i+input1 && j<input2;j++){
					if((isupper(input4[j]) && temp[input4[j]-'A'+26]!=0)){
						temp[input4[j]-'A'+26]--;
						count++;
					} else if((islower(input4[j]) && temp[input4[j]-'a']!=0)){
						temp[input4[j]-'a']--;
						count++;
					}else{
						break;
					}
				}
				if(count==input1)
					res++;
			}
		}
        
		return res;
		
    }


int main()
{
	cout << "PATTERN :: STRING\n";
	char* tok=new char[3000];
	char* str=new char[3000000];
	memset(tok,'\0',3000);
	memset(str,'\0',3000000);
	cin>>tok>>str;
	int res=appearanceCount(strlen(tok),strlen(str),tok,str);
	cout<<res<<endl;
	return 0;
}
