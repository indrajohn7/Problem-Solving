//send the API with the color turn and will return if is_check --> TRUE;
bool is_king_check(element mat[][],int N,char c,int x,int y,chat t)
{
	int i,j;
	if(t=='B'){
		i=x;
		j=y;
		while(i<=N && j<=N){
			if(mat[i][j].type=='K' && mat[i][j].color!=mat[x][y].color)
				return true;
			i++;
			j++;
		}
		while(i<=N && j>=0){
			if(mat[i][j].type=='K' && mat[i][j].color!=mat[x][y].color)
				return true;
			i++;
			j--;
		}
		while(i>=0 && j<=N){
			if(mat[i][j].type=='K' && mat[i][j].color!=mat[x][y].color)
				return true;
			i--;
			j++;
		}
		while(i>=0 && j>=0){
			if(mat[i][j].type=='K' && mat[i][j].color!=mat[x][y].color)
				return true;
			i--;
			j--;
		}
	}else if(t=='H'){
		i=x;
		j=y;
	//	while(i<=N && j<=N){ //check for NULL pointer termination
			if(mat[i+2][j+1].type=='K' && mat[i+2][j+1].color!=mat[x][y].color)
				return true;
		//	i++;
		//	j++;
	//	}
	//	while(i<=N && j>=0){
			if(mat[i-2][j+1].type=='K' && mat[i-2][j+1].color!=mat[x][y].color)
				return true;
			i++;
			j--;
	//	}
	//	while(i>=0 && j<=N){
			if(mat[i+1][j+2].type=='K' && mat[i+1][j+2].color!=mat[x][y].color)
				return true;
	//		i--;
	//		j++;
	//	}
	//	while(i>=0 && j>=0){
			if(mat[i-1][j-2].type=='K' && mat[i-1][j-2].color!=mat[x][y].color)
				return true;
	//		i--;
	//		j--;
	//	}	
	}else if(t=='K'){
				
	}else if(t=='Q'){
				
	}else if(t=='E'){
				
	}else if(t=='P'){
				
	}
	return false;
}