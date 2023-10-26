#include <bits/stdc++.h>
using namespace std;

const double AN = -1e-16;
const double AP = 1e-16;

int main(){

    double velZ, velY, dif, eff, len;
    scanf("%lf%lf%lf%lf%lf", &velZ, &velY, &dif, &eff, &len);
    if(AN <= dif && dif <= AP){
        cout << "0.0000000000";
        return 0;
    }
    velZ += eff * len * len / 16;
    double test = velZ - velY;
    if(AN <= test && test <= AP){
        cout << "Impossible";
        return 0;
    }
    double tme = dif / test;
    if(tme < 0){
        cout << "Impossible";
    } else {
        printf("%.10lf", tme);
    }

    return 0;
}
