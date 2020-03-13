#include<bits/stdc++.h>

#define PI 3.14159265
#define SIN(X) sin(X*PI/180)
#define COS(X) cos(X*PI/180)

using namespace std;

float calc_cir(int x,int up)
{
	float res;
	if(up)
		res=(float)50+(float)sqrt(pow(50,2)-pow((x-50),2));
	else
		res=(float)50-(float)sqrt(pow(50,2)-pow((x-50),2));
	
	return res;
}

float calc_line(int x,int deg_f)
{
	float slope=(float)(SIN(deg_f)/COS(deg_f));
	float res;
	res=50+(x-50)*slope;
	return res;
}

int main()
{
	ifstream fin;
	ofstream fout;
	fout.open("pie.txt");
	fin.open("progress_pie.txt");
	int Num_Test,iter;
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int p,x,y;
		fin>>p>>x>>y;
		int deg_f,deg=p*360/100;
		if(deg<=90)
			deg_f=90-deg;
		else
			deg_f=360-(deg-90);
		int co_or_per,co_or_deg;
		co_or_deg=(deg/90)+1;
		co_or_per=(p/25)+1;
		bool white,black;
		white=black=false;
		switch(co_or_per){
			
			case 1:
					if(deg == 0){
						white=true;
						break;
					}else{
						if(x>=50 && x<=(50+(50*COS(deg_f)))){
							if(x==50+(50*COS(deg_f))){
								if(y==50*SIN(deg_f)){
									black=true;
									break;
								}
								else{
									white=true;
									break;
								}
							}else{
								if(y>=calc_line(x,deg_f) && y<=calc_cir(x,1)){
									black=true;
									break;
								}
								else{
									white=true;
									break;
								}
							}
								
						}
						else{
							white=true;
							break;
						}
					}
					break;
			case 2:
						if(x>=50 && x<=50+(50*COS(deg_f))){							
								if(y>=calc_line(x,deg_f) && y<=calc_cir(x,1)){
									black=true;
									break;
								}
								else{
									white=true;
									break;
								}
						}else if(x>=50+(50*COS(deg_f))){
							if(y>=calc_cir(x,0) && y<=calc_cir(x,1)){
									black=true;
									break;
								}
								else{
									white=true;
									break;
								}						
						}else{
							white=true;
							break;
						}
						break;
			case 3:
						
						if(x>=50){
							if(y>=calc_cir(x,0) && y<=calc_cir(x,1)){
								black=true;
								break;
							}else{
								white=true;
								break;
							}
						}else if(x>=50+(50*COS(deg_f))){
							if(y<=calc_line(x,deg_f) && y>=calc_cir(x,0)){
								black=true;
								break;
							}
						}
						break;
					
			case 4:
					/*	if(deg==270){
							if(x<50 && y>50){
								white=true;
								break;
							}else{
								black=true;
								break;
							}		
						}*/
						 if(x>=50){
							if(y>=calc_cir(x,0) && y<=calc_cir(x,1)){
								black=true;
								break;
							}else{
								white=true;
								break;
							}
						}else if(x<=50+(50*COS(deg_f))){
							if(y>=calc_cir(x,0) && y<=calc_cir(x,1)){
								black=true;
								break;
							}
						}else{
							if(y<=calc_line(x,deg_f) && y>=calc_cir(x,0)){
								black=true;
								break;
							}
						}
						break;
			case 5:
					if(deg==360){
						if(y>=calc_cir(x,0) && y<=calc_cir(x,1)){
							black=true;
							break;
						}		
					}
					break;
			default:
				break;
		}
		fout<<"Case #"<<iter+1<<": ";
		if(black)
			fout<<"black"<<endl;
		else
			fout<<"white"<<endl;
	}
	return 0;
}
