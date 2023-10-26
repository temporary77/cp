#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int mnDist = min(min(i, n - i + 1), min(j, n - j + 1));
            if(mnDist % 2 == 0){
                cout << '-';
            } else {
                cout << '*';
            }
        }
        cout << '\n';
    }

    return 0;
}
