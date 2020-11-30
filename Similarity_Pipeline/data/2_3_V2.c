#include <stdio.h>
#include <stdlib.h>
long int max(long int n , long int a[]);
int main(void) {
	// your code goes here
	long int num;
	while(scanf("%ld", &num) != EOF){
	    long int* arr=(long int*)malloc(sizeof(long int)*(num+1));
	    printf("%ld\n",max(num,arr));
	}
	return 0;
}
long int max(long int n , long int a[])
{
    if (a[n]!=0)
    return a[n];
    else if(n==0||n==1)
    {
        a[n]=n;
        return a[n];
    }
       long long int m = max(n/2,a)+max(n/3,a)+max(n/4,a);
       a[n] = n>m?n:m;
       return a[n];
}