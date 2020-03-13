#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>

using namespace std;



class Node{
  public:
    char Stream_in[500]; 
    int percent;
    int st_key;
    int end_key;
 // public:
    Node(char Strm[500],int s_key,int e_key,int Percnt)
    {
      memset(Stream_in,0,strlen(Strm));
      memcpy(Stream_in,Strm,strlen(Strm));
      st_key=s_key;
      end_key=e_key;
      percent=Percnt;
    }
};

vector<Node> node;

class Input
{
  private:
    int percent_in;
    char *Stream;

  public:
    Input(char stream[500],int percentage)
    {
      Stream=new char[strlen(stream)];
      memset(Stream,0,strlen(stream));
      memcpy(Stream,stream,strlen(stream));
      cout<<Stream<<"\n";
      percent_in=percentage;  
    }
    friend class Node;
   /* 
    Input(void)
    {
      head=NULL;
    }
    */
    void initialise(char* streamin);
    void insertion_vector(char* SubStream,int startkey_ptr,int endkey_ptr,int prcnt);
    void min_calc(vector<Node> node_l,int i);
};


void Input::initialise(char Stream[500])
{
  int dummy_start,percent,length,start_key,end_key,flag;
  start_key=0;
  end_key=1;
  flag=0;
  while(start_key!=(strlen(Stream)-1) && end_key!=(strlen(Stream)))
  {
    int dummy_end=end_key;
    while(dummy_end!=strlen(Stream))
    {
      flag=0;
      dummy_start=start_key;
      while(dummy_start<=dummy_end)
      {
        if(Stream[dummy_start]=='1')
          flag++;
        dummy_start++;
      }
    //  if(Stream[end_key]==1)
      //  flag++
      length=dummy_end-start_key+1;
      percent=(flag*100)/length;
      insertion_vector(Stream,start_key,dummy_end,percent);
      dummy_end++;
    }
    start_key++;
    end_key++;
  
  }
}


void Input::insertion_vector(char SubStream[500],int start_key,int endl_key,int percentage)
{
  Node  l_node(SubStream,start_key,endl_key,percentage);
  node.push_back(l_node);

  /*
  memset(node.Stream_in,0,strlen(SubStream));
  memcpy(node.Stream_in,SubStream,strlen(SubStream));
  node.percent=percentage;
  node.st_key=start_key;
  node.end_key=endl_key;
  */
}

void Input::min_calc(vector<Node> l_node,int g_percent)
{
  int min=100;
  int flag=0;
  for(int i=0;i<l_node.size();i++)
  {
    cout<<l_node[i].percent<<"\n";
    if(abs(l_node[i].percent-g_percent)<=abs(min-g_percent))
    {
      min=l_node[i].percent;
      flag=i;
    }
  }
  cout<<"The following substring with respected 1 % is:"<<"\n";
  cout<<"SUBSTRING:";
  for(int j=l_node[flag].st_key;j<=l_node[flag].end_key;j++)
  	cout<<l_node[flag].Stream_in[j];
  cout<<"\n";
  cout<<"Start_Key:"<<l_node[flag].st_key<<"\n";
  cout<<"End_Key:"<<l_node[flag].end_key<<"\n";
  cout<<"Percentage:"<<l_node[flag].percent<<"\n";
}

int main()
{
  int Percent;
  char Stream[500];
  cout<<"Enter your Binary Stream:"<<"\n";
  cin.getline(Stream,sizeof(Stream));
  cout<<"Enter the Percentage:"<<"\n";
  cin>>Percent;
  Input *assign=new Input(Stream,Percent);
 // Input *newptr=new Input();
  assign->initialise(Stream);
  assign->min_calc(node,Percent);
  return 0;
}

