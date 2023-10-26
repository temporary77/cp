#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, *nptr = &n;
    scanf("%d",nptr);
    if (*nptr <= 0 || *nptr > 100) {
        printf("Error");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",arr+i);
        if (*(arr+i) < -100 || *(arr+i) > 100) {
            printf("Error");
            return 0;
        }
    }
    int a, *aptr = &a;
    scanf("%d",aptr);
    if (*aptr < -100 || *aptr > 100) {
        printf("Error");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (*(arr+i) == *aptr) {
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}
