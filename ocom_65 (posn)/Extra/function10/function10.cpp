#include <bits/stdc++.h>
using namespace std;

int even(int n) {
    if (n%2 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d",even(n));

    return 0;
}
