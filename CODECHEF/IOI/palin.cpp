#include<bits/stdc++.h>

using namespace std;

//typedef vector<int> vin;
//typedef pair<int,vector<int>> pini;
typedef pair<int,int> pii;
vector<pii> vpii;


bool IS_Palindrome(int arr[],int first,int last)
{
	int val=((last-first)%2==0)?(last-first)/2:(last+1-first)/2;
	int match=0;
	while(first<last){
		if(arr[first++]==arr[last--])
			match++;
		else
			break;
	}
	if(val!=0 && match==val)
		return true;
	else
		return false;
}


int main()
{
	freopen("palin.in","r",stdin);
	int N,res=0,first=0,last;
	bool is_palin=false;
	cin>>N;
	last=N-1;
	int* arr=new int[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	typedef map<int, vector<int> > vmap;
	vmap work;
	for(int i=0;i<N;i++){
		vmap::iterator it=work.begin();
		it=work.find(arr[i]);
		if(it==work.end()){
			vector<int> vi;
			vi.push_back(i);
			work[arr[i]]=vi;
		}
		else{
			it->second.push_back(i);
		}
	}
	//GET PALINDROMES
	
	for(vmap::iterator it=work.begin();it!=work.end();it++){
		if(it->second.size()>1){
			int match=0,first=0,last=0;
			bool is_palin=false;
			for(int i=0;i<it->second.size()-1;i++){
				first=it->second[i];match=0;
				for(int j=it->second.size()-1;j>i;j--){
					last=it->second[j];is_palin=false;
					if(IS_Palindrome(arr,first,last)){
						pair<int,int> p=make_pair(first,last);
						vpii.push_back(p);
						is_palin=true;
						break;
					}
				}
				if(is_palin)
					break;
			}			
		}
	}
	
	
	//SORT the pairs
	
	for(int i=0;i<vpii.size();i++){
		for(int j=0;j<vpii.size()-1;j++){
			if(abs(vpii[j].first-vpii[j].second) > abs(vpii[j+1].first-vpii[j+1].second))
				swap(vpii[j],vpii[j+1]);
		}
	}
	
	int count=0,length=0;
	vector<pii> vp;
	vp.push_back(vpii[vpii.size()-1]);
	first=vpii[vpii.size()-1].first;
	last=vpii[vpii.size()-1].second;
	for(int i=vpii.size()-1;i>=0;i--){    //check here
		bool select=false;
		for(int j=0;j<vp.size();j++){
			if(!(vpii[i].first > vp[j].second || vpii[i].second < vp[j].first)){
				select=false;
				break;
			}
			else
				select=true;
		}
		if(select==true){
			vp.push_back(make_pair(vpii[i].first,vpii[i].second));
			//count++;
			//length+=abs(vpii[i].first-vpii[i].second)+1;
		}
	}
	for(int i=0;i<vp.size();i++){
		length+=abs(vp[i].first-vp[i].second)+1;
	}
	count=N-length+vp.size();
	cout<<count;
	return 0;
}