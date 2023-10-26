#include <bits/stdc++.h>
using namespace std;

void backruptcy(int a, int n) {
    double money = a;
    for (int i = 0; i < n; ++i) {
        money *= 102/(double)100;
        printf("%d-%.2lf\n",i+1,money);
    }
}

int main() {
    int a, n;
    scanf("%d%d",&a,&n);
    backruptcy(a,n);
    return 0;
}
