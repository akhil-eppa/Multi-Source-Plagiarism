#include <stdio.h>
#include <stdlib.h>
long int max(long n , long a[]);
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
    int i=0;
    while (i<m)
    {
        arr[i]=-1;
        i++;
    }
    arr[0]=0;
    for(int i=0;i<c;i++)
    {
        long int ans=max(x[i],arr);
        printf("%ld\n",ans);
    }
    return 0;
}
long int max(long n , long a[])
{
    if(n==0||n==1)
    {
        a[n]=n;
        return a[n];
    }
   else if (a[n]!=0)
       return a[n];
       long int m = max(n/2,a)+max(n/3,a)+max(n/4,a);
       a[n] = n>m?n:m;
       return a[n];
}