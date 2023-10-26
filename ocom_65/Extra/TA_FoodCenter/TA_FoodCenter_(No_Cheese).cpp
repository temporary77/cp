#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, result = 1000;
    scanf("%d", &n);
    for (int i = 0; i <= n / 8; ++i)
    {
        int sndr = n, cnt = 0;
        sndr -= i * 8;
        cnt += i;
        for (int j = 0; j <= sndr / 4; ++j)
        {
            int sndr2 = sndr, cnt2 = cnt;
            sndr2 -= j * 4;
            cnt2 += j;
            for (int k = 0; k <= sndr2 / 3; ++k)
            {
                int sndr3 = sndr2, cnt3 = cnt2;
                sndr3 -= k * 3;
                cnt3 += k;
                cnt3 += sndr3;
                if (cnt3 < result)
                {
                    result = cnt3;
                }
            }
        }
    }
    printf("%d", result);
    return 0;
}