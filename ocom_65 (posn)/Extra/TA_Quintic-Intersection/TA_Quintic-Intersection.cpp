#include <bits/stdc++.h>
using namespace std;

bool iszero(long double a, long double b) {
    return a - b >= -1e-16 && a - b <= 1e-16;
}

int main() {
    int s1,s2,s3,s4,s5,s6,b1,b2,b3,b4,b5,b6,q,l,r;
    scanf("%d%d%d%d%d%d\n%d%d%d%d%d%d\n%d",&s1,&s2,&s3,&s4,&s5,&s6,&b1,&b2,&b3,&b4,&b5,&b6,&q);
    s1 -= b1;
    s2 -= b2;
    s3 -= b3;
    s4 -= b4;
    s5 -= b5;
    s6 -= b6;
    for (int i = 0; i < q; ++i) {
        long double x, old = 1e320, num, denom;
        scanf("%Lf%d%d",&x,&l,&r);
        bool broken = 0;
        for (int j = 0; j < 1000; ++j) {
            num = s1*x*x*x*x*x+s2*x*x*x*x+s3*x*x*x+s4*x*x+s5*x+s6;
            denom = s1*5*x*x*x*x+s2*4*x*x*x+s3*3*x*x+s4*2*x+s5;
            if (iszero(denom,0)) {
                if (num == 0) {
                    if (x >= l && x <= r) {
                        printf("Inside %.10Lf\n",x);
                    } else if (x < l && l-x <= 1e-16 || x > r && x-r <= 1e-16) {
                        printf("Inside %.10Lf\n",x);
                    } else {
                        printf("Outside %.10Lf\n",x);
                    }
                    break;
                }
                broken = 1;
            }
            if (broken == 1) {
                printf("Broken\n");
                break;
            }
            if (iszero(x,old)) {
                if (x >= l && x <= r) {
                    printf("Inside %.10Lf\n",x);
                } else if (x < l && l-x <= 1e-16 || x > r && x-r <= 1e-16) {
                    printf("Inside %.10Lf\n",x);
                } else {
                    printf("Outside %.10Lf\n",x);
                }
                break;
            }
            old = x;
            x -= num/denom;
            if (j == 999) {
                printf("Broken\n");
                break;
            }
        }
    }
    return 0;
}
