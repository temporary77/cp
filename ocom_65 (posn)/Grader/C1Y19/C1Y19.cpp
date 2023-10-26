#include <bits/stdc++.h>
using namespace std;

long long expo(int x, int y) {
    if (y == 0) {
        return 1;
    }
    return x*expo(x,y-1);
}

int main() {
    int x, y;
    scanf("%d%d",&x,&y);
    printf("%lld",expo(x,y));

    return 0;
}
