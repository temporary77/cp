#include <bits/stdc++.h>
using namespace std;

int main(){

    int x;
    scanf("%d", &x);
    if(x == 1){
        cout << "no";
        return 0;
    }
    int sq = sqrt(x);
    for(int i = 2; i <= sq; ++i){
        if(x % i == 0){
            cout << "no";
            return 0;
        }
    }
    cout << "yes";

    return 0;
}
