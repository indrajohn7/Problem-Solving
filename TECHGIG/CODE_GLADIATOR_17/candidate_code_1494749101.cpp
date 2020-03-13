
#include<bits/stdc++.h>
typedef pair<int,int> pii;

bool left_up(pii p)
{
    if(p.first-2 >=1 && p.second+1<=8)
        return true;
    return false;
}


bool left_down(pii p)
{
    if(p.first-2 >=1 && p.second-1>=1)
        return true;
    return false;
}


bool right_up(pii p)
{
    if(p.first+2 <=8 && p.second+1<=8)
        return true;
    return false;
}


bool right_down(pii p)
{
    if(p.first+2 <=8 && p.second-1>=1)
        return true;
    return false;
}


bool up_left(pii p)
{
    if(p.first-1 >=1 && p.second+2<=8)
        return true;
    return false;
}


bool up_right(pii p)
{
    if(p.first+1 <=8 && p.second+2<=8)
        return true;
    return false;
}


bool down_left(pii p)
{
    if(p.first-1 >=1 && p.second-2>=1)
        return true;
    return false;
}


bool down_right(pii p)
{
    if(p.first+1 <=8 && p.second-2>=1)
        return true;
    return false;
}

int getStepCount(int input1,int input2,int input3,int input4)
{
	//Write code here
	vector<pii> old;
	vector<pii> curr;
	int move=0;
	old.push_back(make_pair(input1,input2));
	while(true){
	    for(int i=0;i<old.size();i++){
	        
	        if(old[i].first==input3 && old[i].second==input4)
	            return move;
	        if(left_up(old[i])) 
	            curr.push_back(make_pair((old[i].first-2),(old[i].second+1)));
	        if(left_down(old[i])) 
	            curr.push_back(make_pair((old[i].first-2),(old[i].second-1)));
	        if(right_up(old[i])) 
	            curr.push_back(make_pair((old[i].first+2),(old[i].second+1)));
	        if(right_down(old[i])) 
	            curr.push_back(make_pair((old[i].first+2),(old[i].second-1)));
	        if(up_left(old[i])) 
	            curr.push_back(make_pair((old[i].first-1),(old[i].second+2)));
	        if(up_right(old[i])) 
	            curr.push_back(make_pair((old[i].first+1),(old[i].second+2)));
	        if(down_left(old[i])) 
	            curr.push_back(make_pair((old[i].first-1),(old[i].second-2)));
	        if(down_right(old[i])) 
	            curr.push_back(make_pair((old[i].first+1),(old[i].second-2)));
	       
	    }
	    
	    old=curr;
	    curr.clear();
	    move++;
	}
	
	return move;
	
}