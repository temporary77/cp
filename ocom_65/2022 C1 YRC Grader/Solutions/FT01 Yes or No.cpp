#include <bits/stdc++.h>
using namespace std;

bool isYorN(char c){
    c = toupper(c);
    return c == 'Y' || c == 'N';
}

int main(){

    char c;
    scanf(" %c", &c);
    if(isYorN(c)){
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}
