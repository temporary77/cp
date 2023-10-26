#include <bits/stdc++.h>
using namespace std;

struct coor {
    int x, y;
    coor(): x(0), y(0) {}
    coor(int x, int y): x(x), y(y) {}
    double dist(const coor &rhs) const {
        double dx = x - rhs.x;
        double dy = y - rhs.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main(){

    coor a, b;
    scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
    printf("%.4lf", a.dist(b));

    return 0;
}
