#include <iostream>

using namespace std;

int main()
{
    int x, y, z, n, cnt = 0;
    long long sum = 0;
    scanf("%d%d%d%d", &x, &y, &z, &n);
    int density = x*y*z, t = (n-1)/(x*y*z)+1;
    for (int i = 0; i < t*y*z; ++i) {
        for (int j = 0; j < x; ++j) {
            if (cnt < n) {
                printf("%d ", cnt);
                sum += cnt;
            } else {
                printf("v ");
            }
            if (j < x - 1)
            {
                if (((i % 2) + (z * (i / (y * z)) % 2) + (((y + 1) % 2) * (i / y) % 2)) % 2 == 0)
                {
                    ++cnt;
                }
                else
                {
                    --cnt;
                }
            }
        }
        printf("\n");
        if ((i % (y * z) == y * z - 1) && (z % 2 == 1))
        {
            ++cnt;
        }
        else if (i % y == y - 1)
        {
            cnt += x * y;
            if (y % 2 == 0)
            {
                cnt += (x - 1) * (((i / y) % 2 * -2) + 1);
            }
        }
        else if (((i / y % 2) + (z * (i / (y * z)) % 2)) % 2 == 0)
        {
            cnt += x;
        }
        else
        {
            cnt -= x;
        }
        if ((i + 1) % (y * z) == 0)
        {
            printf("%lld\n", sum);
            sum = 0;
            if (z % 2 == 1 && y % 2 == 0)
            {
                cnt += (x - 1);
            }
        }
    }
    return 0;
}
