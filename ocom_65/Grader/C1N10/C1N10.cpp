#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, max1 = 0, max2 = 0, cnt = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d",&a);
        if (a%2 == 0) {
            if (a > max2) {
                max2 = a;
            }
        } else {
            if (a > max1) {
                max1 = a;
            }
            cnt++;
        }
    }
    printf("%d\n%d\n%d\n%d",cnt,10-cnt,max1,max2);
    return 0;
}
