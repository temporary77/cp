#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (w != 1) {
                if ((i/(w-1)%2 == 0 && i%(w-1) == j) || (i/(w-1)%2 == 1 && i%(w-1) == (w-1)-j)) {
                    printf("%c", 'A'+i%26);
                } else if ((i/(w-1)%2 == 1 && i%(w-1) == j) || (i/(w-1)%2 == 0 && i%(w-1) == (w-1)-j)) {
                    printf("%c", '0'+i%10);
                } else {
                    printf(" ");
                }
            } else {
                printf("%c", 'A'+i%26);
            }
        }
        printf("\n");
    }
    return 0;
}
