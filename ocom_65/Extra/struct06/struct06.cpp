#include <bits/stdc++.h>
using namespace std;

struct point {
    long long x, y;
    double dist(const point &b) const {
        return sqrt(pow(x-b.x,2)+pow(y-b.y,2));
    }
};

int main() {
    point m, n;
    scanf("%lld%lld%lld%lld",&m.x,&m.y,&n.x,&n.y);
    printf("%.4lf",m.dist(n));
    return 0;
}
