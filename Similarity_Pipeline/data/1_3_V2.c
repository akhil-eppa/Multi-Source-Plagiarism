#include <stdio.h>
#include <stdlib.h>
long int max(long num , long a[]);
int main(void)
{
	long number;
	
	while(~scanf("%ld", &number)) // != EOF  or == 1
	{
	    long *arr = malloc((number+1) * sizeof(long));
	    printf("%ld\n", max(number, arr));
	}
	
	return 0;
}
long int max(long num , long a[])
{
    if(num==0||num==1)
    {
        a[num]=num;
        return a[num];
    }
   else if (a[num]!=0)
       return a[num];
       long int m = max(num/2,a)+max(num/3,a)+max(num/4,a);
       a[num] = num>m?num:m;
       return a[num];
}