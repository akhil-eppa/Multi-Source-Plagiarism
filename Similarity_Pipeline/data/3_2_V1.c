#include <stdio.h>
#include <stdlib.h>

long int func(long int n,long int* arr){
    //printf("x=%d s=%d\n",x,s);  
    if(arr[n]){
    }
    else if(n<12){
        arr[n]=n;
    }
    else{
        arr[n]=func(n/2,arr)+func(n/3,arr)+func(n/4,arr);
    }
    return arr[n];
}

int main(void) {
	// your code goes here
	long int number;
	long int *a;
	while(scanf("%ld" ,&number)==1)
	{
	    a=(long int*)calloc(number+1,sizeof(long int));
	    printf("%ld\n",func(number,a));
	}
	
	return 0;
}