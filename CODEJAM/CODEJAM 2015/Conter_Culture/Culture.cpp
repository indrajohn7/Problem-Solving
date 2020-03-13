#include<bits/stdc++.h>

using namespace std;


int lengthint(long long N)
{
        int count=0;
        while(N!=0)
        {
                N=N/10;
                count++;
        }
        return count;
}


long long reverse(long long N)
{
        long long sum=0;
        while(N!=0)
        {
                sum=sum*10+N%10;
                N=N/10;
        }
        return sum;

}

bool samedigit(long long N)
{
        long long flag=0;
        flag=reverse(N);
        if(flag==N)
                return false;
        else return true;
}


int main()
{
        int Num_Test,iter;
        ifstream fin;
        fin.open("Culture.in");
//              FILE* fout=freopen("culture.out","w",stdout);
        fin>>Num_Test;
        for(iter=0;iter<Num_Test;iter++)
        {
                int i=0,length=0,temp_length=0,f_d;
                long long  num,temp;
                long long  N=1;
                long long  count=1;
                long long sum=1;
                N=1;
                fin>>num;
                temp=num;
                length=lengthint(temp);
		while(temp!=0)
		{
			f_d=temp%10;
			temp=temp/10;
		}
		cout<<length<<"\n";
                             
                                 while(i!=length)
                {
                                        sum=sum*10;
                    i++;
                }
		cout<<sum<<"\n";
                while(N!=num)
                {
                                                temp_length=lengthint(N);

                        if(N%10==9 && temp_length <length && temp_length>1 && samedigit(N) && (reverse(N)-N)>0)
                                                {
                                                        N=reverse(N);
                        //                              cout<<N<<"\n";
                                                        count++;
                                                }
                                                else{

                        if(temp_length==length && N%10==f_d && samedigit(N) && (num-reverse(N)>=0) && (num-reverse(N))<sum)
                        {
                           //     cout<<"Inside Reverse call\n";
                                sum=N-reverse(N);
                                N=reverse(N);
                        //      cout<<N<<"\n";
                                count++;
                        }
                        else
                        {
                //              if(N>100000)
                //                      cout;

                                N++;
                                count++;
                        }
                                                }
                }
                cout<<"case #"<<iter+1<<":\t"<<count<<"\n";
        }
        return 0;

}

