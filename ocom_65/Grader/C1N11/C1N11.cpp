#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, max1 = 0, min1 = 101, sum = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&a);
        if (a > max1) {
            max1 = a;
        }
        if (a < min1) {
            min1 = a;
        }
        sum += a;
    }
    printf("%d\n%d\n%.2lf",min1,max1,(double)sum/10);
    return 0;
}
