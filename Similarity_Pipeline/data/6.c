#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 300
int main()
{
    int anum[SIZE], t, num, a, out = 1, r, i, j, k, l, d, n, count[30], prime[SIZE], m;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &n);
        l = 0;
        r = 0;
        out = 1;
        for (j = 0; j < 30; j++)
        {
            count[j] = 0;
            prime[j] = 0;
            anum[j] = -1;
        }
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a);
            d = sqrt(a);
            for (k = 2; k <= (d + 1); k++)
            {
                if (a % k == 0)
                {
                    for (m = 0; m < r; m++)
                    {
                        if (prime[m] == k)
                        {
                            l = anum[m];
                            break;
                        }
                    }
                    if (m == r)
                    {
                        prime[r] = k;
                        anum[r] = r;
                        l = r;
                        r++;
                    }
                    while (a % k == 0)
                    {
                        count[l] = count[l] + 1;
                        a = a / k;
                    }
                }
            }
            if (a > 1)
            {
                for (m = 0; m < r; m++)
                {
                    if (prime[m] == a)
                    {
                        l = anum[m];

                        break;
                    }
                }
                if (m == r)
                {
                    prime[r] = a;
                    anum[r] = r;
                    l = r;
                    r++;
                }

                count[l]++;
            }
        }

        for (j = 0; j < r; j++)
        {

            count[j] = count[j] + 1;
            out = out * count[j];
        }
        printf("%d\n", out);
    }
    return 0;
}