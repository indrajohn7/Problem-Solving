#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int calculate(char* arr, int len)
{
    vector<char> vec;
    int count=0,max=0;
    for(int i=0;i<len;i++){
        if(arr[i]=='('){
            vec.push_back(arr[i]);
          //  count++;
        }else if(arr[i]==')' && vec.size()>0){
            count++;
            vec.pop_back();
        }else{
            if((2*count)>max)
                max=2*count;
            vec.clear();
            count=0;
        }
        
        if(vec.size()==0){
            if((2*count)>max)
                max=2*count;
        }
    }
    
    if(2*count > max)
        max=2*count;
    
    return max;
}


int main()
{
    char* arr=new char[1000];
    memset(arr,'\0',1000);
    cin>>arr;
    int len=strlen(arr);
    int res=calculate(arr,len);
    cout << res << endl;
    return 0;
}
