#include <bits/stdc++.h>
using namespace std;
void permutation(int n, int arr[], int arrsize)
{
    if (n == 1)
    {
        for (int i = 0; i < arrsize; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        int sndr[arrsize] = {}, k = 0;
        for (int j = 0; j < arrsize - n; ++j)
        {
            sndr[j] = arr[j];
        }
        sndr[arrsize - n] = arr[i + arrsize - n];
        for (int j = arrsize - n; j < arrsize - 1; ++j)
        {
            if (arr[j] == sndr[arrsize - n])
            {
                k = 1;
            }
            sndr[j + 1] = arr[j + k];
        }
        permutation(n - 1, sndr, sizeof(sndr) / 4);
    }

    return;
}

int main()
{
    int n;
    long long fac = 1;
    scanf("%d", &n);
    int perm[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &perm[i]);
    }
    permutation(n, perm, sizeof(perm) / 4);
    for (int i = 2; i <= n; ++i)
    {
        fac *= i;
    }
    printf("%lld", fac);
    return 0;
}
