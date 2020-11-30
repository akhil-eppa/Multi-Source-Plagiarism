#include <stdio.h>
#include <stdlib.h>
long long int max(long long int first, long long int second);
long long int maxAmount(long long int n, long long int *arr);
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
long long int max(long long int first, long long int second)
{
    if(second > first)
        return second;
        
    return first;
}
long long int maxAmount(long long int n, long long int *arr)
{
        
    if(arr[n])
        return arr[n];
    if(!n)
        return 0;
        
    return arr[n] = max(n, maxAmount(n/2, arr) + maxAmount(n/3, arr) + maxAmount(n/4, arr));
}