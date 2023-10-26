#include <bits/stdc++.h>
using namespace std;

struct info {
    char class1[10], name[100];
    int num;
    double gpa;
};

int main() {
    char c = 'Y';
    int max1 = -1e6, min1 = 1e6, m, n;
    double avggpa = 0;
    info arr[10000];
    for (int i = 1;; ++i) {
        scanf(" %[^\n]%d %[^\n]%lf",arr[i].class1,&arr[i].num,arr[i].name,&arr[i].gpa);
        avggpa += arr[i].gpa;
        if (arr[i].gpa < min1) {
            min1 = arr[i].gpa;
            n = i;
        }
        if (arr[i].gpa > max1) {
            max1 = arr[i].gpa;
            m = i;
        }
        scanf(" %c",&c);
        if (toupper(c) != 'Y') {
            avggpa /= i;
            break;
        }
    }
    printf("%.2lf\nMAX : Name : %s Classroom : %s Number : %d GPA : %.2lf\nMIN : Name : %s Classroom : %s Number : %d GPA : %.2lf",avggpa,arr[m].name,arr[m].class1,arr[m].num,arr[m].gpa,arr[n].name,arr[n].class1,arr[n].num,arr[n].gpa);
    return 0;
}
