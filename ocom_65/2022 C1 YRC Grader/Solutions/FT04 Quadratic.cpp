#include <bits/stdc++.h>
using namespace std;

bool isZero(double x){
    return -1e-16 <= x && x <= 1e-16;
}

void printAns(const double &x){
    if(isZero(x - trunc(x))){
        printf("%.0lf", x);
    } else {
        printf("%.1lf", x);
    }
}

int main(){

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    double sq = sqrt(b * b - 4 * a * c);
    double x1 = (-b - sq) / 2 / a;
    double x2 = (-b + sq) / 2 / a;
    printAns(x1);
    cout << ' ';
    printAns(x2);

    return 0;
}
