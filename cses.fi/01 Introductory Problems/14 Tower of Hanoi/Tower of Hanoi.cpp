#include <bits/stdc++.h>
using namespace std;

void recursion(int n, int a, int b) {
    if (n == 1) {
        printf("%d %d\n",a,b);
        return;
    }
    recursion(n-1,a,6-a-b);
    recursion(1,a,b);
    recursion(n-1,6-a-b,b);
    return;
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d\n",int(pow(2,n))-1);
    recursion(n,1,3);
    return 0;
}
