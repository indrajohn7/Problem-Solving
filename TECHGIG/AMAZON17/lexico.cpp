#include<bits/stdc++.h>

using namespace std;

vector<char> vec;

void PRINT_LCS(char** b,char X[100],int x, int y)
{
        if(x==0 || y==0)
                return;
        else if(b[x][y]=='$'){
                PRINT_LCS(b,X,x-1,y-1);
                cout<<X[x-1];
				vec.push_back(X[x-1]);
        }
        else if(b[x][y]=='^')
                PRINT_LCS(b,X,x-1,y);
        else if(b[x][y]=='<')
                PRINT_LCS(b,X,x,y-1);
}


char* longestIncreasingSubsequence(char* input1)
{
	int len=strlen(input1);
	int arr[26];
	char** b=new char*[len+1];
	int** c=new int*[len+1];
	for(int i=0;i<len+1;i++){
		b[i]=new char[len+1];
		c[i]=new int[len+1];
	}
	for(int i=0;i<=len;i++){
		for(int j=0;j<=len;j++){
			c[i][j]=0;
        }
    }
	for(int i=0;i<26;i++)
		arr[i]=0;
	for(int i=0;i<len;i++){
		input1[i]=tolower(input1[i]);
		arr[input1[i]-'a']++;
	}
	char* dummy=new char[len+1];
	int k=0;
	for(int i=0;i<26;i++){
		for(int j=0;j<arr[i];j++)
			dummy[k++]='a'+i;
	}
	dummy[k]='\0';
	
	
	for(int i=1;i<=len;i++)
        {
                for(int j=1;j<=len;j++){
                        if(dummy[i-1]==input1[j-1]){
                                c[i][j]=c[i-1][j-1]+1;
                                b[i][j]='$';
                        }
                        else if(c[i-1][j]>=c[i][j-1]){
                                c[i][j]=c[i-1][j];
                                b[i][j]='^';
                        }
                        else{
                                c[i][j]=c[i][j-1];
                                b[i][j]='<';
                        }
                }
        }
		
		PRINT_LCS(b,dummy,len,len);
		char* res=new char[len+1];
		int i=0;
		for(i=0;i<vec.size();i++)
			res[i]=vec[i];
		res[i]='\0';
        cout<<"\n";
		return res;
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