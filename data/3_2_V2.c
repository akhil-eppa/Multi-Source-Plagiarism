#include <stdio.h>
#include <stdlib.h>
long int func(long int n,long int* arr);
int main(void) {
	// your code goes here
	long int n;
	long int *a;
	while(scanf("%ld" ,&n)==1)
	{
	    a=(long int*)calloc(n+1,sizeof(long int));
	    printf("%ld\n",func(n,a));
	}
	
	return 0;
}
long int func(long int n,long int* arr){
    //printf("x=%d s=%d\n",x,s);  
    if(n<12){
        arr[n]=n;
    }
    else if(!n){
    }
    else{
        arr[n]=func(n/2,arr)+func(n/3,arr)+func(n/4,arr);
    }
    return arr[n];
}
