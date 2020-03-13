#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;


#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

bool nick_caught(char** temp,int N,pii p,int dir)
{
	bool left,right,up,down;
	left=right=up=down=false;
	if(((p.first-1) >= 0 && temp[p.first-1][p.second]=='C') || p.first==0){
		up=true;
	}
	if(((p.first+1) < N  && temp[p.first+1][p.second]=='C') || p.first==N-1)
		down=true;
	if(((p.second-1) >= 0 && temp[p.first][p.second-1]=='C') || p.second==0)
		left=true;
	if(((p.second+1) < N && temp[p.first][p.second+1]=='C') || p.second==N-1)
		right=true;
	
	if(dir == UP && up)
		return true;
	else if(dir == DOWN && down)
		return true;
	else if(dir == LEFT && left)
		return true;
	else if(dir == RIGHT && right)
		return true;
	else
		return (up && down && left && right);
}


void move(char** temp,int N)
{
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(temp[i][j]== 'C' || temp[i][j]=='L'){
				if(i>0 && (temp[i-1][j]=='C' || temp[i-1][j]=='O'))
					temp[i-1][j]='C';
				if(j>0 && (temp[i][j-1]=='C' || temp[i][j-1]=='O'))
					temp[i][j-1]='C';
				if(i<N-1 && (temp[i+1][j]=='C' || temp[i+1][j]=='O'))
					temp[i+1][j]='C';
				if(j<N-1 && (temp[i][j+1]=='C' || temp[i][j+1]=='O'))
					temp[i][j+1]='C';
			}
			
		}
	}
}

void truck_move(char** temp,int N,pii p)
{
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if((i==p.first && j==p.second)){
				if(i>0 && (temp[i][j-1]=='C' || temp[i-1][j]=='O' ))
					temp[i-1][j]='C';
				if(j>0 && (temp[i][j-1]=='C' || temp[i][j-1]=='O'))
					temp[i][j-1]='C';
				if(i<N-1 && (temp[i+1][j]=='C' || temp[i+1][j]=='O'))
					temp[i+1][j]='C';
				if(j<N-1 && (temp[i][j+1]=='C' || temp[i][j+1]=='O'))
					temp[i][j+1]='C';
			}
			
		}
	}
}



int get_dir(char** temp,int N,pii source,pii dest)
{
	if(source.first == dest.first){
		if(dest.second > source.second)
			return 4;
		else
			return 3;
	}else{
		if(dest.first > source.first)
			return 2;
		else 
			return 1;
	}
}

int nick_move(char** temp,int N,int S,int* r,int* c,pii dest)
{
	
	temp[*r][*c]='O';
	if(*r == dest.first){
		if(*c > dest.second){
			for(int i=*c; i>=(*c-S);i--){
				if(i>=0 && temp[*r][i]=='C')
					return -1;
			}
			
			*c-=S;
			temp[*r][*c]='M';
			if(*c <= dest.second)
				return 0;
		}else{
			for(int i=*c; i<=(*c+S);i++){
				if(i<N && temp[*r][i]=='C')
					return -1;
			}
			*c+=S;
			temp[*r][*c]='M';
			if(*c >= dest.second)
				return 0;
		}
	}else{
		if(*r > dest.first){
			for(int i=*r; i>=(*r-S);i--){
				if(i>=0 && temp[i][*c]=='C')
					return -1;
			}
			*r-=S;
			temp[*r][*c]='M';
			if(*r <= dest.second)
				return 0;
		}else{
			for(int i=*r; i<=(*r+S);i++){
				if(i<N && temp[i][*c]=='C')
					return -1;
			}
			*r+=S;
			temp[*r][*c]='M';
			if(*r >= dest.first)
				return 0;
		}
	}
	
	return 1;
			
}

void cpy(char** dest,char** src, int N)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dest[i][j]=src[i][j];
}

int maxPossibleWait(int input1,int input2,int input3_size, char** input3)
{
        //Write code here
		
		int N,S;
		N=input1;
		S=input2;
		int res;
		//typedef pair<int,int> pii;
		typedef vector<pii> vpii;
		typedef map<char,vpii> vmap;
		vmap loc;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				vmap::iterator it=loc.begin();
				if((it=loc.find(input3[i][j])) != loc.end()){
					//loc[input3[i][j]].push_back(make_pair(i,j));
					it->second.push_back(make_pair(i,j));
				}else{
					loc[input3[i][j]].push_back(make_pair(i,j));
				}
			}
		}
		
		vmap::iterator it=loc.begin();
		pii source,dest;
		it=loc.find('M');
		source.first=it->second[0].first;
		source.second=it->second[0].second;
		
		it=loc.find('S');
		dest.first=it->second[0].first;
		dest.second=it->second[0].second;
		
		it=loc.find('L');
		int dis=2*N;
		
		pii truck;
		for(int i=0;i<it->second.size();i++){
			if(abs(source.first-it->second[i].first)+abs(source.second - it->second[i].second) < dis){
				dis=abs(source.first-it->second[i].first)+abs(source.second - it->second[i].second);
				truck.first=it->second[i].first;
				truck.second=it->second[i].second;
			}
		}
		
		int t1;
		float t2;
		
		char** stream;
		char** temp;
		stream=new char*[N];
		for(int i=0;i<N;i++)
			stream[i]=new char[N];
		
		temp=new char*[N];
		for(int i=0;i<N;i++)
			temp[i]=new char[N];
		
		memcpy(stream,input3,N*N);
		cpy(temp,input3,N);
		
		int started,time;
		started=time=0;
		it=loc.find('L');
		bool caught=true;
/*		
		while(caught){
			for(int i=0;i<it->second.size();i++){
				if(nick_caught(temp,N,source)){
					caught=false;
					break;
				}
				move(temp,N,it->second[i]);
				time++;
			}
		}
*/	
		int timer1;
		float timer2;
		int dist=abs(source.first-dest.first)+abs(source.second+dest.second);
		timer2=(float)((float)dist/(float)S);
		timer1=dist/S;
		
		if(timer2 > timer1)
			timer1+=1;
		
		caught=false;
		cpy(temp,input3,N);
		
		it=loc.find('L');
		/*for(int i=0;i<it->second.size();i++){
			truck_move(temp,N,it->second[i]);
		*/
		int reach,wait,iter;
		wait=iter=0;
	//	if(timer1 < time)
		//	return -1;
	//	else{
		
		pii dummy=source;
			while(!caught){
				int dir=get_dir(temp,N,source,dest);
				if(nick_caught(temp,N,source,dir))
					caught=true;
			//	for(int i=0;i<it->second.size();i++){
					move(temp,N);
			//	}
				
				if(nick_caught(temp,N,source,dir))
					return wait-1;
				if(iter>=wait){
					int t=nick_move(temp,N,S,&(source.first),&(source.second),dest);
					if( t == 0){
						wait++;
						iter=0;
						cpy(temp,input3,N);
						reach=1;
						source=dummy;
					}else if(t==-1)
						return wait-1;
				}
				if(reach == 0)
					iter++;
				else
					reach=0;
			}
	//	}
		
		if(wait==0)
			return -1;
		else
			return wait-1;
		
}




int main() {
	freopen("nick.in","r",stdin);
    int output;
    int ip1;
    cin >> ip1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip2;
    cin >> ip2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    int ip3_size = 0;
    cin >> ip3_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
  //  vector<string> ip3;
    char** ip3=new char*[ip3_size];
	for(int i=0;i<ip3_size;i++)
		ip3[i]=new char[ip3_size];
	string ip3_item;
    for(int ip3_i=0; ip3_i<ip3_size; ip3_i++) {
		for(int j=0;j<ip3_size;j++)
			cin>>ip3[ip3_i][j];
      //  getline(cin, ip3_item);
      //  ip3.push_back(ip3_item);
    }
    output = maxPossibleWait(ip1,ip2,ip3_size,ip3);
    cout << output << endl;
    return 0;
}
