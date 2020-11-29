#include <stdio.h>
#include <stdlib.h>
long int func(long n,long * arr);
int main()
{
    long n,m=0;
    long x[10];
    int c=0;
    while(scanf("%ld",&n)>0)
    {
        x[c]=n;
        c++;
        if(m<n)
            m=n;
    }
    long arr[m];
    for(long i=0;i<m;i++)
        arr[i]=-1;
    arr[0]=0;
    int i=0;
    while (i<c)
    {
        long int ans=func(x[i],arr);
        printf("%ld\n",arr[x[i]]);
        i++;
    }
    return 0;
}

long int func(long n,long * arr){
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