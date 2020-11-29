#include <stdio.h>
int main()
{
    int t1;
    scanf("%d", &t1);
    while (t1--)
    {
        int i, n, sum = 0, x;
        scanf("%d", &n);
        int t = n;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &x);
            sum += x;
            if (x == 0)
            {
                t--;
            }
        }
        printf("%s\n", ((sum - 100) <= t - 1 && sum >= 100) ? "YES" : "NO");
    }
    return 0;
}