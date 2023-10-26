#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    if (n == 3 || n == 2) {
        printf("NO SOLUTION");
        return 0;
    }
    for (int i = 2; i != n+2-(n+1)%2; i += 2) {
        if (i > n) {i = 1;}
        printf("%d ",i);
    }
    return 0;
}
