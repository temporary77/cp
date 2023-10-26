#include <bits/stdc++.h>
using namespace std;

struct info {
    int id;
    double gpa;
};

int main() {
    int n;
    scanf("%d",&n);
    info arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d%lf",&arr[i].id,&arr[i].gpa);
    }
    double p;
    bool existence = 0;
    scanf("%lf",&p);
    for (int i = 0; i < n; ++i) {
        if (arr[i].gpa >= p) {
            existence = 1;
            printf("%d\n",arr[i].id);
        }
    }
    if (existence == 0) {
        printf("None");
    }
    return 0;
}
