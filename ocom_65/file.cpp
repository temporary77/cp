#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int main() {
    FILE *fp; fp = fopen("prime.txt","w");
    bool arr[N+1] = {};
    for (int i = 2; i*i <= sqrt(N); ++i) {
        if (arr[i] == 0) {
            for (int j = i*i; j <= N; j += i) {
                arr[j] = 1;
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (arr[i] == 0) {
            fprintf(fp,"%d\n", i);
        }
    }
    fclose(fp);
    return 0;
}
