
#include<bits/stdc++.h>
//#include"header.h"
using namespace std;


typedef struct start_pt
{
        int x_c;
        int y_c;
        int e;
}Point;

/*
int DIRECTION(Point P1,Point P2,Point P3)
{
	return((P3.x_c-P1.x_c)(P2.y_c-P1.y_c)-(P2.x_c-P1.x_c)(P3.y_c-P1.y_c));
	//return (P3-P1)*(P2-P1) vector product returns
}


*/
int min(int a , int b)
{
	if(a<b)
			return a;
	else 
		return b;
}

int max(int a, int b)
{
	if(a>b)
			return a;
	else return b;
}

bool ON_SEGMENT(Point P1,Point P2,Point P3)
{
	if(min(P1.x_c,P2.x_c)<=P3.x_c && max(P1.x_c,P2.x_c)>=P3.x_c && min(P1.y_c,P2.y_c)<=P3.y_c && max(P1.y_c,P2.y_c)>=P3.y_c)
		return true;
	else 
		false;
}




int main()
{
        ifstream fin;
        fin.open("infile.in");
        int NUM_TEST,iter;
        fin>>NUM_TEST;
        for(iter=0;iter<NUM_TEST;iter++)
        {
                Point Seg[10];
                int Num_Seg,i;
                fin>>Num_Seg;
                for(int i=0;i<Num_Seg;i+=2)
                {
                        fin>>Seg[i].x_c;
                        fin>>Seg[i].y_c;
                        Seg[i].e=0;
                        fin>>Seg[i+1].x_c;
                        fin>>Seg[i+1].y_c;
                        Seg[i].e=1;
                }
                int d1,d2,d3,d4;
                i=0;
	//			return((Seg[3].x_c-Seg[0].x_c)(Seg[1].y_c-Seg[0].y_c)-(Seg[1].x_c-Seg[0].x_c)(Seg[3].y_c-Seg[0].y_c));
                d1=(Seg[0].x_c-Seg[2].x_c)*(Seg[3].y_c-Seg[2].y_c)-(Seg[3].x_c-Seg[2].x_c)*(Seg[0].y_c-Seg[2].y_c);
                d2=(Seg[1].x_c-Seg[2].x_c)*(Seg[3].y_c-Seg[2].y_c)-(Seg[3].x_c-Seg[2].x_c)*(Seg[1].y_c-Seg[2].y_c);
                d3=(Seg[2].x_c-Seg[0].x_c)*(Seg[1].y_c-Seg[0].y_c)-(Seg[1].x_c-Seg[0].x_c)*(Seg[2].y_c-Seg[0].y_c);
                d4=(Seg[3].x_c-Seg[0].x_c)*(Seg[1].y_c-Seg[0].y_c)-(Seg[1].x_c-Seg[0].x_c)*(Seg[3].y_c-Seg[0].y_c);
                if(((d1>0 && d2<0)||(d1<0 && d2>0))&&((d3>0 && d4<0)||(d3<0 && d4>0)))
                        cout<<"cut\n";
                else if(d1==0 && ON_SEGMENT(Seg[2],Seg[3],Seg[0]))
                        cout<<"cut\n";
                else if(d2==0 && ON_SEGMENT(Seg[2],Seg[3],Seg[1]))
                        cout<<"cut\n";
                else if(d3==0 && ON_SEGMENT(Seg[0],Seg[1],Seg[2]))
                        cout<<"cut\n";
                else if(d4==0 && ON_SEGMENT(Seg[0],Seg[1],Seg[3]))
                        cout<<"cut\n";
                else
                        cout<<"NOT CUT\n";


        }
        return 0;
}
