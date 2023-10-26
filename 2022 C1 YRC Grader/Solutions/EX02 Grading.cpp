#include <bits/stdc++.h>
using namespace std;

int main(){

    int x;
    scanf("%d", &x);
    if(x < 0 || x > 100){
        cout << "Error";
        return 0;
    }
    if(x >= 80){
        cout << 'A';
    } else if(x >= 70){
        cout << 'B';
    } else if(x >= 60){
        cout << 'C';
    } else if(x >= 50){
        cout << 'D';
    } else {
        cout << 'F';
    }

    return 0;
}
