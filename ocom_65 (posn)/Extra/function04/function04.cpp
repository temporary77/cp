#include <bits/stdc++.h>
using namespace std;

void factor(int a, int b, int c) {
    printf("%.1g %.1g",(-b-sqrt(b*b-4*a*c))/(2*a),(-b+sqrt(b*b-4*a*c))/(2*a));
}

int main() {
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    factor(a,b,c);
    return 0;
}
