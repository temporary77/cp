#include <bits/stdc++.h>
using namespace std;

int main() {
    char n[2000] = {};
    scanf("%s",n);
    int len = strlen(n);
    for (int i = 0; i < len; ++i) {
        if (i%2 == 0) {
            printf("%c",toupper(n[i]));
        } else {
            printf("%c",tolower(n[i]));
        }
    }

    return 0;
}
