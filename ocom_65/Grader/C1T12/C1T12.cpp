#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, det, max1 = 0;
    scanf("%d%d", &n, &k);
    int x[n], y[n], result[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < pow(2, n); ++i)
    {
        det = i;
        bool broken = 0;
        int xsum = 0, ysum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (det % 2 == 1)
            {
                xsum += x[j];
                ysum += y[j];
                if (ysum > k)
                {
                    broken = 1;
                    break;
                }
            }
            det /= 2;
        }
        if (broken == 1)
        {
            continue;
        }
        if (xsum > max1)
        {
            max1 = xsum;
        }
    }
    printf("%d", max1);
    return 0;
}