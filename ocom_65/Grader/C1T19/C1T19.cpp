#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 1] = {};
    arr[1] = 0;
    for (int i = 2; i <= n; ++i) {
        int min1 = n + 1;
        for (int j = 1; j <= i / 2; ++j) {
            if (i % j == 0) {
                if (arr[i - j] < min1) {
                    min1 = arr[i - j];
                }
            }
        }
        arr[i] = min1 + 1;
    }
    printf("%d", arr[n]);
    return 0;
}
