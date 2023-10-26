#include <bits/stdc++.h>
using namespace std;

void binary(int a) {
    if (a <= 1) {
        printf("%d",a);
        return;
    }
    binary(a/2);
    printf("%d",a%2);
    return;
}

int main() {
    int n;
    scanf("%d",&n);
    if (n < 0) {
        printf("error");
        return 0;
    }
    binary(n);
    return 0;
}
