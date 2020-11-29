#include <stdio.h>
#include <stdlib.h>
void max(long int x,long int* arr)
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
	long int num;
	while(scanf("%ld", &num) != EOF){
	    long int* arr=(long int*)malloc(sizeof(long int)*(num+1));
        max(num,arr);
	    printf("%ld\n",arr[num]);
	}
	return 0;
}