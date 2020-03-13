#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<ctype.h>
#include<stdio.h>

#define N 3
using namespace std;

int main()
{
  ifstream fin;
  fin.clear();
  fin.open("MAP.in");
  int Test,iter;
  fin>>Test;
  for(iter=0;iter<Test;iter++)
  {
    int Prod_num,Expo_num,i,j,k,count=0;
    fin>>Prod_num;
    fin>>Expo_num;
    int Production[Prod_num],Export[Expo_num],Route[100][3]={0};
    for(i=0;i<Prod_num;i++)
      fin>>Production[i];
    for(i=0;i<Expo_num;i++)
      fin>>Export[i];
      int t;
    for(i=0;i<100;i++)
    {
      for(j=0;j<N;j++)
        fin>>Route[i][j];
    }
    for(i=0;i<100;i++)
    {
      if(Route[i][0]==0)
        break;
      count++;
    }
    int Final[count][N];
    k=0;
    for(i=0;i<(Prod_num*Expo_num);i++)
    {
      for(j=0;j<N;j++)
      {
        if(j==0)
          Final[i][j]=Production[i/Expo_num];
        else if(j==1)
        {
          Final[i][j]=Export[k];
          k++;
          if(k>=Expo_num)
            k=0;
        }
        else
          Final[i][j]=0;
      }
    }
    for(i=0;i<Prod_num*Expo_num;i++)
    {
      for(j=0;j<N;j++)
        cout<<Final[i][j]<<"\t";
      cout<<"\n";
    }

    // Solve the logic
    int min,temp;
    cout<<count<<"\n";
    for(i=0;i<Prod_num*Expo_num;i++)
    {
      int P=Final[i][0];
      int E=Final[i][1];
      for(j=0;j<count;j++)
      {
        if(Route[j][0]==E)
        {
          if(Route[j][1]==P)
          {
            Final[i][2]=Route[j][2];
            Route[j][2]=0;
            break;
          }
          else
          {
          //  prev=j;
            temp=Route[j][1];
           // k=0;
            int up[20][2],l=0,m=0;
            min=Route[j][2];
            up[m][0]=j;
            up[m++][1]=min;
            int flag=0,k=0;
            while(temp!=P && k<count)
            {
               // k=0;
                while(!(Route[k][0]==temp) && !(Route[k][1]==temp) && k < count)
                  k++;
                (Route[k][0]==temp) ? temp=Route[k][1] : temp=Route[k][0];
                for(l=0;l<Prod_num;l++)
                {
                  if(Production[l]==temp)
                  {
                    flag=1;
                    break;
                  }
                }
                for(l=0;l<Expo_num;l++)
                {
                  if(Production[l]==temp)
                  {
                    flag=1;
                    break;
                  }
                }
                if(flag==1)
                {
		  if(temp!=P)
		  	k++;
		  else
		  {
                  up[m][0]=k;
                  up[m++][1]=Route[k][2];
		  break;
		  }
                }
                else
                {
                  up[m][0]=k;
                  up[m++][1]=Route[k][2];
		  k++;
                }
            }
            if(temp==P)
            {
              min=up[0][1];
              for(l=0;l<m;l++)
              {
                if(up[l][1]<min)
                {
                  min=up[l][1];
                }
              }
              for(l=m-1;l>0;l--)
              {
                if(up[l][1]<up[l-1][1] && up[l][1]>0 && up[l-1][1]>0)
                  Route[up[l-1][0]][2]-=Route[up[l][0]][2];
              }
              Final[i][2]=min;
	      break;
            }
            else
	    {
	     cout<<"Inside unexpected else:"<<i<<": :"<<j<<"\n";
	      Final[i][2]=0;
	     // temp=
	    //  j=k;
	    }


          }
          }
        
        else if(Route[j][1]==E)
        {
          if(Route[j][0]==P)
          {
            Final[i][2]=Route[j][2];
            Route[j][2]=0;
            break;
          }
          else
          {
          //  prev=j;
            temp=Route[j][0];
           // k=0;
            int up[20][2],l=0,m=0;
            min=Route[j][2];
            up[m][0]=j;
            up[m++][1]=min;
            int flag=0,k=0;
            while(temp!=P && k<count)
            {
              //  k=0;
                while(!(Route[k][0]==temp) && !(Route[k][1]==temp) && k < count && temp!=E)
                  k++;
                (Route[k][0]==temp) ? temp=Route[k][1] : temp=Route[k][0];
                for(l=0;l<Prod_num;l++)
                {
                  if(Production[l]==temp)
                  {
                    flag=1;
                    break;
                  }
                }
                for(l=0;l<Expo_num;l++)
                {
                  if(Export[l]==temp)
                  {
                    flag=1;
                    break;
                  }
                }
                if(flag==1)
                {
                  if(temp!=P)
		  {
		  //	temp=
			k++;
		  }
		  else
		  {
		  	up[m][0]=k;
                 	 up[m++][1]=Route[k][2];
		 	 break;
		  }
                }
                else
                {
                  up[m][0]=k;
                  up[m++][1]=Route[k][2];
                }
            }
            if(temp==P)
            {
              min=up[0][1];
              for(l=0;l<m;l++)
              {
                if(up[l][1]<min)
                {
                  min=up[l][1];
                }
              }
              for(l=m-1;l>0;l--)
              {
                if(up[l][1]<up[l-1][1] && up[l][1]>0 && up[l-1][1]>0)
                  Route[up[l-1][0]][2]-=Route[up[l][0]][2];
              }
              Final[i][2]=min;
	      break;
            }
            else
            {
	     cout<<"Inside unexpected else:"<<i<<": :"<<j<<"\n";
             Final[i][2]=0;
	    }
          }
          }
        }
      
      }
      for(i=0;i<Prod_num*Expo_num;i++)
      {
      	for(j=0;j<N;j++)
		cout<<Final[i][j]<<"\t";
	cout<<"\n";
      }
    }

  
  return 0;
}

