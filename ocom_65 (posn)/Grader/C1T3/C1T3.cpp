#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, result = 0, d = 1;
    scanf("%d", &n);
    while (n > 0)
    {
        result += n % 2 * d;
        n /= 2;
        d *= 10;
    }
    printf("%d", result);
    return 0;
}