#include <stdio.h>
#include <stdlib.h>

long long max(long long int n , long long int a[])
{
    if(n==0||n==1)
    {
        a[n]=n;
        return a[n];
    }
   else if (a[n]!=0)
       return a[n];
       long long int m = max(n/2,a)+max(n/3,a)+max(n/4,a);
       a[n] = n>m?n:m;
       return a[n];
}


int main(void) {
	// your code goes here
	long long int n;
	long long int *a;
	while(scanf("%lld" ,&n)==1)
	{
	    a=(long long int*)calloc(n+1,sizeof(long long int));
	    printf("%lld\n",max(n,a));
	}
	
	return 0;
}

