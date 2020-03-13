#include<bits/stdc++.h>

using namespace std;

typedef struct _peg{
		int check;
		char arrow;}peg;
		
		bool stat=false;
		
//extern int R,C;

bool isedge_hit(peg arr[][100],int r,int c,int R ,int C)
{
	if(r==0 && c==0 && (arr[r][c].arrow=='^' || arr[r][c].arrow=='<'))
		return true;
	else if(r==0 && c==C-1 && (arr[r][c].arrow=='^' || arr[r][c].arrow=='>'))
		return true;
	else if(r==0  && arr[r][c].arrow=='^')
		return true;
	else if(c==0 && arr[r][c].arrow=='<' )
		return true;
	else if(r==R-1 && c==0 && (arr[r][c].arrow=='v' || arr[r][c].arrow=='<'))
		return true;
	else if(r==R-1 && c==C-1 && (arr[r][c].arrow=='v' || arr[r][c].arrow=='>'))
		return true;
	else if(r==R-1 && c==0 && (arr[r][c].arrow=='v' || arr[r][c].arrow=='<'))
		return true;
	else if(r==R-1 && c==C-1 && (arr[r][c].arrow=='v' || arr[r][c].arrow=='>'))
		return true;
	else if(r==R-1 && arr[r][c].arrow=='v')
		return true;
	else if(c==C-1 &&  arr[r][c].arrow=='>')
		return true;
	else 
		return false;
}

int Traverse(peg arr[][100],int r,int c,bool* status,int flag,int R,int C)
{
        static int count=0;
		bool s=false;
        bool *stats = &s;
	//	*stat=false;
        static char last_arr='.';
		char possib[4]={'v','^','<','>'};
		static char used[4]={'.','.','.','.'};
		
		static int last_r,last_c,k;
		if(flag==0 )
			k=0;
		int l_r,l_c,i,j;
        (flag==0)?last_arr='.':last_arr=last_arr;
		if(flag!=1)
		{
			for(i=0;i<R;i++)
                {
                        for(j=0;j<C;j++)
                                arr[i][j].check=0;
                }
		}
        if(r!=0 && r!=R-1 && c!=0 && c!=C-1)
        {
               
                       
					   
						 if(arr[r][c].arrow!='.')
						{
							if(arr[r][c].check==1)
							{
								*status=true;
								stat=true;
								return count;
							}
							last_arr=arr[r][c].arrow;
							last_r=r;
							last_c=c;
							arr[r][c].check=1;
						}
                        if(last_arr=='v')
                                Traverse(arr,r+1,c,stats,1,R,C);
                        else if(last_arr=='^')
                                Traverse(arr,r-1,c,stats,1,R,C);
                        else if(last_arr=='>')
                                Traverse(arr,r,c+1,stats,1,R,C);
                        else if(last_arr=='<')
                                Traverse(arr,r,c-1,stats,1,R,C);
        }
        else 
		{
				if(arr[r][c].arrow=='.')
				{
						l_r=last_r;
						l_c=last_c;
						while(k<4)
						{
							if(arr[l_r][l_c].arrow!=possib[k])
							{
								arr[l_r][l_c].arrow=possib[k];
								//count++;
								k++;
								count=Traverse(arr,l_r,l_c,status,2,R,C);
							//	if(*status==false && arr[l_r][l_c].check!=1)
								//	count--;
								if(*status==true)// && arr[l_r][l_c].check==1)
								{	
									count++;
									*status=true;
									stat=true;
									return count;
								}
							
							}
						}
						if(k>=4)
						{
							*status=false;
							stat=false;
							return count;
						}
						
				}
				else{
					if(isedge_hit(arr,r,c,R,C))
					{
						l_r=r;l_c=c;
						while(k<4)
						{
							if(arr[l_r][l_c].arrow!=possib[k])
							{
								arr[l_r][l_c].arrow=possib[k];
							//	count++;
								k++;
								count=Traverse(arr,l_r,l_c,status,2,R,C);
							//	if(*status==false && arr[l_r][l_c].check!=1)
								//	count--;
							if(*status==true || stat==true)// && arr[l_r][l_c].check==1)
								{	
									count++;
									*status=true;
									stat=true;
									return count;
								}
							}
						}
						if(k>=4)
						{
							*status=false;
							stat=false;
							return count;
						}
						
					}
					else{
						 if(arr[r][c].arrow!='.')
						{
							if(arr[r][c].check==1)
							{	
								*status=true;
								stat=true;
								return count;
							}
							last_arr=arr[r][c].arrow;
							last_r=r;
							last_c=c;
							arr[r][c].check=1;
						}
						if(arr[r][c].arrow=='v')
                                Traverse(arr,r+1,c,stats,1,R,C);
                        else if(arr[r][c].arrow=='^')
                                Traverse(arr,r-1,c,stats,1,R,C);
                        else if(arr[r][c].arrow=='>')
                                Traverse(arr,r,c+1,stats,1,R,C);
                        else if(arr[r][c].arrow=='<')
                                Traverse(arr,r,c-1,stats,1,R,C);	
					}
					
				}
		}
}



int main()
{
        ifstream fin;
        fin.open("infile.in");
        int NUM_TEST,iter,flag;
        fin>>NUM_TEST;
		int count_iter[NUM_TEST];
        for(iter=0;iter<NUM_TEST;iter++)
        {
                int i,j,count,R,C,res=0,check=0;
                fin>>R>>C;
                peg arr[100][100];
				bool s=true;
                bool* status =&s;
				stat=false;
			//	*status=false;
                for(i=0;i<R;i++)
                {
                        for(j=0;j<C;j++)
                                fin>>arr[i][j].arrow;
                }
                for(i=0;i<R;i++)
                {
						flag=0;
                        for(j=0;j<C;j++){
								if(arr[i][j].arrow!='.'){
									check=1;
									stat=false;
									count_iter[iter]=Traverse(arr,i,j,status,0,R,C);
                                if(stat==false)
								{
										flag=1;
                                        break;
								}
								flag=0;
									}
									
                                }
                        if(stat==false && flag==1)
                                break;
                }
				if(check==0)
					count_iter[iter]=count_iter[iter-1];
				if(*status==true && iter==0)
					cout<<"CASE #"<<iter+1<<"\t"<<count_iter[iter]<<"\n";
				else if(*status==true && iter!=0)
					cout<<"CASE #"<<iter+1<<"\t"<<count_iter[iter]-count_iter[iter-1]<<"\n";
				else
					cout<<"CASE #"<<iter+1<<"\t"<<"IMPOSSIBLE"<<"\n";
        }
		return 0;
		
}

