#include <bits/stdc++.h>
using namespace std;

int main(){

    int x;
    scanf("%d", &x);
    int cnt = x / 8;
    x %= 8;
    if((x & 3) == 3){
        cnt += 1;
        x ^= 3;
    } else if((x & 6) == 6){
        cnt += 2;
        x ^= 6;
    }
    cnt += (x & 4) / 4 + (x & 2) + (x & 1);
    cout << cnt;

    return 0;
}
