#include <bits/stdc++.h>
using namespace std;

void check(char c) {
    if (tolower(c) == 'y' || tolower(c) == 'n') {
        printf("yes");
    } else {
        printf("no");
    }
}

int main() {
    char c;
    scanf("%c",&c);
    check(c);
    return 0;
}
