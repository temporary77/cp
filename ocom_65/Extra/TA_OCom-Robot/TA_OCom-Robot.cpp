#include <bits/stdc++.h>
using namespace std;

// assigned values to each space (normal conditioning)
// could just be done by instantly creating a 1024x1024 matrix with a variable assigning its contents
// or generating power 2 prototypes from that 1024x1024 matrix and working our way up
// or generating a base 4 number or base 2 number from i's and j's (similar to the current method) but would be interesting nonetheless

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < exp2(n); ++i) {
        for (int j = 0; j < exp2(n); ++j) {
            int k = 1;
            for (int m = 2; m <= exp2(n); m *= 2) {
                int det = (i%m)/(m/2)*2+(j%m)/(m/2);
                if (det == 0) {
                    k += m*m/4;
                } else if (det == 2) {
                    k += 2*m*m/4;
                } else if (det == 3) {
                    k += 3*m*m/4;
                }
            }
            printf("%d ",k);
        }
        printf("\n");
    }
    return 0;
}
