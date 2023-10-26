#include <bits/stdc++.h>
using namespace std;

int main() {
    long double z, y, d, p, l;
    scanf("%Lf%Lf%Lf%Lf%Lf",&z,&y,&d,&p,&l);
    z += p*l*l/16;
    if (d == 0) {
        printf("%.10Lf",d);
        return 0;
    }
    if (z > y) {
        printf("%.10Lf",d/(z-y));
    } else {
        printf("Impossible");
    }
    return 0;
}
