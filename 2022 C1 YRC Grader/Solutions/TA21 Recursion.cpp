#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main(){

    int n, st;
    scanf("%d%d", &n, &st);
    if(n == 1){
        cout << (lli)st * st + 1;
    } else {
        cout << (lli)n * n + (lli)(n - 1) * (n - 1);
    }

    return 0;
}
