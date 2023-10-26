#include <bits/stdc++.h>
using namespace std;

struct length {
    double feet, inches;
    length(): feet(0), inches(0) {}
    length(double f, double i): feet(f), inches(i) {}
    void add(const length &rhs){
        feet += rhs.feet;
        inches += rhs.inches;
        if(inches > 12){
            feet += floor(inches / 12);
            inches = fmod(inches, 12);
        }
    }
};

int main(){

    length a, b;
    scanf("%lf%lf%lf%lf", &a.feet, &a.inches, &b.feet, &b.inches);
    a.add(b);
    printf("%.0lf %.1lf", a.feet, a.inches);

    return 0;
}
