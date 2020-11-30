#include <stdio.h>
#include <stdlib.h>
void max(long x,long* arr);
int main(void)
{
	long number;
	
	while(~scanf("%ld", &number)) // != EOF  or == 1
	{
	    long *arr = malloc((number+1) * sizeof(long));
        max(number,arr);
	    printf("%ld\n", (arr[number]));
	}
	
	return 0;
}
void max(long x,long* arr)
{
    if(arr[x/4]==-1)
        max(x/4,arr);
    if(arr[x/2]==-1)
        max(x/2,arr);
    if(arr[x/3]==-1)
        max(x/3,arr);
    arr[x]=x>arr[x/2]+arr[x/3]+arr[x/4]?x:arr[x/2]+arr[x/3]+arr[x/4];
}