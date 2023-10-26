#include <bits/stdc++.h>
using namespace std;

const double AN = -1e-16;
const double AP = 1e-16;

int main(){

    double s1, s2, s3, s4, s5, s6;
    scanf("%lf%lf%lf%lf%lf%lf", &s1, &s2, &s3, &s4, &s5, &s6);
    double b1, b2, b3, b4, b5, b6;
    scanf("%lf%lf%lf%lf%lf%lf", &b1, &b2, &b3, &b4, &b5, &b6);

    s1 -= b1; s2 -= b2;
    s3 -= b3; s4 -= b4;
    s5 -= b5; s6 -= b6;

    int Q;
    scanf("%d", &Q);
    while(Q-- > 0){
        double x, l, r, test;
        scanf("%lf%lf%lf", &x, &l, &r);
        bool broken = false;
        double prv = 1e308;
        for(int i = 1; i <= 1000; ++i){
            double fx = s1 * x * x * x * x * x + s2 * x * x * x * x + s3 * x * x * x + s4 * x * x + s5 * x + s6;
            double fpx = 5 * s1 * x * x * x * x + 4 * s2 * x * x * x + 3 * s3 * x * x + 2 * s4 * x + s5;
            if(AN <= fpx && fpx <= AP){
                if(AN <= fx && fx <= AP){
                    break;
                }
                broken = true;
                break;
            }
            test = x - prv;
            if(AN <= test && test <= AP){
                break;
            } else if(i == 1000){
                broken = true;
            }
            prv = x;
            x -= fx / fpx;
        }
        if(broken){
            cout << "Broken\n";
            continue;
        }
        if(l <= x && x <= r){
            cout << "Inside ";
            printf("%.10lf\n", x);
        } else if(x < l && l - x <= AP || x > r && x - r <= AP){
            cout << "Inside ";
            printf("%.10lf\n", x);
        } else {
            cout << "Outside ";
            printf("%.10lf\n", x);
        }
    }

    return 0;
}
