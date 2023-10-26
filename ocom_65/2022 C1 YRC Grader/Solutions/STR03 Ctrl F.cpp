#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

char str[N + 5];

int main(){

    scanf(" %[^\n]", str + 1);
    int len = strlen(str + 1);
    int cntA = 0, cntD = 0, cntO = 0;
    for(int i = 1; i <= len; ++i){
        char c = str[i];
        if('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z'){
            ++cntA;
        } else if('0' <= c && c <= '9'){
            ++cntD;
        } else {
            ++cntO;
        }
    }
    cout << "Number of Alphabets in the string is : " << cntA << '\n';
    cout << "Number of Digits in the string is : " << cntD << '\n';
    cout << "Number of Special characters in the string is : " << cntO;

    return 0;
}
