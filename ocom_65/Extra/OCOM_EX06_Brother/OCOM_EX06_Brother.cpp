#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0, amount[1000] = {}, max1 = 0, num = -1;
    char name[1000][10], scream[10];
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",scream);
        bool broken = 0;
        for (int j = 0; j < cnt; ++j) {
            if (strcmp(name[j],scream) == 0) {
                amount[j]++;
                if (amount[j] > max1) {
                    max1 = amount[j];
                    num = j;
                } else if (amount[j] == max1) {
                    if (j < num) {
                        num = j;
                    }
                }
                broken = 1;
                break;
            }
        }
        if (broken == 1) {
            continue;
        }
        strcpy(name[cnt],scream);
        amount[cnt]++;
        if (amount[cnt] > max1) {
            max1 = amount[cnt];
            num = cnt;
        }
        cnt++;
    }
    printf("%s",name[num]);
    return 0;
}
