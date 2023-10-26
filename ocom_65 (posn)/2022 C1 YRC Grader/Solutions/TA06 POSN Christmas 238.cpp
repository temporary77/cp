#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int x = a + b * (n - 1);
    for(int i = 1; i <= x; ++i){
        int sum = a + b * (n - 1) + 1;
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= a; ++k){
                if(i + k >= sum){
                    cout << '*';
                } else {
                    cout << ' ';
                }
            }
            sum -= b;
        }
        cout << '\n';
    }
    for(int i = 1; i <= x; ++i){
        int dif = 0;
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= a; ++k){
                if(i - k <= dif){
                    cout << '*';
                } else {
                    cout << ' ';
                }
            }
            dif += b;
        }
        cout << '\n';
    }


    return 0;
}
