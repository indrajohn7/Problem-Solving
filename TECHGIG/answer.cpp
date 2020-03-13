#include<bits/stdc++.h>

#define N 8

typedef struct{
	char type;
	char color;
	int x_pos;
	int y_pos;
}element;

typedef pair<char,char> pcc;

pcc mat[N][N];
element elem[N][N];

int main()
{
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			mat[i][j]=make_pair('0','0');
	}
	
	memset(mat[1],make_pair('P','W'),N);
	memset(mat[6],make_pair('P','B'),N);
	for(int i=0;i<N;i++){
		if(i==0 || i==7){
			for(int j=0;j<N;j++){
				if(j==0 || j==7){
					if(i==0)
						mat[i][j]=make_pair('E','W');
					else if(i==7)
						mat[i][j]=make_pair('E','B');
				}
				else if(j==1 || j==6){
					if(i==0)
						mat[i][j]=make_pair('B','W');
					else if(i==7)
						mat[i][j]=make_pair('B','B');
				}
				else if(j==2 || j==5){
					if(i==0)
						mat[i][j]=make_pair('H','W');
					else if(i==7)
						mat[i][j]=make_pair('H','B');
				}
				else if(j==3){
					if(i==0)
						mat[i][j]=make_pair('K','W');
					else if(i==7)
						mat[i][j]=make_pair('Q','B');
				}
				else if(j==4){
					if(i==0)
						mat[i][j]=make_pair('Q','W');
					else if(i==7)
						mat[i][j]=make_pair('K','B');
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			elem[i][j].color=mat[i][j].second();
			elem[i][j].x_pos=i;
			elem[i][j].y_pos=j;
			elem[i][j].type=mat[i][j].first();
		}
	}
	int flag=0,ch;
	while(1){
		element e;
		if(flag%2){
			e.color='w';	
		}else
			e.color='b';
		cout<<"1.Pawn move\n 2.Bishop move\n 3.King move\n 4.Queen move\n 5.Horse move\n 6.Elephant move\n"
		cout<<"Give input:";
		cin>>ch;
		int xf,yf,xt,yt;
		cout<<"Enter Coordinate from:";
		cin>>xf>>yf;
		cout<<"Enter Coordinate to:";
		cin>>xt>>yt;
		if(!(xf>=1 && xf<=8 && yf>=1 && yf<=8 && xt>=1 && xt<=8 && yt>=1 && yt<=8))
			continue;
		
		//Do is_king_check() every time after an operation : it will determine check condition and if true then only opponent king will turn 
		switch(ch){
			case 1: int ret=pawn_move(elem,e,xt,yt,xf,yf);
					if(ret==1){
						flag++;
						break;
					}else if(ret==2){
						return 0;
					}
					else{
						cout<<"Rechance of ssame player:\n";
						break;
					}
			
			case 2: int ret=bishop_move(elem,e,xt,yt,xf,yf);
					if(ret==1){
						flag++;
						break;
					}else if(ret==2){
						return 0;
					}	
					else{
						cout<<"Rechance of ssame player:\n";
						break;
					}
			case 3: int ret=king_move(elem,e,xt,yt,xf,yf);
					if(ret==1){
						flag++;
						break;
					}else if(ret==2){
						return 0;
					}	
					else{
						cout<<"Rechance of ssame player:\n";
						break;
					}
					
			case 4: int ret=queen_move(elem,e,xt,yt,xf,yf);
					if(ret==1){
						flag++;
						break;
					}else if(ret==2){
						return 0;
					}	
					else{
						cout<<"Rechance of ssame player:\n";
						break;
					}
					
			case 5: int ret=horse_move(elem,e,xt,yt,xf,yf);
					if(ret==1){
						flag++;
						break;
					}else if(ret==2){
						return 0;
					}
					else{
						cout<<"Rechance of ssame player:\n";
						break;
					}
					
			case 6: int ret=elephant_move(elem,e,xt,yt,xf,yf);
					if(ret==1){
						flag++;
						break;
					}else if(ret==2){
						return 0;
					}	
					else{
						cout<<"Rechance of ssame player:\n";
						break;
					}
						
		}
	}
	return 0;
}