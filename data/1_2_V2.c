#include <stdio.h>
#include <stdlib.h>
long int func(long n, long *arr);
int main(void)
{
	long number;
	
	while(~scanf("%ld", &number)) // != EOF  or == 1
	{
	    long *arr = malloc((number+1) * sizeof(long));
	    printf("%ld\n", func(number, arr));
	}
	
	return 0;
}
long int func(long n,long * arr){
    //printf("x=%d s=%d\n",x,s);  
    if(n<12){
        arr[n]=n;
    }
    else if(arr[n]){
        
    }
    else{
        arr[n]=func(n/2,arr)+func(n/3,arr)+func(n/4,arr);
    }
    return arr[n];
}