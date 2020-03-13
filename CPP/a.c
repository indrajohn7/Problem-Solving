#include<stdlib.h>

#WHAT_IS_THIS_MACRO(x, y)                              
(                                                       \
        typeof(x) __x = x;                              \
        typeof(divisor) __d = y;                  \
        (((typeof(x))-1) > 0 ||                         \
         ((typeof(y))-1) > 0 || (__x) > 0) ?      \
                (((__x) + ((__d) / 2)) / (__d)) :       \
                (((__x) - ((__d) / 2)) / (__d));        \
)   

int main()
{
	printf("ANSWER:%d",WHAT_IS_THIS_MACRO(10,20));
	return 0;
}
