#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, *nptr = &n, sum = 0;
    scanf("%d",nptr);
    if (n <= 0 || n > 100) {
        printf("Error");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",arr+i);
        if (arr[i] < -100 || arr[i] > 100) {
            printf("Error");
            return 0;
        }
        sum += *(arr+i);
    }
    printf("%d",sum);
    return 0;
}
