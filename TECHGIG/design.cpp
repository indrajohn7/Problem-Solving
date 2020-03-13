int horse_move(element mat[][],element e,int x_pos,int y_pos,int x_f,int y_f)
{
	if(mat[x_f-1][y_f-1].type=='H'){
			if((abs(mat[x_f-1][y_f-1].x_pos-x_pos)==2 && abs(mat[x_f-1][y_f-1].x_pos-y_pos)==1) ||
					(abs(mat[x_f-1][y_f-1].x_pos-x_pos)==1 && abs(mat[x_f-1][y_f-1].x_pos-y_pos)==2)){
				if(mat[x_pos-1][y_pos-1].color!=mat[x_f-1][y_f-1].color){
					mat[x_pos-1][y_pos-1]=mat[x_f-1][y_f-1];
					memset(&mat[x_f-1][y_f-1],0,sizeof(element));
					if(mat[x_pos][y_pos].type=='K'){
						cout<<"Game returns with winner:"<<mat[x_f][y_f].color<<endl;
						return 2;
					}
				//	mat[e.x][e.y]='0';
					return true;
				}else{
					//take care to kill
					return false;
				}
			}
	}
	else{
		//print type error
		return false;
	}
}

int bishop_move(element mat[][],element e,int x_pos,int y_pos,int x_f,int y_f)
{
	if(mat[x_f-1][y_f-1].type=='B'){
		if(abs(x_f-x_pos)==abs(y_f-y_pos)){
			if(mat[x_pos-1][y_pos-1].color!=mat[x_f-1][y_f-1].color){
					mat[x_pos-1][y_pos-1]=mat[x_f-1][y_f-1];
					memset(&mat[x_f-1][y_f-1],0,sizeof(element));
					if(mat[x_pos-1][y_pos-1].type=='K'){
						cout<<"Game returns with winner:"<<mat[x_f-1][y_f-1].color<<endl;
						return 2;
					}
					return true;
					
				}else{
					//take care to kill depends on the color
					return false;
				}
			}
		}
	else{
		return false;
	}
}


int elephant_move(element mat[][],element e,int x_pos,int y_pos,int x_f,int y_f)
{
	if(mat[x_f-1][y_f-1].type=='E'){
		if((abs(x_f-x_pos)!=0 && abs(y_f-y_pos)==0) || (abs(x_f-x_pos)==0 && abs(y_f-y_pos)!=0)){
			if(mat[x_pos-1][y_pos-1].color!=mat[x_f-1][y_f-1].color){
					mat[x_pos-1][y_pos-1]=mat[x_f-1][y_f-1];
					memset(&mat[x_f-1][y_f-1],0,sizeof(element));
					if(mat[x_pos-1][y_pos-1].type=='K'){
						cout<<"Game returns with winner:"<<mat[x_f-1][y_f-1].color<<endl;
						return 2;
					}
					return true;
				}else{
					//take care to kill depends on the color
					return false;
				}
		}
	}else{
		return false;
	}
}


int queen_move(element mat[][],element e,int x_pos,int y_pos)
{
	if(mat[x_f-1][y_f-1].type=='Q'){
		if((abs(x_f-x_pos)!=0 && abs(y_f-y_pos)==0) || (abs(x_f-x_pos)==0 && abs(y_f-y_pos)!=0) ||
			abs(x_f-x_pos)==abs(y_f-y_pos)){
			if(mat[x_pos-1][y_pos-1].color!=mat[x_f-1][y_f-1].color){
					mat[x_pos-1][y_pos-1]=mat[x_f-1][y_f-1];
					memset(&mat[x_f-1][y_f-1],0,sizeof(element));
					if(mat[x_pos-1][y_pos-1].type=='K'){
						cout<<"Game returns with winner:"<<mat[x_f-1][y_f-1].color<<endl;
						return 2;
					}
					return true;
				}else{
					//take care to kill depends on the color
					return false;
				}
		}
	}else{
		return false;
	}
}

int king_move(element mat[][],element e,int x_pos,int y_pos,int x_f,int y_f)
{
	if(mat[x_f-1][y_f-1].type=='K'){
		if((abs(x_f-x_pos)==1 && abs(y_f-y_pos)==0) || (abs(x_f-x_pos)==0 && abs(y_f-y_pos)==1) ||
				(abs(x_f-x_pos)==1 && abs(y_f-y_pos)==1)){
			if(mat[x_pos-1][y_pos-1].color!=mat[x_f-1][y_f-1].color){
					mat[x_pos-1][y_pos-1]=mat[x_f-1][y_f-1];
					memset(&mat[x_f-1][y_f-1],0,sizeof(element));
					if(mat[x_pos-1][y_pos-1].type=='K'){
						cout<<"Game returns with winner:"<<mat[x_f-1][y_f-1].color<<endl;
						return 2;
					}
					return true;
				}else{
					//take care to kill depends on the color
				}
		}
	}else{
		return false;
	}
}


int pawn_move(element mat[][],element e,int x_pos,int y_pos,int x_f,int y_f)
{
	if(mat[x_f-1][y_f-1].type=='P'){
		if((((y_f-y_pos)==1) && x_f==x_pos && mat[x_f-1][y_f-1].color=='b') ||
			(((y_pos-y_f)==1) && x_f==x_pos && mat[x_f-1][y_f-1].color=='w')){
			if(mat[x_pos-1][y_pos-1].color=='0'){
					mat[x_pos-1][y_pos-1]=mat[x_f-1][y_f-1];
					memset(&mat[x_f-1][y_f-1],0,sizeof(element));
					return true;
				}else {
					//take care to kill depends on the color
					return false;
				}
		}else if(abs(y_f-y_pos)==1) && abs(x_f-x_pos)==1){
			if(mat[x_pos-1][y_pos-1].color!='0' && mat[x_pos-1][y_pos-1].color!=mat[x_f-1][y_f-1].color){
					mat[x_pos-1][y_pos-1]=mat[x_f-1][y_f-1];
					memset(&mat[x_f-1][y_f-1],0,sizeof(element));
					if(mat[x_pos-1][y_pos-1].type=='K'){
						cout<<"Game returns with winner:"<<mat[x_f-1][y_f-1].color<<endl;
						return 2;
					}
					return true;
				}else {
					//take care to kill depends on the color
					return false;
				}
		}
	}
	else{
		return false;
	}
}

