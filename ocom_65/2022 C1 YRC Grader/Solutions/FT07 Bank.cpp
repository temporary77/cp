#include <bits/stdc++.h>
using namespace std;

int main(){

    double mny;
    int n;
    scanf("%lf%d", &mny, &n);
    for(int i = 1; i <= n; ++i){
        mny *= 1.02;
        printf("%d-%.2lf\n", i, mny);
    }

    return 0;
}
