#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;
#define X '0'
#define Y '1'
#define N  100000


list<char> Stream;

char* iteration(char* input1)
{
	//Write code here
	 char Sol[200];
        int i=0,j=0,T;
	  memset(Sol,'\0',200);
      memcpy(Sol,input1,strlen(input1));
        while(Sol[i]!='\0')
        {
                if(!(Sol[i]=='N' || Sol[i]=='O' || Sol[i]=='A' || Sol[i]=='I' || Sol[i]=='F'))
                        Sol[i]='0';
                i++;
        }
        cout<<Sol<<"\t"<<strlen(Sol)<<endl;
        char op1,op2,oper;
        op1=op2=oper='3';
        i=0,j=0;
        char Final[20];
        memset(Final,'\0',sizeof(Final));
        for(i=0;i<strlen(Sol);i++)
        {

                if(Sol[i]=='N' || Sol[i]=='A' || Sol[i]=='O' || Sol[i]=='I' ||Sol[i]=='F')
                {
                        Stream.push_front(Sol[i]);
                }
                else
                {
                        if(Sol[i+1]==X || Sol[i+1]==Y)
                        {
                                if(Stream.front()=='N')
                                {
                                        Stream.pop_front();
                                        (Sol[i]==X)?Sol[i]=Y:Sol[i]=X;
                                }
                                                                op1=Sol[i+1];
                                                                op2=Sol[i];
        if(op2=='2' && (Stream.front()!=X && Stream.front()!=Y))
        {
                if(Stream.front()=='N')
                {
                        Stream.pop_front();
                        (op1==X)?Stream.push_front('1'):Stream.push_front('0');
                }
                else
                Stream.push_front(op1);
                cout<<"Inside if:"<<"\n";
        }
        else
        {
                cout<<"Inside else calc"<< "\n";
                if(op2=='2' && (Stream.front()==X || Stream.front()==Y))
                {
                        op2=Stream.front();
                        Stream.pop_front();
                }
                oper=Stream.front();
                Stream.pop_front();
                if(oper=='N')
                {
                        (op2==X)?op2=Y:op2=X;
                        Stream.push_front(op2);
                        Stream.push_front(op1);
                }
                else if(oper=='I')
                {
                        (op2=='1' && op1=='0')?Stream.push_front('0'):Stream.push_front('1');
                }
                else if(oper=='A')
                        (op2=='1' && op1=='1')?Stream.push_front('1'):Stream.push_front('0');
                else if(oper=='O')
                        (op2=='0' && op1=='0')?Stream.push_front('0'):Stream.push_front('1');
                else if(oper == 'F')
                        (op1==op2)?Stream.push_front('1'):Stream.push_front('0');
                else
                {
                        cout<<"Invalid\n";
                        return "Invalid";
                }
        }
                             //   calculate(&Stream,Sol[i+1],Sol[i]);
                                i=i+1;
                        }
                        else
                        {
                                if(Stream.front()=='N')
                                {
                                        (Sol[i]==X)?Sol[i]=Y:Sol[i]=X;
                                        Stream.pop_front();
                                }
                                                        op1=Sol[i];
                                                        op2='2';
        if(op2=='2' && (Stream.front()!=X && Stream.front()!=Y))
        {
                if(Stream.front()=='N')
                {
                        Stream.pop_front();
                        (op1==X)?Stream.push_front('1'):Stream.push_front('0');
                }
                else
                        Stream.push_front(op1);
                cout<<"Inside if:"<<"\n";
        }
        else
        {
                cout<<"Inside else calc"<< "\n";
                if(op2=='2' && (Stream.front()==X || Stream.front()==Y))
                {
                        op2=Stream.front();
                        Stream.pop_front();
                }
                oper=Stream.front();
                Stream.pop_front();
                if(oper=='N')
                {
                        (op2==X)?op2=Y:op2=X;
                        Stream.push_front(op2);
                        Stream.push_front(op1);
                }
                else if(oper=='I')
                {
                        (op2=='1' && op1=='0')?Stream.push_front('0'):Stream.push_front('1');
                }
                else if(oper=='A')
                        (op2=='1' && op1=='1')?Stream.push_front('1'):Stream.push_front('0');
                else if(oper=='O')
                        (op2=='0' && op1=='0')?Stream.push_front('0'):Stream.push_front('1');
                else if(oper == 'F')
                        (op1==op2)?Stream.push_front('1'):Stream.push_front('0');
                else
                {
                        cout<<"Invalid\n";
                        return "Invalid";
                }
        }
                                                        //   calculate(&Stream,Sol[i],'2');
                        }
                }
        }
                int iter=0;
        while(Stream.size()>1)
        {
                op1=Stream.front();
                Stream.pop_front();
                                op2='2';
        if(Stream.front()!=X && Stream.front()!=Y)
        {
                if(Stream.front()=='N')
                {
                        Stream.pop_front();
                        (op1==X)?Stream.push_front('1'):Stream.push_front('0');
                }
                else
                        Stream.push_front(op1);
                cout<<"Inside if:"<<"\n";
        }
        else
        {
                cout<<"Inside else calc"<< "\n";
                if(op2=='2' && (Stream.front()==X || Stream.front()==Y))
                {
                        op2=Stream.front();
                        Stream.pop_front();
                }
                oper=Stream.front();
                Stream.pop_front();
                if(oper=='N')
                {
                        (op2==X)?op2=Y:op2=X;
                        Stream.push_front(op2);
                        Stream.push_front(op1);
                }
                else if(oper=='I')
                {
                        (op2=='1' && op1=='0')?Stream.push_front('0'):Stream.push_front('1');
                }
                else if(oper=='A')
                        (op2=='1' && op1=='1')?Stream.push_front('1'):Stream.push_front('0');
                else if(oper=='O')
                        (op2=='0' && op1=='0')?Stream.push_front('0'):Stream.push_front('1');
                else if(oper == 'F')
                        (op1==op2)?Stream.push_front('1'):Stream.push_front('0');
                else
                {
                        cout<<"Invalid\n";
                        return "Invalid";
                }

        }
               // calculate(&Stream,x,'2');
        }
        if(Stream.front()=='1')
                strncpy(Final,"yes",3);
        else
                strncpy(Final,"NO",2);
        if(Stream.front()=='1') 
            return "Yes";
        else
            return "No";
    //    return Final;

}



int main(int argc,char* argv[])
{	
	char* res=new char[10];
	memset(res,'\0',10);
	res=iteration(argv[1]);
	cout<<res<<endl;
	return 0;
}
