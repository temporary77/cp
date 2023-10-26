#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    scanf("%d%d%d",&n,&a,&b);
    for (int i = 0; i < 2*(a+(n-1)*b); ++i) {
        for (int j = 0; j < n*a; ++j) {
            if (a+(n-1)*b-1-j%a-(j/a)*b <= i && i <= a+(n-1)*b+j%a+(j/a)*b) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
