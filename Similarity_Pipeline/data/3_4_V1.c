#include <stdio.h>
#include <stdlib.h>
void max(long long int x,long long int* arr)
{
    if(arr[x/2]==-1)
        max(x/2,arr);
    if(arr[x/4]==-1)
        max(x/4,arr);
    if(arr[x/3]==-1)
        max(x/3,arr);
    arr[x]=x>arr[x/2]+arr[x/3]+arr[x/4]?x:arr[x/2]+arr[x/3]+arr[x/4];
}
int main(void) {
	// your code goes here
	long long int num;
	long long int *a;
	while(scanf("%lld" ,&num)==1)
	{
	    a=(long long int*)calloc(num+1,sizeof(long long int));
        max(num,a);
	    printf("%lld\n",a[num]);
	}
	
	return 0;
}