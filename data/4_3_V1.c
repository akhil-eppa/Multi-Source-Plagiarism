#include <stdio.h>
#include <stdlib.h>

long int max(long num , long a[])
{
    if(num==0||num==1)
    {
        a[num]=num;
        return a[num];
    }
   else if (a[num]!=0)
       return a[num];
       long int m = max(num/2,a)+max(num/3,a)+max(num/4,a);
       a[num] = num>m?num:m;
       return a[num];
}
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