#include <bits/stdc++.h>
using namespace std;

int main() {
    char arr[1000000];
    scanf("%[^\n]",arr);
    int n = strlen(arr), char1 = 0, num1 = 0, special1 = 0;
    for (int i = 0; i < n; ++i) {
        if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122)) {
            char1++;
        } else if (arr[i] >= 48 && arr[i] <= 57) {
            num1++;
        } else {
            special1++;
        }
    }
    printf("Number of Alphabets in the string is : %d\nNumber of Digits in the string is : %d\nNumber of Special characters in the string is : %d",char1,num1,special1);
    return 0;
}
