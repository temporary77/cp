#include <bits/stdc++.h>
using namespace std;

const int L = 1e6;

char str[L + 5];

int main(){

    scanf("%s", str + 1);
    int len = strlen(str + 1);
    bool isPalin = true;
    for(int i = 1; i <= (len - len % 2) / 2; ++i){
        if(str[i] != str[len - i + 1]){
            isPalin = false;
            break;
        }
    }
    if(isPalin){
        printf("%s is a palindrome", str + 1);
    } else {
        printf("%s is not a palindrome", str + 1);
    }

    return 0;
}
