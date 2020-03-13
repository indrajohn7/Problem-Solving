#include<bits/stdc++.h>

    using namespace std;

    const int N = 1000010;

    int a[N];
    char foo[N];


int main(int argc, char* argv[]) {
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  int Sm;
  freopen("A-large.in", "r", stdin);
  freopen("out", "w", stdout);
  int tt,i;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    // input data starts
    scanf("%d %s",&Sm,foo);
    int n = strlen(foo);
    //printf("%s\n",foo);
    for (i = 0; i < n; i++) {
      a[i] = foo[i] - '0';
    }
    printf("Case #%d: ", qq);
    fflush(stdout);
    //solution starts
    int sum=0;
        for(i=0;i<n;i++)
                sum=sum+a[i];
    if(a[n-1]>0)
    {

        int flag=0,diff,j;

        for(i=0;i<n;i++)
        {
                int stand_ov=0;
                if(i>0)
                {
                        for(j=0;j<i;j++)
                        {
                                stand_ov=stand_ov+a[j];
                        }
                        if(stand_ov<i)
                        {
                                //flag=flag+(i-stand_ov);
                                diff=i-stand_ov;
                                int it=0;
                                while(diff!=0)
                                {
                                        for(j=0;j<i;j++)
                                        {
                                                if(it==0)
                                                {
                                                        if(a[j]==0)
                                                        {
                                                                if(diff>0)
                                                                {
                                                                        a[j]++;
                                                                        diff--;
                                                                }
                                                        }
                                                }
                                                else
                                                {
                                                        if(diff>0)
                                                        {
                                                                a[j]++;
                                                                diff--;
                                                        }
                                                }
                                        }
                                        it++;
                                }

                        }
                }

        }
        for(i=0;i<n;i++)
	{
                flag=flag+a[i];
//		printf("%d",a[i]);
	}
		 printf("\t%d\n",flag-sum);
        }
    else
        printf("Invalid case:Max Shyness can't be 0 \n");
    fflush(stdout);
    fprintf(stderr, "test %d solved\n", qq);
    }
    return 0;
   }

