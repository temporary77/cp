#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[10], sum = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d",arr+i);
        if (*(arr+i)%2 == 0) {
            sum += *(arr+i);
        }
    }
    printf("%d",sum);
    return 0;
}
