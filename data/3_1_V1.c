#include <stdio.h>
#include <stdlib.h>
long long int max(long long int first, long long int second)
{
    if(first > second)
        return first;
        
    return second;
}
long long int maxAmount(long long int n, long long int *arr)
{
    if(!n)
        return 0;
        
    if(arr[n])
        return arr[n];
        
    return arr[n] = max(n, maxAmount(n/2, arr) + maxAmount(n/3, arr) + maxAmount(n/4, arr));
}

int main(void) {
	// your code goes here
	long long int num;
	long long int *a;
	while(scanf("%lld" ,&num)==1)
	{
	    a=(long long int*)calloc(num+1,sizeof(long long int));
	    printf("%lld\n",maxAmount(num,a));
	}
	
	return 0;
}
