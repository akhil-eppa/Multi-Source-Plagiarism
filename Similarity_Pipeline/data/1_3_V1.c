#include <stdio.h>
#include <stdlib.h>
long int max(long n , long a[])
{
    if(n==0||n==1)
    {
        a[n]=n;
        return a[n];
    }
   else if (a[n]!=0)
       return a[n];
       long int m = max(n/2,a)+max(n/3,a)+max(n/4,a);
       a[n] = n>m?n:m;
       return a[n];
}
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