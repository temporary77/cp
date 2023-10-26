#include <bits/stdc++.h>
using namespace std;

void yes(int c) {
    scanf(" %c",&c);
    if (toupper(c) == 'Y' || toupper(c) == 'N') {
        printf("yes");
        return;
    }
    printf("no");
    return ;
}

int main() {
    int c;
    yes(c);
    return 0;
}
