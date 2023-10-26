#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int a[n], b, ascr = 0, bscr = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&b);
        if (a[i] > b) {
            ascr += 2;
        } else if (a[i] == b) {
            ascr++;
            bscr++;
        } else {
            bscr += 2;
        }
    }
    if (ascr > bscr) {
        printf("1\n%d %d",ascr,bscr);
    } else if (ascr < bscr) {
        printf("2\n%d %d",bscr,ascr);
    } else {
        printf("D\n%d %d",ascr,bscr);
    }
    return 0;
}
