#include <bits/stdc++.h>
using namespace std;

int main() {
    char arr[(long long unsigned)(1e6)];
    scanf(" %s",arr);
    int cnt[26], len = strlen(arr), odd = 0;
    for (int i = 0; i < len; ++i) {
        if (++cnt[arr[i]-'A']%2 == 1) {++odd;} else {--odd;}
    }
    if (len%2 != odd) {printf("NO SOLUTION"); return 0;}
    if (len%2 == 0) {
        /*char palin[len/2];
        int index = 0;*/
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]/2; ++j) {
                printf("%c",i+'A');
                /*palin[index++] = i+'A';*/
            }
        }
        for (int i = 26; i >= 0; --i) {
            for (int j = 0; j < cnt[i]/2; ++j) {
                printf("%c",i+'A');
            }
        }
        /*printf("%s",palin);
        strrev(palin);
        printf("%s",palin);*/
    } else {
        /*char palin[len/2];
        int index = 0;*/
        int culprit;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]%2 == 1) {
                culprit = i;
                continue;
            }
            for (int j = 0; j < cnt[i]/2; ++j) {
                printf("%c",i+'A');
                /*palin[index++] = i+'A';*/
            }
        }
        for (int i = 0; i < cnt[culprit]; ++i) {
            printf("%c",culprit+'A');
        }
        cnt[culprit] = 0;
        for (int i = 26; i >= 0; --i) {
            for (int j = 0; j < cnt[i]/2; ++j) {
                printf("%c",i+'A');
            }
        }
        /*printf("%s%c",palin,culprit+'A');
        strrev(palin);
        printf("%s",palin);*/
    }
    return 0;
}
