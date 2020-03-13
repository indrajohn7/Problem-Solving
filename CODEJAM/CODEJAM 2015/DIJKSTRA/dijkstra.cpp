#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include<math.h>
#include<string.h>


#define INT_1 0
#define INT_I 1
#define INT_J 2
#define INT_K 3
#define X 0
#define N pow(10,12)

char Mat_pos_pos[4][4][3]={"1","i","j","k","i","-1","k","-j","j","-k","-1","i","k","j","-i","-1"};
//char Mat_neg_pos[4][4]={'X','I','J','K','I','1','K','J','J','k','1','I','K','J','i','1'};
//char Mat_neg_neg[4][4]={'','','','','','','','','','','','','','','',''};


void Multi(char* Sol,int init,int end,char final[3])
{
        int Mul=0,a,b,count=0,i;
        char res[3];
        char pos=Sol[init];
//	std::cout<<n<<"\n";
//	char final[2];
        for(i=init;i<=end;i++)
        {
                if(init==end)
		{	
		//	printf("%s\n",(char*)pos);
			final[0]=pos;
			final[1]='\0';
                //        return final;
		}
                else
                {
                        if(Mul==0)
                                a=INT_1;
                        if(Mul==1)
                                a=INT_I;
                        if(Mul==2)
                                a=INT_J;
                        if(Mul==3)
                                a=INT_K;
                        if(Sol[i]=='i')
                                b=INT_I;
                        if(Sol[i]=='j')
                                b=INT_J;
                        if(Sol[i]=='k')
                                b=INT_K;
                        strcpy(res,Mat_pos_pos[a][b]);
                        if(*res=='-')
                                count++;
                        if(!strcmp(res,"i") || !strcmp(res,"-i"))
                                Mul=INT_I;
                        else if(!strcmp(res,"j") || !strcmp(res,"-j"))
                                Mul=INT_J;
                        else if(!strcmp(res,"k") || !strcmp(res,"-k"))
                                Mul=INT_K;
                        else if(!strcmp(res,"1") || !strcmp(res,"-1"))
                                Mul=INT_1;
                }
        }
        if(count%2==0)
        {
                i=0;
		while(res[i] && init!=end)
                        {
                                if(isalnum(res[i]))
				{
				//	printf("%s\n",(char*)(*res));

					final[0]=res[i];
					final[1]='\0';
					fflush(stdout);
					fprintf(stderr, "Final:%s\tINIT:%d\tEND:%d\n",final,init,end);
                                   //     return res;
				}
                                        ++i;
                        }
        }
     	else
		strcpy(final,res);

}


int main(int argc,char* argv[])
{
        freopen(argv[1],"r",stdin);
        freopen("D-large.out","w",stdout);
		int Num_Test,St_1[10000],St_2[10000],j=0,p;
		char* Val_1=new char[3];
		char* Val_2=new char[3];
		char* Val_3=new char[3];
        scanf("%d",&Num_Test);
        for(int p=0;p<Num_Test;p++)
        {
                int num_chars,k=0,flag=0,possibility=0,flag2=0,i;
                unsigned long long int reps,rep_len;
                scanf("%d %llu",&num_chars,&reps);
                char buff[10000];
                scanf("%s",buff);
                rep_len=reps*num_chars;
                char Sol_Stream[rep_len];
                //Solution starts
        //      k=0;
		if(strlen(buff)>1){
                while(reps!=0)
                {
                        i=0;
                        while(i<strlen(buff))
                                Sol_Stream[k++]=buff[i++];
                        reps--;
                }
                k=i=flag=0;
                while(k<rep_len)
                {
                                Multi(Sol_Stream,0,k,Val_1);
//				printf("Val_1:%s\n",Val_1);
                                if(Val_1!=NULL && !strcmp(Val_1,"i"))
                                {
                                        flag++;
                                        St_1[i++]=k;
                                }
                                k++;
                }
                i=0;
		j=0;
                k=St_1[i]+1;
                while(i<flag && flag!=0)
                {
                //      k=St_1[i]+1;
                        while(k<rep_len)
                        {
                                Multi(Sol_Stream,St_1[i]+1,k,Val_2);
//				printf("Val_2:%s\n",Val_2);
                                if(Val_2!=NULL && !strcmp(Val_2,"j"))
                                {
                                        St_2[j++]=k;
                                        flag2++;
                                }
                                k++;
                        }
                        i++;
                }
                j=i=0;
                k=St_2[j]+1;
                while(i<flag2 && flag2!=0)
                {
                                Multi(Sol_Stream,St_2[i]+1,rep_len-1,Val_3);
//				printf("Val_3:%s\n",Val_3);
                                if(Val_3!=NULL && !strcmp(Val_3,"k"))
                                {
                                        possibility=1;
                                        break;
                                }
                                i++;
                }
	}//end if
                char Str[10];
                if(possibility==1)
                        strcpy(Str,"YES");
                else
                        strcpy(Str,"NO");
                printf("Case #%d : %s\n",p+1,Str);

        }
	



return 0;
}



