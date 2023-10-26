#include <bits/stdc++.h>
using namespace std;

int minimum(int a, int b, int c) {
    return min(a,min(b,c));
}

int main() {
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",minimum(a,b,c));
    return 0;
}
