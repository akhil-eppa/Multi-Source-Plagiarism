#include<stdio.h>
void max(long x,long* arr)
{
    if(arr[x/2]==-1)
        max(x/2,arr);
    if(arr[x/4]==-1)
        max(x/4,arr);
    if(arr[x/3]==-1)
        max(x/3,arr);
    arr[x]=x>arr[x/2]+arr[x/3]+arr[x/4]?x:arr[x/2]+arr[x/3]+arr[x/4];
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
    for(long i=0;i<m;i++)
        arr[i]=-1;
    arr[0]=0;
    for(int i=0;i<c;i++)
    {
        max(x[i],arr);
        printf("%ld\n",arr[x[i]]);
    }
    return 0;
}