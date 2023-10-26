#include <bits/stdc++.h>
using namespace std;

const double pi = 3.14;

void radius(int r) {
    printf("%.2lf %.2lf",pi*r*r,4*pi*r*r);
}

int main() {
    int r;
    scanf("%d",&r);
    radius(r);
    return 0;
}
