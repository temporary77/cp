#include <bits/stdc++.h>
using namespace std;

struct american {
    double feet, inches;
    american operator + (const american &element) const {
        american sum = {feet+element.feet,inches+element.inches};
        if (sum.inches >= 12) {
            sum.inches -= 12;
            sum.feet++;
        }
        return sum;
    }
};


int main() {
    american a, b;
    scanf("%lf%lf%lf%lf",&a.feet,&a.inches,&b.feet,&b.inches);
    printf("%.0lf %.1lf",(a+b).feet,(a+b).inches);
    return 0;
}
