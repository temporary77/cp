#include <bits/stdc++.h>
using namespace std;

// 11 5 2 4 1 6 11 8 10 7 9 3

int main() {
    int n, a;
    scanf("%d",&n);
    int adjacent[n+1], slot[n+1], bystander[n+1], median = n/2+1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a);
        slot[i] = a;
    }
    for (int i = 1; i <= n; ++i) {
        adjacent[slot[i]] = slot[i%n+1];
        bystander[slot[i%n+1]] = slot[i];
    }
    for (int i = 0; i < n/2; ++i) {
        if (adjacent[median] < median) {
            adjacent[bystander[median]] = adjacent[adjacent[median]];
            bystander[adjacent[adjacent[median]]] = bystander[median];
            adjacent[adjacent[median]] = 0;
            adjacent[median] = 0;
            for (;;) {
                if (adjacent[++median] != 0) {
                    break;
                }
            }
        } else {
            adjacent[bystander[median]] = adjacent[adjacent[median]];
            bystander[adjacent[adjacent[median]]] = bystander[median];
            adjacent[adjacent[median]] = 0;
            adjacent[median] = 0;
            for (;;) {
                if (adjacent[--median] != 0) {
                    break;
                }
            }
        }
    }
    /*for (int i = 0; i < n/2; ++i) {
        for (int j = 1;; ++j) {
            if (slot[(loc[median]+j-1)%n+1] > 0) {

                if (slot[(loc[median]+j-1)%n+1] < median) {
                    loc[slot[(loc[median]+j-1)%n+1]] = 0;
                    slot[loc[median]] = 0;
                    slot[(loc[median]+j-1)%n+1] = 0;
                    loc[median] = 0;
                    for (;;) {
                        if (loc[++median] != 0) {
                            break;
                        }
                    }
                } else {
                    loc[slot[(loc[median]+j-1)%n+1]] = 0;
                    slot[loc[median]] = 0;
                    slot[(loc[median]+j-1)%n+1] = 0;
                    loc[median] = 0;
                    for (;;) {
                        if (loc[--median] != 0) {
                            break;
                        }
                    }
                }

                for (int i = 1; i <= n; ++i) {
                    printf("%d|",loc[i]);
                }
                printf("\n");
                for (int i = 1; i <= n; ++i) {
                    printf("%d|",slot[i]);
                }
                printf("\n%d\n",median);
                break;
            }
        }
    }*/
    /*for (int i = 0; i < n/2; ++i) {
        int cnt = 0, trgt = n/2-i;
        for (int j = 1; j <= n; ++j) {
            if (loc[j] != 0) {
                if (cnt == trgt) {
                    loc[slot[(loc[j]+space[loc[j]])%n+1]] = 0;
                    slot[(loc[j]+space[loc[j]])%n+1] = 0;
                    space[(loc[j])%n < 1 ? n : (loc[j])%n] += 1;
                    space[(loc[j]-1) < 1 ? n : loc[j]-1] += 1+space[loc[j]];
                    for (int k = loc[j];; ++k) {
                        if (slot[k%n+1] != 0) {
                            loc[slot[k%n+1]] = 0;
                            slot[k%n+1] = 0;
                            break;
                        }
                    }
                    slot[loc[j]] = 0;
                    loc[j] = 0;
                    printf("%d\n",j);
                    for (int i = 1; i <= n; ++i) {
                        printf("%d|",slot[i]);
                    }
                    printf("slot\n");
                    for (int i = 1; i <= n; ++i) {
                        printf("%d|",loc[i]);
                    }
                    printf("loc\n");
                    for (int i = 1; i <= n; ++i) {
                        printf("%d|",space[i]);
                    }
                    printf("space\n");
                    break;
                }
                ++cnt;
            }
        }
    }*/
    printf("%d",median);

    return 0;
}
