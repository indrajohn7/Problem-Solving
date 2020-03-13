#include <stdio.h>
#define MAX_SIZE 1024
main ()
{
  FILE *fp, *gp;
  char buf[MAX_SIZE];
  int i, total = 0;
  if ((fp = fopen("data1.txt", "r") ) == NULL)
    printf("Error in data1.txt file \n");
  else if ((gp=fopen("data2.txt", "w")) == NULL)
    printf("Error in data2.txt file \n");
  else
   {
    while(i=fread(buf, 1, MAX_SIZE, fp))
    {
     fwrite(buf, 1, MAX_SIZE, gp);
     total +=i;
    }
    printf("Total is %d\n", total);
  }
  fclose(fp);
  fclose(gp);
}
