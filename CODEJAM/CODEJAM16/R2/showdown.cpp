#include<bits/stdc++.h>

#define SIZE pow(2,12)
using namespace std;

int main()
{
	int Num_Test;
	ifstream fin;
	fin.open("showdown.in");
	fin>>Num_Test;
	for(int iter=0;iter<Num_Test;iter++){
		int N,rock,paper,scissor;
		fin>>N>>rock>>paper>>scissor;
		char winner,second,sec;
		int p,r,s;
		p=paper;
		r=rock;
		s=scissor;
		if(rock==0)
			winner=(paper<=scissor)?'p':'s';
		else if(paper==0)
			winner=(rock<=scissor)?'r':'s';
		else if(scissor==0)
			winner=(paper<=rock)?'p':'r';
		else if(rock<=paper && rock<=scissor && rock!=0)
			winner='r';
		else if(scissor<=paper && scissor<=rock && scissor!=0)
			winner='s';
		else if(paper<=rock && paper<=scissor && paper!=0)
			winner='p';
		if(winner=='r')
			second=(paper<=scissor && paper!=0)?'p':'s';
		else if(winner=='p')
			second=(rock<=scissor && rock!=0)?'r':'s';
		else if(winner=='s')
			second=(paper<=rock && paper!=0)?'p':'r';
		
		int trial=0;
		bool impos=false;
		vector<char*> vec;
		for(int i=0;i<=N;i++){
			if(impos && trial>1)
				break;
			else
				impos=false;
			char* str=new char[(int)pow(2,12)];
			memset(str,'\0',(int)pow(2,12));
			if(i==0){
				if(winner=='r')
					strncpy(str,"R",strlen("R"));
				else if(winner=='p')
					strncpy(str,"P",strlen("P"));
				else if(winner=='s')
					strncpy(str,"S",strlen("S"));
				str[1]='\0';
				vec.push_back(str);
			}
			else{
				int k=0;
				for(int j=0;j<strlen(vec[i-1]);j++,k++){
					if(vec[i-1][j]=='R'){
						if(rock && scissor){
							str[k]='R';
							str[++k]='S';
							if(i==N){
								rock--;
								scissor--;
							}
						}
						else{
							vec.clear();
							vec.erase(vec.begin(),vec.end()); //vec.resize(0);
							i=-1;
							winner=second;
							trial++;
							impos=true;
							paper=p;
							rock=r;
							scissor=s;
							break;
						}
					}
					else if(vec[i-1][j]=='S'){
						if(paper && scissor){
							str[k]='P';
							str[++k]='S';
							if(i==N){
								paper--;
								scissor--;
							}
						}
						else{
							i=-1;
							vec.clear();
							vec.erase(vec.begin(),vec.end()); //vec.resize(0);
							impos=true;
							trial++;
							winner=second;
							paper=p;
							rock=r;
							scissor=s;
							break;
						}
					}
					else if(vec[i-1][j]=='P'){
						if(paper && rock){
							str[k]='P';
							str[++k]='R';
							if(i==N){
								paper--;
								rock--;
							}
						}
						else{
							i=-1;
							vec.clear();
							vec.erase(vec.begin(),vec.end()); //vec.resize(0);
							impos=true;
							trial++;
							winner=second;
							paper=p;
							rock=r;
							scissor=s;
							break;
						}
					}
				}
				str[k+1]='\0';
				if(!impos)
					vec.push_back(str);
			}
		}
		cout<<"CASE	#"<<iter+1<<":";
		if(impos)
			cout<<"IMPOSSIBLE\n";
		else
			cout<<vec[vec.size()-1]<<endl;
	}
	return 0;
}