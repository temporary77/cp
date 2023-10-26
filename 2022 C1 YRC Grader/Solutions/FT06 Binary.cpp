#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

void recur(lli x){
    if(x < 2){
        cout << x;
        return;
    }
    recur(x / 2);
    cout << x % 2;
}

int main(){

    lli x;
    scanf("%lld", &x);
    if(x < 0){
        cout << "error";
        return 0;
    }
    recur(x);

    return 0;
}
