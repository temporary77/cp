#include <bits/stdc++.h>
using namespace std;

int main(){

    int x;
    scanf("%d", &x);
    if(x < 0){
        cout << "Error";
        return 0;
    }
    if(x >= 1000){
        cout << "100";
    } else {
        cout << '0';
    }

    return 0;
}
