#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long h, l, a, num = 0, current = -1, amount = 0;
    int n, max1 = 0;
    scanf("%lld%lld%d", &h, &l, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a);
        if (a - l < 0 || a - l > h)
        {
            continue;
        }
        if (a != current)
        {
            if (amount > max1)
            {
                max1 = amount;
                num = current;
            }
            amount = 0;
        }
        current = a;
        amount++;
    }
    printf("%d %lld", max1, num);

    return 0;
}