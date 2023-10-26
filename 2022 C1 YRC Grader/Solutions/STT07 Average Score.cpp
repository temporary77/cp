#include <bits/stdc++.h>
using namespace std;

int main(){

    double sum = 0;
    double mx = 0;
    double mn = 1e308;
    int n = 0;
    char cmd;
    do {
        double x;
        scanf("%*d%*s%lf", &x);
        sum += x;
        mx = max(mx, x);
        mn = min(mn, x);
        ++n;
        scanf(" %c", &cmd);
    } while(cmd == 'Y' || cmd == 'y');
    printf("%.2lf\n%.2lf\n%.2lf", sum / n, mn, mx);

    return 0;
}
