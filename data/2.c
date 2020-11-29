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
	long int n;
	while(scanf("%ld", &n) != EOF){
	    long int* arr=(long int*)malloc(sizeof(long int)*(n+1));
	    printf("%ld\n",func(n,arr));
	}
	return 0;
}