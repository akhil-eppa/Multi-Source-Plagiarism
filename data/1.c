#include <stdio.h>
#include <stdlib.h>
long maxAmount(long, long *);
long max(long, long);

int main(void)
{
	long num;
	
	while(~scanf("%ld", &num)) // != EOF  or == 1
	{
	    long *arr = malloc((num+1) * sizeof(long));
	    printf("%ld\n", maxAmount(num, arr));
	}
	
	return 0;
}

//Function for calculating the maximum amount after exchange
long maxAmount(long n, long *arr)
{
    if(!n)
        return 0;
        
    if(arr[n])
        return arr[n];
        
    return arr[n] = max(n, maxAmount(n/2, arr) + maxAmount(n/3, arr) + maxAmount(n/4, arr));
}

//Maximum Function
long max(long first, long second)
{
    if(first > second)
        return first;
        
    return second;
}

