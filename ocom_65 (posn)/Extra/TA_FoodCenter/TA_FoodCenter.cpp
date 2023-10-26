#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", n / 8 + n % 8 / 4 + n % 4 / 3 + n % 4 % 3 - (n + 1) % 8 / 7);
    return 0;
}