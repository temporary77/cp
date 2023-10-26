#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, min1 = 10001, max1 = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        if (a > max1)
        {
            max1 = a;
        }
        if (a < min1)
        {
            min1 = a;
        }
    }
    bool prime[max1 + 1] = {};
    for (int i = 2; i <= max1; ++i)
    {
        if (int(prime[i]) == 0)
        {
            if (i >= min1 && i <= max1)
            {
                printf("%d ", i);
            }
            for (int j = i * i; j <= max1; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    return 0;
}