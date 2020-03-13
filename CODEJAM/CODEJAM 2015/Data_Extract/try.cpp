#include<bits/stdc++.h>
    
    using namespace std;

    const int ANS = 210;
    const int N = 1000010;

    int f[ANS][N];
    int a[N];
    int last[13];
    int pr[N][13];
    char foo[N];
    char buf[N];


int main(int argc, char* argv[]) {
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  int Sm;
/*  if (argc == 3) {
    sscanf(argv[1], "%d", &TEST_FROM);
    sscanf(argv[2], "%d", &TEST_TO);
  }*/
  freopen("in1", "r", stdin);
//  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    // input data starts
    scanf("%d %s",&Sm,foo);
    //printf("%s\n",foo);
   // sscanf(buf,"%d %s",&Sm,foo);
    int n = strlen(foo);
    printf("%s\n",foo);
    for (int i = 0; i < n; i++) {
      a[i] = foo[i] - '0';
    }
    
    // input data ends
  /*  if (qq < TEST_FROM || qq > TEST_TO) {
      continue;
    }*/
    printf("Case #%d: ", qq);
    fflush(stdout);
    for (int i = 0; i < n; i++) 
    	printf("%d",a[i]);
    fflush(stdout);
    fprintf(stderr, "test %d solved\n", qq);
    }
    return 0;
   }


