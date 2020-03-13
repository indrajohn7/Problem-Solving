#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Test;
	ifstream fin;
	fin.open("in");
	fin>>Test;
	for(iter=0;iter<Test;iter++)
	{
		int count,i,j,k_len,len,s_len;
		float prob,ans,exp,sum=0,max=0;
		prob=1;
		fin>>k_len;
		fin>>len;
		fin>>s_len;
		float char_count[26]={0};
		char* keys=new char[k_len];
		char* str=new char[s_len];
		fin>>keys;
		fin>>str;
		count=0;
		for(i=0;str[i]!='\0';i++)
		{
			for(j=0;keys[j]!='\0';j++)
			{
				if(str[i]==keys[j])
				{	
					count++;
					break;
				}
			}
		}
		if(count!=len)
			ans=0;
		else
		{
			for(j=0;keys[j]!='\0';j++)
			{
				char_count[keys[j]-'A']++;
			}
			for(j=0;j<26;j++)
				sum=sum+char_count[j];
			if(s_len<len)
				ans=0;
			else
			{
				//char[] target=new char[len];
				char* target=new char[s_len];
				target[0]='\0';
				while(strlen(target)+strlen(str)<=s_len)
				{
					strncat(target,str,len);
				}
				i=0;
				char* dummy=new char[s_len];
				strncpy(dummy,target,strlen(target));
				while(*dummy!='\0')
				{
					if(*(dummy+len-1)!='\0' && !strncmp(dummy,str,len))
						max++;
					dummy=dummy+1;;
				}
				cout<<max<<"\n";
				///calculate probability/////////
				i=0;
				while(str[i]!='\0')
				{
					cout<<prob<<"\n";
					prob=prob*(char_count[str[i]-'A']/sum);
					i++;
				}
				exp=0;
				for(i=1;i<=max;i++)
				{
					exp+=i*pow(prob,i)*pow((1/k_len),s_len-(i*len));
				}
				ans=max-exp;
				cout<<"CASE #"<<iter+1<<"\t"<<ans<<"\n";

			}
		}
	}
	return 0;

}
