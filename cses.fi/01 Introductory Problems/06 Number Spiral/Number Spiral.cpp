#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a = 5;
    long long x, y;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld",&x,&y);
        int c = x%2;
        if (x < y) {c = (y+1)%2;swap(x,y);}
        printf("%lld\n",x*x-c*(x-1)*2+(c*2-1)*(y-1));
        /*printf("%lld\n",max(x,y)*max(x,y)-max(x,y)+1+(int)((x > y ^ max(x,y)%2)*2-1)*abs(x-y));*/
    }
    return 0;
}
