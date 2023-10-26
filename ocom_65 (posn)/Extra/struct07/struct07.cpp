#include <bits/stdc++.h>
using namespace std;

struct info {
    int num;
    char name[1000];
    double gpa;
};

int main() {
    info arr[1000];
    double max1 = -1, min1 = 5, avg = 0;
    char c = 'Y';
    for (int i = 1;;++i) {
        scanf("%d %[^1234567890]%lf",&arr[i].num,&arr[i].name,&arr[i].gpa);
        if (arr[i].gpa > max1) {
            max1 = arr[i].gpa;
        }
        if (arr[i].gpa < min1) {
            min1 = arr[i].gpa;
        }
        avg += arr[i].gpa;
        scanf(" %c",&c);
        if (toupper(c) != 'Y') {
            avg /= i;
            break;
        }
    }
    printf("%.2lf\n%.2lf\n%.2lf",avg,min1,max1);
    return 0;
}
