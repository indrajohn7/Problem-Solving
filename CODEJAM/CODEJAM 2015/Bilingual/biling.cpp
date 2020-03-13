#include<bits/stdc++.h>

using namespace std;
#define N 3000
#define limit 10

int  read(char a[][limit],char b[N*limit])
{
        int i=0,k=0,j=0;
        while(b[i]!='\0' && b[i]!='\n')
        {
                while(b[i]!='\0' && b[i]!='\n' && b[i]!=' ')
                        a[k][j++]=b[i++];
				a[k][j]='\0';
                if(b[i]==' ')
                        i++;
                k++;
                j=0;
        }
        return k;
}

void Read(char S[][limit],char T[][limit],int lt,int *ls)
{
                int i,j,k,count;
                bool ret=false;
                for(i=0;i<lt;i++)
                {
                        for(j=0;j<*ls;j++)
                        {
                                if(!strcmp(S[j],T[i]))
								{
									ret=true;
									break;
								}
                        }
						if(ret==true)
								break;
                }
                if(ret==true)
                {
                        for(i=0;i<lt;i++)
                        {
                                count=0;
                                for(j=0;j<*ls;j++)
                                {
                                        if(strcmp(S[j],T[i]))
                                        {
                                                count++;
                                        }
                                        else
                                                break;
                                }
                                if(count==*ls)
                                {
                                        strcpy(S[*ls],T[i]);
                                        ++(*ls);
                                }
                        }
                }
}

int compare(char S[][limit],char T[][limit],int lt,int *ls)
{
        int count=0;
        for(int i=0;i<lt;i++)
        {
                for(int j=0;j<*ls;j++)
                {
                        if(!strcmp(S[i],T[j]))
                        { 
							count++;
							break;
						}
                }
        }
        return count;
}


int main()
{
        int Test,iter;
        FILE* fin;
        fin=fopen("infile.in","r");
        fscanf(fin,"%d",&Test);
        for(iter=1;iter<=Test;iter++)
        {
                char Eng[N][limit]={"NULL"};
				char Fren[N][limit]={"NULL"};
				char Eng1[N][limit]={"NULL"};
				char Fren1[N][limit]={"NULL"};
				char buff[N*limit],common[N][limit];
                int num_lines,len_e,len_f,len_s,count,i,count_e,count_f;
                fscanf(fin,"%d\n",&num_lines);
                int arr_s[num_lines-2];
                char Sen[num_lines-2][limit][limit];
                fgets(buff,(N*limit),fin);
                len_e=read(Eng,buff);
                fgets(buff,(N*limit),fin);
                len_f=read(Fren,buff);
                for(i=0;i<num_lines-2;i++)
                {
                        fgets(buff,(N*limit),fin);
                        len_s=read(Sen[i],buff);
                        arr_s[i]=len_s;
                }
                int *le,*lf,*ls,*l_e,*l_f;
                le=&len_e;
                lf=&len_f;
				int lne,lnf;
				for(i=0;i<len_e;i++)
					strcpy(Eng1[i],Eng[i]);
				for(i=0;i<len_f;i++)
					strcpy(Fren1[i],Fren[i]);
				lne=len_e;
				lnf=len_f;
				l_e=&lne;
				l_f=&lnf;
                for(i=0;i<num_lines-2;i++)
                {
                        count_e=compare(Eng,Sen[i],arr_s[i],le);
                        count_f=compare(Fren,Sen[i],arr_s[i],lf);
                        if(count_e>count_f)
                                Read(Eng1,Sen[i],arr_s[i],l_e);
                        else
                                Read(Fren1,Sen[i],arr_s[i],l_f);
                }
                count=compare(Eng1,Fren1,*l_e,l_f);
                cout<<"CASE #"<<iter<<":\t"<<count<<"\n";
        }
        return 0;
}

