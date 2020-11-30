#include <stdio.h>
#include <stdlib.h>
void max(long x,long* arr)
{
    if(arr[x/2]==-1)
        max(x/2,arr);
    if(arr[x/4]==-1)
        max(x/4,arr);
    if(arr[x/3]==-1)
        max(x/3,arr);
    arr[x]=x>arr[x/2]+arr[x/3]+arr[x/4]?x:arr[x/2]+arr[x/3]+arr[x/4];
}
int main(void)
{
	long num;
	
	while(~scanf("%ld", &num)) // != EOF  or == 1
	{
	    long *arr = malloc((num+1) * sizeof(long));
        max(num,arr);
	    printf("%ld\n", (arr[num]));
	}
	
	return 0;
}