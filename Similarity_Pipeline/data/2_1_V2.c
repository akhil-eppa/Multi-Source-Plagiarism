#include <stdio.h>
#include <stdlib.h>
long max(long first, long second);
long maxAmount(long n, long *arr);
int main(void) {
	// your code goes here
	long num;
	while(scanf("%ld", &num) != EOF){
	    long* arr=(long *)malloc(sizeof(long)*(num+1));
	    printf("%ld\n",maxAmount(num,arr));
	}
	return 0;
}
long max(long first, long second)
{
    if(second>first)
        return second;
        
    return first;
}
long maxAmount(long n, long *arr)
{
    if(arr[n])
        return arr[n];
        
    if(!n)
        return 0;
        
    return arr[n] = max(n, maxAmount(n/2, arr) + maxAmount(n/3, arr) + maxAmount(n/4, arr));
}