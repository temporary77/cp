#include <bits/stdc++.h>
using namespace std;

void prime(int n) {
    bool arr[n+1];
    for (int i = 2; i*i <= n; ++i) {
        if (arr[i] == 0) {
            for (int j = i*i; j <= n; j += i) {
                arr[j] = 1;
            }
        }
    }
    if (arr[n] == 1) {
        printf("no");
    } else {
        printf("yes");
    }
    return;
}

int main() {
    int n;
    scanf("%d",&n);
    prime(n);

    return 0;
}
