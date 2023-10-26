#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, min = 10001, max = 0, m, d;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        if (a > max)
        {
            max = a;
        }
        if (a < min)
        {
            min = a;
        }
    }
    int range = max - min;
    scanf("%d%d", &m, &d);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &a);
        if (a >= range - d && a <= range + d)
        {
            printf("/%d\\\n", a);
        }
    }
    printf("%d %d", d, range);
    return 0;
}