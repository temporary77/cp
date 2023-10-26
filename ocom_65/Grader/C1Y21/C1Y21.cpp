#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, *aptr = &a, *bptr = &b;
    scanf("%d%d",aptr,bptr);
    if (*aptr <= -100 || *aptr > 100 || *bptr <= -100 || *bptr > 100) {
        printf("Error");
        return 0;
    }
    int *temp = aptr;
    aptr = bptr;
    bptr = temp;
    printf("%d %d",*aptr,*bptr);
    return 0;
}
